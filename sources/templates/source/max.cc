#include <complex>
#include <iostream>
#include <iomanip>
#include <algorithm>

/*ugly hack*/
namespace std
{
	template <class T>
	bool operator<(std::complex<T> const& lhs, std::complex<T> const& rhs)
	{
		return lhs.real() < rhs.real();
	}
}

/* types must be equal */
namespace simple 
{

	template <class T>
	inline T const& max (T const& lhs, T const& rhs)
	{
		return lhs<rhs?rhs:lhs;
	}
}

/* types can differ but return type is the first */
namespace argsWrong
{
	/* dangeling reference */
	template <class U, class V>
	inline U const& max (U const& lhs, V const& rhs)
	{
		return lhs<rhs?rhs:lhs;
	}
}

namespace args
{
	template <class U, class V>
	inline U max (U const& lhs, V const& rhs)
	{
		return lhs<rhs?rhs:lhs;
	}
}

namespace rt
{
	template <class U, class V, class RT>
	inline RT const& max(U const& lhs, V const& rhs)
	{
		return lhs<rhs?rhs:lhs;
	}
}

/* all of the () are required */
#define maxMacro(x,y) (((x)<(y))?(y):(x))


void operators()
{
	std::cout << "====operators====" << std::endl;
	std::complex<float> c1{1,3}, c2{2,1};
	std::cout << std::boolalpha;

	std::cout << (c1<c2) << std::endl;
	std::cout << simple::max(c1,c2) << std::endl;
	std::cout << args::max(c1,c2) << std::endl;
	std::cout << std::max(c1,c2) << std::endl;
	std::cout << maxMacro(c1,c2) << std::endl;
}

void percision()
{
	std::cout << "====precision====" << std::endl;
	int x = 2;
	double y = 3.1;

	/*won't compile*/
	/*std::cout << std::max(x,y) << std::endl;*/
	std::cout << std::max<double>(x,y) << std::endl;
	std::cout << std::max<int>(x,y) << std::endl;

	/*won't compile*/
	/*std::cout << simple::max<double>(x,y) << std::endl;*/
	std::cout << simple::max<double>(x,y) << std::endl;

	/*bad! dangling refernece*/
	/*std::cout << argsWrong::max(x,y) << std::endl;*/

	std::cout << args::max(x,y) << std::endl;
}

void promotion()
{
	std::cout << "====promotion====" << std::endl;
	int x = 2;
	double y = 3.1;
	std::cout << maxMacro(x,y) << std::endl;
	std::cout << maxMacro(y,x) << std::endl;
}



int main(int argc, char *argv[])
{

	operators();
	percision();
	promotion();

	return 0;
}
