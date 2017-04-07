#include <vector>
#include <map>
#include <list>
#include <iostream>
#include <iomanip>
#include <utility>
#include <type_traits>


//{{{ sfinae
//solution based on macro-free version in http://stackoverflow.com/a/9154394
namespace detail {
	template<class>
	struct sfinae_true: std::true_type{};
}

//note that methods:
//
//1. are `static`
//2. have different signatures
//3. use decltype and std::declval
//
#define HAS_METHOD_NAME(name) \
namespace detail { \
	template<class T> \
	static auto test_##name(int) -> sfinae_true<decltype(std::declval<T>().name())>; \
	template<class T> \
	static auto test_##name(long) -> std::false_type; \
} \
template<class T> \
struct has_##name : decltype(detail::test_##name<T>(0)){}

//don't forget to instantiate the macros
HAS_METHOD_NAME(begin);
HAS_METHOD_NAME(end);

template <class Container>
struct is_iterable
{
	static constexpr bool value = std::is_class<Container>::value \
								  && has_begin<Container>::value  \
								  && has_end<Container>::value;
};
//}}}
//{{{ test_reflection()
void test_reflection()
{
	std::cout << "=====test_component=====" << std::endl;
	std::cout << std::boolalpha;

	std::cout << has_begin<int>::value << std::endl;
	std::cout << has_end<int>::value << std::endl;
	std::cout << std::is_class<int>::value << std::endl;
	std::cout << has_begin<std::vector<int>>::value << std::endl;
	std::cout << has_end<std::vector<int>>::value << std::endl;
	std::cout << std::is_class<std::vector<int>>::value << std::endl;

	std::cout << "======test_is_iterable===========" << std::endl;
	std::cout << is_iterable<int>::value << std::endl;
	std::cout << is_iterable<long>::value << std::endl;
	std::cout << is_iterable<char>::value << std::endl;
	std::cout << is_iterable<std::vector<int>>::value << std::endl;
	std::cout << is_iterable<std::list<int>>::value << std::endl;
	std::cout << is_iterable<std::map<int,int>>::value << std::endl;
}
//}}}

template <class Container>
std::enable_if_t<is_iterable<Container>::value, std::ostream&>
join(Container const& c, std::string const& delim="", std::ostream& out = std::cout)
{

	typename Container::const_iterator begin = c.begin();
	if(begin != c.end()) {
		out << *begin;
		begin++;
	}
	for(; begin != c.end(); begin++)
	{
		out << delim << *begin;
	}
	return out;
}

template <class Object>
std::enable_if_t<!is_iterable<Object>::value, std::ostream&>
join(Object const& o, std::string const& delim="", std::ostream& out = std::cout)
{
	return out << o;
}

//{{{ use_join_method
void use_join_method()
{
	std::cout << "=====use_join=====" << std::endl;
	std::vector<int> v = {1,2,3,4,5};
	int three = 3;
	join(v, ", ") << std::endl;
	join(three) << std::endl;
}
//}}}
//{{{ main
int main(int argc, char *argv[])
{
	test_reflection();
	use_join_method();
	return 0;
}
//}}}
// vim: foldmethod=marker
