#include <iostream>

//template meta-programming is useful for compile_time commutable values
//It cannot be inductive or branch on run-time values

//inductive case
template <std::size_t N, class T>
struct DotProduct
{
	static T result (const T* a, const T* b){
		return *a * *b + DotProduct<N-1,T>::result(a+1,b+1);
	}
		
};

//base case
template <class T>
struct DotProduct<1,T>
{
	static T result (const T* a, const T* b){
		return *a * *b;
	}
};

//convenience function
template <std::size_t N,class T>
T dot_product(const T* a, const T* b)
{
	return DotProduct<N,T>::result(a,b);
}

//{{{main
int main(int argc, char *argv[])
{
	int  a[] = {1,2,3,4,5};
	int  b[] = {1,2,3,4,5};
	std::cout << dot_product<5>(a,b) << std::endl;
	return 0;
}
//}}}
// vim: foldmethod=marker
