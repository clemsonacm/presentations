# Python

### A Parser Tongue Primer


## Brought to you by Clemson ACM

We're on Freenode! Join `#clemsonacm` on chat.freenode.net!

### Speakers:

Robert Underwood - ACM Vice President



## Coming Up

-   The Zen of Python
-   Imperative programming
-   Functional programming
-   String Parsing
-   Object Oriented
-   Learning more



## Getting into the Zen of Python


### Getting Started

-   Which version of python?
	-   I recommend python3.X
	-   Provided setup from class is python 2.7
-   Which interpreter?
	-   I recommend ipython for development


### The Zen of Python

`import this`

-   "Beautiful is better than ugly"
-   "Simple is better than complex"
-   "There should be one obvious way to do it"



## Imperative Programming


### Variables

-   Python uses duck typing
-   Immutable Types
	-   None, int, float, bool, 
	-   tuple, complex, str
	-   function
-   Mutable Types
	-   dictionary, lists


### Container Types

-   Dictionary - Mutable set unique of keys to values
-   Set - Mutable set of unique keys
-   List - Mutable ordered list
-   Tuple - Immutable version of a list
-   See `collections` for more examples


### What is True?

-   0, False, and None are False
-   Everything else is True


### Conditionals

```python
if x == 1 or y == 2:
	print(x)
elif x in [3,4,5]:
	print("foo", x)
else:
	print("bar")
```


### Looping

```python
for a in range(1,10,2):
	print(a)
	if a == 5:
		break
else:
	print("never called")
```


### Lists

```python
a = [1,2,3,4,5]
a.append(0)
position = a.index(3)
for value in sorted(a):
	print(value)
```


### Dictionaries

```python
a = {
	"a": 1,
	"b": 2,
	"c": 3,
}
a['a'] += 2
a['d'] = 4
a.get('e',0)
for key in a:
	print(key,a[key])
```


### Functions

```python
def add(a=0,b=4):
	"returns the sum of a and b"
	return a+b

add()
add(1)
add(1,1)
add(b=3)
add(1.0,2)
```


### Functions cont...

You can also have lists of arguments

```python
def add_all(*args, **kwargs):
	"adds a arbitary sequence"
	for key in kwargs:
		print(key, "-->", kwargs[key])
	return sum(args)

add_all(1,2,2,3,4,5)
add_all(1,2, b="foo", c="asdf")
```


### Context Managers

-   Use when you change "contexts"
	-   think open/close, connect/disconnect
	-   Uses the `with` syntax
	-   define `__enter__` and `__exit__`

```python
with open("/path/to/file.txt", "w") as essay:
	essay.write(boring_paper)
```



## Functional Programming


### Iterators

-   Iterators are objects that define:
	-   Represent a collection of objects
	-   `__iter__` and `__next__`
-   dictionaries, lists, sets are all iterators
-   Most standard functions accept iterators


### Generators

-   Generators are iterable functions that call yield
-   Generators __can be__ more memory efficient

```python
def count_by_3(x):
	x = 0
	while True:
		yield x+3
```


### Operator

-   Python operators as functions
-   Useful in Lambda functions and comprehensions

```python
from operator import add
x, y = 1, 2
x + y == add(x,y)
```


### Lambda Expressions

Simple "anonymous" functions

```python
a = ["red", "orange", "yellow", "greeen",
	 "blue", "indego" "volit"]
sorted(a, key=lambda x: len(x) % 3)

b = map(lambda x: x+1, range(10))
```


### Comprehensions

Syntactic sugar for building collections

```python
[i+2 for i in range(10)] #Lists
{i+2 for i in range(10)} #Sets
{i:i+2 for i in range(10)} #Dictionaries
(i+2 for i in range(10)) #Generators
```


### Functools

Useful methods from functional programming

-   `map` built-ins
-   `reduce` -- used to be built-in now in functools
-   `partial/partialmethod` -- simplifying call signature
-   `singledispatch` -- overloading type generic functions
-   `total_ordering` -- writing comparisons

```python
from functools import reduce
from operator import add
values = range(10)
print(reduce(add,values))
```


### Itertools

Working with iterators

-   `zip` -- built-in
-   `chain` -- link iterators together
-   `cycle` -- repeat iterators infinitely
-   `groupby` -- return iterator of groups
-   `zip_longest` -- zip until longest iterator consumed

```python
from itertools import cycle
jobs = [1,2,3,4]
servers = ['a','b','c']
for job, server in zip(jobs, cycle(servers))
	print (job,"-->", server)
```



## String Parsing


### Several types of strings

```python
raw_string = r'^\d+\s\S+$'
double_quoted = "asdf\n"
single_quoted = 'This is literal\n'
byte_string = b"asdf"
```


### str methods

-   Strings are sequences!
-   Important methods
	-   index -- return first index of substring
	-   split -- separate on token
	-   join -- combine a list of str
	-   upper/lower -- capitalize or lowercase
	-   startswith/endswith -- compare prefix/suffixes

```python
words = ["all", "you", "need", "is", "join"
" ".join(s.title() for s in words)
```


### Ever seen this?

What on earth does this print??
```C
printf("%4d%c%c%g%15.4f %20s%n\n", ...);
```


### Format()

-   Python has, printf() style formatting but...
	-   It doesn't handle collections well
	-   Doesn't solve the fundamental readability problem
-   format() is more powerful and more readable

```python
"Welcome {user}, today is {date:%B %d, %Y}"\
	.format(user="Mr. President", date=datetime.date.today())
```


### Regular Expressions

-   Mostly Perl compatible regular expressions
	-   Notably the `?{}` syntax is absent
	-   Useful when str doesn't quite cut it
	-   _DONT USE IT TO PARSE [HTML][zalgo]_

```python
import re
pattern = re.compile(r"^(\d+)\s+([a-z]*)\s+$")
with open("example.txt") as infile:
	for match in pattern.finditer(infile.read()):
		print(match.group(1), match.group(2))
```
[zalgo]: http://stackoverflow.com/questions/1732348/regex-match-open-tags-except-xhtml-self-contained-tags/


### Well known formats

-   csv, xml, html, and json have parsers
-   Parsers for yaml and other common formats exist
	-   If using xml consider `defuesedxml`
	-   If using html consider "Beautiful Soup" a.k.a `bs4`

```python
import csv
def parse_csv_line(line):
	"""parse a stirng of csv that is NOT in a file"""
	reader = csv.reader(line.splitlines())
	for entry in reader:
		yeild entry
```



## Object Oriented Programming


### Classes

-   Not like classes in other languages
-   Classes are _only_ a tool for code reuse
-   DRY -- Don't Repeat Yourself
-   There is nothing sacred about it


### How are they different?

-   Constructor is called `__init__`
-   All methods need to be passed `self` 
-   No such thing as private
	-   `_non_public` - avoid using this method
	-   `__mangeled` - do not subclass this method


### Multiple Inheritance

-   Multiple Inheritance via `super()`
	-   `super()` delegates to the next in line
	-   Remember the Method Resolution Order (MRO)
		-   children are called before parents
		-   order in class declaration breaks ties


### Decorator Objects

-   Implement the decorator function with ease
-   Decorators work "inside out"

```python
import logging
def log_entry_exit(orig):
	"""adds logging a function"""

	def	logged_function(*args, **kwargs):
		logging.info("starting %s", orig.__name__)
		orig(*args, **kwargs)
		logging.info("exiting %s", orig.__name__)

	return logged_function

@log_entry_exit
def print_wrapper(a):
	print(a)
```


### Properties

Functions exposed as variables

-   Useful for:
	-   simpler code 
	-   ensuring data integrity
	-   controlling access (ie locking)


### An Example

```python
class Square():
	def __init__(self, side=0):
		self.side = side

	@property
	def area(self):
		"area of a square"
		return side ** 2

	@area.setter
	def area(self, a):
		side = math.sqrt(a)

a = Square()
a.area = 25
a.area
```


### Method Types

-   method -- normal methods
-   `classmethod` -- provide alternative constructors
-   `staticmethod` -- conceptually related functionality
-   `raise UnimplementedError` to force implementation


### Down the Rabbit hole

-   Magic Methods
	-   Allow for operator overloading
	-   Used for singletons, decorators, callable-classes
-   Objects can be callable
	-   Simply define the `__call__` method
-   Every object is a dictionary
	-   Introspection - get information about a class
	-   Meta-classes - create a class of classes (ie black magic)



### A quick note on modules

-   Python has a module for everything or soon will
	-   First check the standard library
	-   Then check PyPI
-   You can even make your own [modules!][modules]

[modules]: http://python-packaging.readthedocs.org/en/latest/minimal.html



## Further Resources

-   [Dive Into Python][dive]
-   [Dive Into Python 3][dive3]
-   [Standard Library Reference][stdlib]
-   PyCon Talks on YouTube
	-   [Raymond Hettinger][raymond]
	-   [Decorators Context Managers][context]
-   the `help()` function or `?` and `??`

[stdlib]: https://docs.python.org
[dive]: http://www.diveintopython.net/
[dive3]: http://www.diveintopython3.net/
[raymond]: https//www.youtube.com/results?search_query=raymond-hettinger 
[context]: https://www.youtube.com/watch?v=cSbD5SKwak0


## Questions

Send feedback to acm@cs.clemson.edu

This material available under [CC By-SA 4.0](http://creativecommons.org/licenses/by-sa/4.0/)

