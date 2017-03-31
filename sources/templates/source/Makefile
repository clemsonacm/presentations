CXX?=clang++
CXXFLAGS+=-Wall -Werror -Wpedantic
BINS = max functors tuples template_metaprogramming  \
	   baseclass subclass variadic specialization
.PHONY: all test clean
all: $(BINS)
variadic:  CXXFLAGS+=-std=c++1z
baseclass: CXXFLAGS+=-std=c++11
subclass:  CXXFLAGS+=-std=c++11
tuples:    CXXFLAGS+=-std=c++14
max:       CXXFLAGS+=-std=c++11
functors:  CXXFLAGS+=-std=c++14
specialization: CXXFLAGS+=-std=c++14
test: all
	./specialization
clean:
	$(RM) $(BINS)

