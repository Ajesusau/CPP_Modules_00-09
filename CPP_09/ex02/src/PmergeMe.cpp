#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	std::cout << "PmergeMe default constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other) {
	std::cout << "PmergeMe copy constructor called" << std::endl;
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	std::cout << "PmergeMe copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_numbersVect = other._numbersVect;
		this->_numbersDeque = other._numbersDeque;
		this->_nbrsSize = other._nbrsSize;
		this->_vectTime = other._vectTime;
		this->_dequeTime = other._vectTime;
	}
	return *this;
}

PmergeMe::~PmergeMe() {
	std::cout << "PmergeMe destructor called" << std::endl;
}

void	PmergeMe::sortNumbers(char* nbrs[]) {
	int	i = 1;

	while (nbrs[i]) {
		if(isPosInteger(nbrs[i])) {
			_numbersVect.push_back(std::atoi(nbrs[i]));
			_numbersDeque.push_back(std::atoi(nbrs[i]));
		} else {
			throw InvalidArgumentException();
		}
		i++;
	}
	_nbrsSize = i - 1;
	sortVector();
	sortDeque();
	printResult(nbrs);
}

bool	PmergeMe::isPosInteger(const std::string str) {
	size_t i = 0;
	long   nbr;
	if (!str.empty()) {
		while (str[i]) {
			if (!std::isdigit(str[i]))
				return false;
			i++;
		}
		nbr = atol(str.c_str());
		if (nbr < 0 || nbr > __INT_MAX__)
			return false;
		else
			return true;
	}
	return false;
}
void	PmergeMe::sortVector() {
	struct timeval start;
	struct timeval end;
	gettimeofday(&start, NULL);
	fordJohnsonVector(_numbersVect);
	gettimeofday(&end, NULL);
	_vectTime = getTime(start, end);
}
void	PmergeMe::sortDeque() {
	struct timeval start;
	struct timeval end;
	gettimeofday(&start, NULL);
	fordJohnsonDeque(_numbersDeque);
	gettimeofday(&end, NULL);
	_dequeTime = getTime(start, end);
}

void	PmergeMe::printResult(char* nbrs[]) {
	int i = 1;
	std::cout << "Before:	";
	while (nbrs[i]) {
		std::cout << nbrs[i] << " ";
		i++;
	}
	std::cout << std::endl;

	size_t j = 0;
	std::cout << "After:	";
	while (j < _numbersVect.size()) {
		std::cout << _numbersVect[j] << " ";
		j++;
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of "<< _nbrsSize <<" elements with std::vector : "
		<< std::fixed << std::setprecision(6) << _vectTime <<" s" << std::endl;
	std::cout << "Time to process a range of "<< _nbrsSize <<" elements with std::deque : "
		<< std::fixed << std::setprecision(6) << _dequeTime <<" s" << std::endl;
}

std::vector<int> PmergeMe::generateJacobsthalVector(int n) {
	std::vector<int> jacob;
	if (n <= 0)
		return jacob;
	jacob.push_back(1);
	if (n == 1) 
		return jacob;
	jacob.push_back(3);
	while (jacob.back() < n) {
		int next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
		jacob.push_back(next);
	}
	return jacob;
}

void	PmergeMe::fordJohnsonVector(std::vector<int>& numbers) {
	
	size_t	nbrSize;
	int		straggler;
	bool	hasStraggler = false;
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> mainChain;
	std::vector<int> pendChain;
	size_t lastInserted;
	size_t	endPos;


	if (numbers.size() <= 1)
		return;
	if (numbers.size() % 2 != 0) {
		straggler = numbers.back();
		numbers.pop_back();
		hasStraggler = true;
	}
	nbrSize = numbers.size();
	for (size_t i = 0; i < nbrSize; i += 2) {
		if (numbers[i] < numbers[i + 1])
			pairs.push_back(std::make_pair(numbers[i + 1], numbers[i]));
		else
			pairs.push_back(std::make_pair(numbers[i], numbers[i + 1]));
	}
	for (size_t i = 0; i < pairs.size(); i++) {
		mainChain.push_back(pairs[i].first);
	}
	fordJohnsonVector(mainChain);
	std::vector<bool> usedPairs(pairs.size(), false);
	for (size_t i = 0; i < mainChain.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (!usedPairs[j] && pairs[j].first == mainChain[i]) {
				pendChain.push_back(pairs[j].second);
				usedPairs[j] = true;
				break;
			}
		}
	}
	mainChain.insert(mainChain.begin(), pendChain[0]);
	std::vector<int> jacobSeq = generateJacobsthalVector(pendChain.size());
	lastInserted = 1;
	for (size_t i = 0; i < jacobSeq.size(); i++) {
		if (static_cast<std::size_t>(jacobSeq[i]) < pendChain.size())
			endPos = jacobSeq[i];
		else
			endPos = pendChain.size();
		for (size_t j = endPos; j > lastInserted; j--) {
			std::vector<int>::iterator it = std::upper_bound(mainChain.begin(), mainChain.end(), pendChain[j - 1]);
			mainChain.insert(it, pendChain[j - 1]);
		}
		lastInserted = endPos;
	}
	if (hasStraggler) {
		std::vector<int>::iterator it = std::upper_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(it, straggler);
	}
	numbers = mainChain;
}

std::deque<int> PmergeMe::generateJacobsthalDeque(int n) {
	std::deque<int> jacob;
	if (n <= 0)
		return jacob;
	jacob.push_back(1);
	if (n == 1) 
		return jacob;
	jacob.push_back(3);
	while (jacob.back() < n) {
		int next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
		jacob.push_back(next);
	}
	return jacob;
}

void	PmergeMe::fordJohnsonDeque(std::deque<int>& numbers) {
	
	size_t	nbrSize;
	int		straggler;
	bool	hasStraggler = false;
	std::deque<std::pair<int, int> > pairs;
	std::deque<int> mainChain;
	std::deque<int> pendChain;
	size_t lastInserted;
	size_t	endPos;


	if (numbers.size() <= 1)
		return;
	if (numbers.size() % 2 != 0) {
		straggler = numbers.back();
		numbers.pop_back();
		hasStraggler = true;
	}
	nbrSize = numbers.size();
	for (size_t i = 0; i < nbrSize; i += 2) {
		if (numbers[i] < numbers[i + 1])
			pairs.push_back(std::make_pair(numbers[i + 1], numbers[i]));
		else
			pairs.push_back(std::make_pair(numbers[i], numbers[i + 1]));
	}
	for (size_t i = 0; i < pairs.size(); i++) {
		mainChain.push_back(pairs[i].first);
	}
	fordJohnsonDeque(mainChain);
	std::deque<bool> usedPairs(pairs.size(), false);
	for (size_t i = 0; i < mainChain.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (!usedPairs[j] && pairs[j].first == mainChain[i]) {
				pendChain.push_back(pairs[j].second);
				usedPairs[j] = true;
				break;
			}
		}
	}
	mainChain.insert(mainChain.begin(), pendChain[0]);
	std::deque<int> jacobSeq = generateJacobsthalDeque(pendChain.size());
	lastInserted = 1;
	for (size_t i = 0; i < jacobSeq.size(); i++) {
		if (static_cast<std::size_t>(jacobSeq[i]) < pendChain.size())
			endPos = jacobSeq[i];
		else
			endPos = pendChain.size();
		for (size_t j = endPos; j > lastInserted; j--) {
			std::deque<int>::iterator it = std::upper_bound(mainChain.begin(), mainChain.end(), pendChain[j - 1]);
			mainChain.insert(it, pendChain[j - 1]);
		}
		lastInserted = endPos;
	}
	if (hasStraggler) {
		std::deque<int>::iterator it = std::upper_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(it, straggler);
	}
	numbers = mainChain;
}

double PmergeMe::getTime(struct timeval start, struct timeval end) {
	double segundos = (double)(end.tv_sec - start.tv_sec);
	double microsegundos = (double)(end.tv_usec - start.tv_usec);
	return segundos + (microsegundos / 1000000.0);
}

const char* PmergeMe::InvalidArgumentException::what() const throw() {
	return "Invalid Argument.";
}
