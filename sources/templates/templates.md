# C++ Templates

### Staring into the abyss

Robert Underwood


## Overview

1.	Why templates?
2.	Basics
	1.	Template Methods
	2.	Template Polymorphism
	3.	Classes vs Functions
3.	Applications
	1.	Trait Specialization and Policies
	2.	Template Meta-programming
	3.	Tuples
	3.	Functors
	4.	Other Uses



## Warning

Here be dragons!



##	Why templates?

+	Generics -- code that accepts any type
+	Performance -- type specific implementation
+	Code Reuse -- let the compile do the writing


##	Basics


### What are they?

+	Allows you to:
	+	delay binding of type to variables
	+	write generic code of some type T
	+	trades code size for binary size (and readability?)


###	Classes vs Functions

+	Functions have type deduction
+	Classes/Structs have partial specialization
+	At least for now...


###	Template Methods

+	Will deduce but not coerce types
+	They can be overloaded


###	Template Polymorphism

+	If possible,
	+	Put only template methods in a template class
	+	Each expansion takes space in the binary
	+	Each expansion increases compile time


### Variadic Templates

+	Templates of many arguments
+	Use overloading to handle recursion


### SFINAE

>	Substitution Failure is not an Error

+	A blessing and a curse
	+	Almost incomprehensible error messages
	+	Allows overloading and "compile-time reflection"
		+	Reflection -- change behavior on class attribute/methods



##	Applications


### Trait Specialization and Policies

+	Select an algorithm/behavior through:
	+	reflection on types
	+	template arguments
+	Implementations vary
	+	SFINAE-based -- more flexible, harder to implement
	+	Specialization-base -- less flexible, almost trivial


###	Template Meta-programming

+	Solve a recursive problem at compile time
+	often inline, beware template recursion depth


###	Tuples

+	collections of types
+	very similar to a struct
+	can be expanded and passed as function arguments
+	can be used to extract variables via `std::tie`


###	Functors

+	Accept a function as argument
+	Write functional paradigm code
	+	Easier to parallelize
	+	Easier to reason about


###	Other Uses

+	Smart Pointers
+	Iterator Generics
+	Curiously Recurring Template Pattern
+	Parameterized Type Attributes
+	Generic implementations of Design Patterns


## Further Reading

+	Many of concepts are found
	+	C++ Templates: The Complete Guide
	+	Modern C++ Design


## Questions

Send us feedback at <rr.underwood94@gmail.com>!

This material available under [CC By-SA 4.0](http://creativecommons.org/licenses/by-sa/4.0/)
