# Think Different
### How to Code Smarter, not harder


## Brought to you by Clemson ACM

We're on Freenode! Join `#clemsonacm` on chat.freenode.net!

### Speakers:

Robert Underwood - ACM Vice President

Austin Anderson - Former ACM President


## Coming Up

- Starting out Strong
- Automate the Tedium
- What to Do When Things Go Bad
- Finishing Smart



## Starting out Strong


## Happy Thoughts

- Think about what you're doing before you code
   - Make sure you understand the spec first
- Try using paper or a whiteboard to plan
- Give yourself enough time to do the project!
   - Do a little bit of work, regularly


## Consider Version Control

- Check out our [git seminar][git]  to get started
- Easily track and search through your development history
- Commit whenever you make progress
- Tools: `git`, `mercurial`

[git]: http://present.protractor.ninja?git


## Consider Test Driven Development (TDD)

- Basics:
  - Write tests first
  - Make sure the tests fail
  - Code until you pass the tests
- Extensive tests help you track progress
- Tools: [`check`](http://check.sourceforge.net/), [`bats`](https://github.com/sstephenson/bats), `python unittest`



## Automate the Tedium

### Save your time and sanity!


## Makefiles, in brief

- Makefiles are a great way to automate building, testing...

Simple example
```makefile
a.out: project.c
   gcc project.c

run: a.out
   ./a.out "arguments"
```

Same thing, with Make's automatic compilation rules
```makefile
CC=gcc
CFLAGS=-g -Wall

a.out: project.c

run: a.out
   ./a.out "arguments"
```


## Automate Builds

- Create targets for each executable and task
- Consider using multiple compilers
   - `gcc` is what professors test with
   - `clang` for readable error messages
- `all` and `clean` targets are convention (and useful)
  - Use `.PHONY` for tasks that aren't files

```makefile
.PHONY: all run clean
all: a.out
clean:
   rm a.out
run: a.out
   ./a.out "arguments"
```


## Automate Testing

- Create a `test` target
- With TDD, commit when you pass more tests
- Things you can test
   - Output
      - tools: `awk`, `bash`, `diff`, `grep`
   - Exit status
      - tools: `bash` using `$?`, `bats`
   - Memory leaks
      - tools: [`valgrind`](http://valgrind.org/)


## Automate Other Stuff

- Documentation?
   - Create a `docs` target
   - Write documentation as you go
   - Use doxygen, javadocs, or sphinx
- Log files?
   - Use Python or Bash
- Bash and Python scripts can do a lot!


## Automate Submission

- Saves time, effort, and stress
- Handin is Mercurial-based, so you can use the command line
- Or, [Austin made a makefile for you already][1]

[1]: https://github.com/protractorninja/cu-handin-magic-make/



## What To Do When Things Go Bad


## Talk to your professors

- Go to office hours with your problems
- Good professors want to help you learn
- Go early! Everyone goes the night before


## Debugging

- `gdb`
- `valgrind`
- `git bisect` helps find where a bug was introduced
   - Only works if commits are testable


## Reverting Old Changes

- Version control makes this easy
- Commit (and branch) prior to big changes
- `git revert` can undo a specific earlier commit



## Finishing Smart

- Test everything again before you submit!
- Submit early, submit often
   - Handin lets you submit as many times as you want
- Don't share your code without permission



## Further Resources

- More command reference:
   - UNIX `man` pages - most commands have a `man` page
   - [Grymoire][1] - great scripting resource
   - [Archwiki][2] - great command resource
- [Austin's magic makefile][3] automates submission and testing on the lab machines

[1]: http://www.grymoire.com/
[2]: https://wiki.archlinux.org/index.php/Main_Page
[3]: https://github.com/protractorninja/cu-handin-magic-make/


## Useful Commands

- `time`
- `watch`
- `scp` and `ssh`
- `find`
- `sed`
- `ag`, the [Silver Searcher](https://github.com/ggreer/the_silver_searcher)



## Questions

Send feedback to acm@cs.clemson.edu

This material available under [CC By-SA 4.0](http://creativecommons.org/licenses/by-sa/4.0/)

