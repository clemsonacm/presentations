CXX=clang++
CXXFLAGS+=-Wall -Werror -Wpedantic
BINS = max functors tuples template_metaprogramming  \
	   baseclass subclass variadic specialization \
	   partial  policy
.PHONY: all test clean
all: $(BINS)
max:       CXXFLAGS+=-std=c++11
partial:   CXXFLAGS+=-std=c++11
variadic:  CXXFLAGS+=-std=c++1z
baseclass: CXXFLAGS+=-std=c++11
subclass:  CXXFLAGS+=-std=c++11
tuples:    CXXFLAGS+=-std=c++14
functors:  CXXFLAGS+=-std=c++14
specialization: CXXFLAGS+=-std=c++14
policy: CXXFLAGS+=-std=c++14
test: all
	./specialization
clean:
	$(RM) $(BINS)

