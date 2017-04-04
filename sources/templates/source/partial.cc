#include <iostream>

template<class U, class V>
struct print
{
	static void call(U const&, V const&)
	{
		std::cout << "first" << std::endl;
	}
};

template<class U>
struct print<U,U>
{
	static void call(U const&, U const&)
	{
		std::cout << "second" << std::endl;
	}
};

template<>
struct print<double,double>
{
	static void call(double const&, double const&)
	{
		std::cout << "third" << std::endl;
	}
};

//{{{ main
int main(int argc, char *argv[])
{
	print<int,double>::call(1,2);
	print<int,int>::call(1,2);
	print<double,double>::call(1,2);
	return 0;
}
//}}}

// vim: foldmethod=marker
