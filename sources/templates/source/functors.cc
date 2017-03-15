#include <iostream>
#include <functional>
#include <vector>

void aside_on_member_fn();

//example of generic function using predicates
template <class InputIterator, class UninaryPredicate>
UninaryPredicate for_each(InputIterator begin, InputIterator end, UninaryPredicate f)
{
	for(;begin != end; begin++)
	{
		f(*begin);
	}
	return f;
}

//helper method
template <class fn>
void use_functor(std::string const & name, fn const & function)
{
	std::vector<int> v = {1,2,3,4,5};

	std::cout <<  "=====" << name << "====" << std::endl;
	for_each(v.begin(), v.end(), function);
	std::cout << std::endl;
}


//functor struct, classes work just as well but have more overhead in this case
template <class T>
struct functor
{
	T const& operator()(T const& val) { std::cout << val << " "; return val;}
};



//example generic function
template <class T>
T const & print(T const & val) { std::cout << val << " "; return val;}

template<class T>
class Printer
{
	public:
	T const& print(T const& val) const { std::cout << val << " "; return val;}
};

#define printM(x) \
	do { \
		std::cout << (x) << " ";  \
		}while(0) 


void use_functors()
{


	//you can't pass a macro
	//use_functor("macro", printM);

	//You can print with structs
	{
		functor<int> print_int_struct;
		use_functor("struct", print_int_struct);
	}

	//With function pointers
	{
		int const& (*print_fn_ptr)(int const&) = print;
		use_functor("pointer", print_fn_ptr);
	}

	//With function reference
	{
		auto& print_ref = print<int>;
		use_functor("func reference", print_ref);
	}

	//Or more simply
	use_functor("func reference2", print<int>);

	//but not
	//use_functor("func reference", print);
	
	//Or with free member functions (std::bind is very slow)
	{
		//note the use of std::bind is required
		//&Printer<int>::print is not unitary, but binary
		//if it was free its signature would be:
		//
		//    int const& (*print)(Printer<int>*, int const&)
		//
		using namespace std::placeholders;
		const Printer<int> p;
		auto printMemFn = std::mem_fn(&Printer<int>::print);
		auto boundFn = std::bind(printMemFn, p, _1);
		use_functor("memberfn bound", boundFn);
	}

	//or with lambdas
	{
		auto print_lambda = [](int const& val) -> int const& {
			std::cout << val << " ";
			return val;
		};
		use_functor("lambda", print_lambda);
	}

	//or generic lambdas in c++14
	{
		auto auto_print_lambda = [](auto const & val) -> decltype(val) const&{
			std::cout << val << " ";
			return val;
		};
		use_functor("generic lambda", auto_print_lambda);
	}

	//or lambda's to member functions (preferred method to call member functions)
	{
		Printer<int> p;
		auto print_memfn = [&p](int const& val){
			return p.print(val);
		};
		use_functor("memfn lambda", print_memfn);
	}
}


int main(int argc, char *argv[])
{
	use_functors();	
	return 0;
}
