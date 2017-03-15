CXX=clang++
CXXFLAGS=-std=c++11 -Wall -Werror -Weffc++ -Wpedantic
SRCS=$(wildcard *.cc)
BINS=$(basename $(SRCS))
.PHONY: all clean
all: $(BINS) restore_db
clean:
	$(RM) $(BINS)
restore_db:
	cp database.bak database.txt
