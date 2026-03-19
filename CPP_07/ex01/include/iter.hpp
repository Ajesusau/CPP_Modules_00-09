#ifndef ITER_HPP
# define ITER_HPP

template <typename T_array, typename T_function>
void	iter(T_array *array, const size_t length, T_function function) {
	size_t i;

	i = 0;
	while (i < length) {
		function(array[i]);
		i++;
	}
}

#endif
