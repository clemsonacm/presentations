#include <iostream>

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

int main(int argc, char *argv[])
{
	
	std::cout << sum(1,2,3,4,5,6) << std::endl;
	return 0;
}
