#include <iostream>
#include <iomanip>

#ifdef __cpp_fold_expressions
#define CPP_17
#endif
//order matters here
//
//if we put
//T sum(T, Ts...)
//T sum(T) 
//
//this code will not compile


//primary function for overload resolution
template <class T>
T sum (T const& first)
{
	return first;
}

// note the differing number and type of arguments 
// this is overloading not partial specialization
template <class T, class... Ts>
T sum (T const& first, const Ts&... rest)
{
	return first + sum(rest...);
}

template <class T>
bool all (T const& first)
{
	return first;
}

template <class T, class... Ts>
bool all (T const& first, Ts const&... rest)
{
	return first && all(rest...);
}

#ifdef CPP_17
//in c++17
template <class T, class...  Ts>
T sumbfl (T const& first, const Ts&... rest)
{
	return (first + ... + rest);
}

template <class... Ts>
bool allufr (const Ts&... args)
{
	return (args && ...);
}
#endif

int main(int argc, char *argv[])
{
	
	std::cout << sum(1,2,3,4,5,6) << std::endl;
#ifdef CPP_17
	std::cout << sumbfl(1,2,3,4,5,6) << std::endl;
#endif
	std::cout << std::boolalpha;
	std::cout << all(1,0,3,4) << std::endl;
#ifdef CPP_17
	std::cout << allufr(1,0,3,4) << std::endl;
#endif
	return 0;
}
