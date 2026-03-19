#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <iomanip>
#include <algorithm>

class PmergeMe
{
	private:
		std::vector<int> _numbersVect;
		std::deque<int> _numbersDeque;
		long			_nbrsSize;
		double			_vectTime;
		double			_dequeTime;
		bool	isPosInteger(const std::string str);
		void	sortVector();
		void	sortDeque();
		void	printResult(char* nbrs[]);
		double	getTime(struct timeval start, struct timeval end);
		std::vector<int> generateJacobsthalVector(int n);
		void	fordJohnsonVector(std::vector<int>& numbers);
		std::deque<int> generateJacobsthalDeque(int n);
		void	fordJohnsonDeque(std::deque<int>& numbers);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		void	sortNumbers(char* nbrs[]);

		class	InvalidArgumentException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif
