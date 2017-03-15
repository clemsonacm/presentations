#include <type_traits>
#include <iostream>
#include <tuple>

#if __has_include("experimental/tuple")
#include <experimental/tuple>
#define CPP_17
#endif


namespace tuple
{
	template<class Tuple, std::size_t N>
	struct Printer
	{
		static void print(std::ostream& out, const Tuple& t)
		{
			Printer<Tuple, N-1>::print(out, t);
			out << ", " << std::get<N-1>(t);
		}
	};
	template<class Tuple>
	struct Printer<Tuple, 1>
	{
		static void print(std::ostream& out, const Tuple& t)
		{
			out << std::get<0>(t);
		}
	};

	template<class... Args>
	std::ostream& print(std::ostream& out, const std::tuple<Args...>& t)
	{
		out << "{";
		tuple::Printer<decltype(t), sizeof...(Args)>::print(out, t);
		out << "}";
		return out;
	}
}

template<class... Tuple>
std::ostream& operator<<(std::ostream& out, std::tuple<Tuple...> const& tuple)
{
	return tuple::print(out, tuple);
}

std::tuple<int,std::string> convert(int i, int j, std::string const& s)
{
	return std::make_tuple(i+j,s);
}

void print_tuple()
{
	std::cout << "=====print_tuple=====" << std::endl;
	auto t = std::make_tuple<int,int,std::string>(1,2,"asdf");
	std::cout << t << std::endl;
}

void with_cpp14()
{
	std::cout << "=====with_cpp14=====" << std::endl;
	int i = 0;
	std::string s;
	auto t = std::make_tuple<int,int,std::string>(1,2,"asdf");

	std::tie(std::ignore,s) = convert(std::get<0>(t), std::get<1>(t), std::get<2>(t));
	std::cout << i << ", \"" << s << "\"" << std::endl;
}

#ifdef CPP_17
void with_cpp17()
{
	std::cout << "=====with_cpp17=====" << std::endl;
	int i = 0;
	std::string s;
	auto t = std::make_tuple<int,int,std::string>(1,2,"asdf");

	std::tie(i,std::ignore) = std::experimental::apply(convert, t);
	std::cout << i << ", \"" << s << "\"" << std::endl;

}
#endif

int main(int argc, char *argv[])
{

	print_tuple();
	with_cpp14();
#ifdef CPP_17
	with_cpp17();
#endif

	return 0;
}
