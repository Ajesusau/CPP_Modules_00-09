#ifndef ESAYFIND_HPP
# define ESAYFIND_HPP

#include<algorithm>
#include<exception>

class NotFoundExeption : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Number not found");
		}
	
};

template <typename T>
typename T::iterator	easyfind(T& container, int n) {
	typename T::iterator result;
	
	result = std::find(container.begin(), container.end(), n);
	if (result == container.end())
		throw NotFoundExeption();
	return result;
}

#endif
