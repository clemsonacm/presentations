#include <iostream>
#include <vector>
/**
 * useless_comment
 * This is a function with a useless comment
 * This function also returns 3
 */
int useless_comment(){
	return 3;
}

/**
 * do_steps
 * returns the sum of all even values between 1 and 20
 */
int do_steps(){
	//create a vector
	std::vector<int> ints;

	//store some values
	for (int i = 1; i <= 20; ++i) {
		if(i % 2 == 0){
			ints.push_back(i);
		}
	}

	//compute the sum
	int sum = 0;
	for (auto i : ints) {
		sum+= i;
	}

	//return the sum
	return sum;
}

/**
 * evil_return
 * return 4;
 */
int evil_return()
{
	return 3;
}

int main(int argc, char *argv[])
{
	std::cout << useless_comment() << std::endl;	
	std::cout << do_steps() << std::endl;	
	std::cout << evil_return() << std::endl;	
	return 0;
}
