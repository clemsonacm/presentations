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
- Group Projects
- What to Do When Things Go Bad
- Finishing Smart



## Starting out Strong

- Think, don't just code
- Give yourself enough time to finish
- Test driven development
- Version control



## Version Control

- Check out [git][git] seminar to get started
- Save work in a searchable manner
- Have a log of what you've tried
- Commit when you get something working



## Test Driven Development

- Write tests first
- Make sure the tests fail
- Code until you pass the tests



## Automate the Tedium

- Automate builds
- Automate testing
- Automate documentation
- Automate deployment



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



## Automate Documentation

- Saves effort of updating both
- For projects that require it:
   - Create a `docs` target
   - Write documentation as you go
   - Use doxygen, javadocs, or sphinx



## Automate Deployment

- Means different things different places
- Testing on lab machines
- Automating submissions to Handin
- Saves time and effort
- Reduces stress



## Handling Group Projects

- Communication
- Don't forget about dependencies
- Buffet, Bitbucket, etc.
- Branching
- Mocking



## Branching

- Have a master branch
- Work on separate branches
- Fix merge conflicts on the feature branch
- Test before merging back



## Mocking

- Reduce dependencies for testings
- Write dummy classes/functions
- Returns hard coded values



## What To Do When Things Go Bad

- Talk to your professors


## Debugging

- `gdb` is your friend
- `pdb` for python


## Reverting

- Commit (and branch)  prior to big changes
- Prefer reverts to rebases to preserve history



## Finishing Smart

- Don't share your code without permission



## Further Resources

- [Austin's magic makefile][1]



## Questions

Send feedback to acm@cs.clemson.edu

This material available under [CC By-SA 4.0](http://creativecommons.org/licenses/by-sa/4.0/)

[1]: https://github.com/protractorninja/cu-handin-magic-make/
[git]: people.cs.clemson.edu/~robertu/git/git.html
