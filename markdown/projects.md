# Think Different
### How to Code Smarter, not harder


## Brought to you by Clemson ACM

We're on [Steam](http://steamcommunity.com/groups/clemsonacm) &
Freenode! Join #clemsonacm on chat.freenode.net!

### Speakers:

Robert Underwood - ACM Vice President
 Austin Anderson - ACM President


## Coming Up

- Starting out Strong
- Automate the Tedium
- What to Do When Things Go Bad
- Finishing Smart



## Starting out Strong


## Happy Thoughts

- Think about what you're doing before you code
- Try using paper or a whiteboard to plan
- Give yourself enough time to do the project!
  - Do a little bit of work, regularly


## Consider Version Control

- Check out [git][git] seminar to get started
- Save work in a searchable manner
- Have a log of what you've tried
- Commit when you get something working
- Tools: `git`, `mercurial`

[git]: people.cs.clemson.edu/~robertu/git/git.html


## Consider Test Driven Development

- Write tests first
- Make sure the tests fail
- Code until you pass the tests
- Good tests means you'll know when you're done
- Tools: `check`, `bats`



## Automate the Tedium


## Makefiles, in brief

- Makefiles are a great way to automate building, testing...

```makefile
a.out: project.c
    gcc project.c -o a.out

run: a.out
    ./a.out "arguments"
```


## Automate Builds

- Write a Makefile
- Create targets for each executable
- Should build from just the source
- `all` and `clean` targets


## Automate Testing

- Create a `test` target
- Saves you time and sanity
- Run before every commit
- Things you can test
   - Output
   - Exit status
   - Memory leaks


## Automate Weird Stuff

- Documentation?
   - Create a `docs` target
   - Write documentation as you go
   - Use doxygen, javadocs, or sphinx
- Log files?
   - Use python or bash
- Bash or Python scripts are powerful!


## Automate Submission

- Saves time, effort, and stress
- Handin is Mercurial-based, so you can use the command line
- Or, [Austin made a makefile for you already][1]

[1]: https://github.com/protractorninja/cu-handin-magic-make/


## What To Do When Things Go Bad


## Talk to your professors

- Go to office hours with your problems
- Good professors want to help you learn


## Debugging

- `gdb`
- `valgrind`
- `git bisect` helps find where a bug was introduced
  - As long as you can run something at every commit


## Reverting Old Changes

- Commit (and branch) prior to big changes
- `git revert` can undo a specific earlier commit



## Finishing Smart

- Test everything again before you submit!
- Sumbit early, submit often
  - Handin lets you submit as many times as you want
- Don't share your code without permission



## Further Resources

- [Austin's magic makefile][1] automates submission and testing on the lab machines

[1]: https://github.com/protractorninja/cu-handin-magic-make/


## Questions

Send feedback to acm@cs.clemson.edu

This material available under [CC By-SA 4.0](http://creativecommons.org/licenses/by-sa/4.0/)

