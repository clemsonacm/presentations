//{{{includes
#include <tuple>
#include <experimental/tuple>
#include <memory>
#include <map>
#include <stdexcept>
#include <iostream>
#include <iomanip>
namespace std
{
	using experimental::apply;
	// make_from_tuple{_impl,} from http://en.cppreference.com/w/cpp/utility/make_from_tuple
	namespace detail {
		template <class T, class Tuple, std::size_t... I>
			constexpr T make_from_tuple_impl( Tuple&& t, std::index_sequence<I...> )
			{
				  return T(std::get<I>(std::forward<Tuple>(t))...);
			}
	} // namespace detail
	 
	template <class T, class Tuple>
	constexpr T make_from_tuple( Tuple&& t )
	{
			return detail::make_from_tuple_impl<T>(std::forward<Tuple>(t),
							std::make_index_sequence<std::tuple_size<std::decay_t<Tuple>>::value>{});
	}
}
///}}}
//{{{ Object(int,int)
class Object
{
	public:
	Object(int i,int j): i(i), j(j) {}
	int getI() const {return j;}
	int getJ() const {return i;}
	private:
	int i;
	int j;
};

std::ostream& operator<<(std::ostream& out, Object const& o)
{
	return out << "(" << o.getI() << ", " << o.getJ() << ")";
}
//}}}

template<class Key, class Value, template <class...> class MapType = std::map>
class FlyWeight
{
	public:
	using Map = MapType<Key,std::shared_ptr<Value>>;

	template<class... Args>
	std::shared_ptr<Value> get(Args const&... args)
	{
		auto key = std::make_tuple(args...);
		auto it = flyweights.find(key);
		if(it != flyweights.end())
		{
			return it->second;
		}
		auto value = construct(key);
		flyweights.emplace(key,value);
		return value;
	}

	template<class... Args>
	std::shared_ptr<Value> 
	construct(std::tuple<Args ...>const& key)
	{
		return std::make_shared<Value>(std::move(std::make_from_tuple<Value>(key)));
	}

	typename Map::size_type size()
	{
		return flyweights.size();
	}

	private:
	Map flyweights;
};


//{{{main
int main()
{
	FlyWeight<std::tuple<int,int>,Object> f;
	auto i = f.get(1,2);
	auto j1 = f.get(2,3);
	auto j2 = f.get(2,3);
	auto k = f.get(3,4);
	std::cout << std::boolalpha;
	std::cout << *i << std::endl;
	std::cout << (j1.get()==j2.get()) << std::endl;
	std::cout << f.size() << std::endl;
}
//}}}
// vim: foldmethod=marker
