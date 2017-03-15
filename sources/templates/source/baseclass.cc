#include <iostream>

class base
{
	public:
	virtual ~base()=default;
	int getThree() const
	{
		return 3;
	}
	virtual int getFour() const
	{
		return 4;
	}
	virtual std::ostream& print(std::ostream&) const=0;
};

std::ostream& operator<<(std::ostream& out, base const& base)
{
	return base.print(out);
}

template <class T>
class sub: public base
{
	public:
	sub(T t): base(), t(t) {}

	std::ostream& print(std::ostream& out) const
	{
		return out << t;
	}
	private:
	T t;
	
};

int main(int argc, char *argv[])
{
	sub<int> i(2);
	sub<double> d(3.0);
	sub<long long> l(3l);
	sub<unsigned int> u(3);

	std::cout << i << std::endl;
	std::cout << d << std::endl;
	std::cout << l << std::endl;
	std::cout << u << std::endl;
	return 0;
}
