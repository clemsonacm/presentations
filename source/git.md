# Git Well Soon!


## How to keep your code straight with Git

Brought to you by Clemson ACM. Join us on `#clemsonacm` @ `irc.freenode.net`!

## Speakers:

Robert Underwood - ACM Vice President\
Austin Anderson - ACM President



## Coming Up

1. Git is a VCS. Huh?
2. Why on Earth do I care?
3. How can I _git_ started?
4. Wrap-up and Reminders



## Git? Sounds... unpleasant.

- git - (n) An unpleasant or contemptible person.
- git - (n) Free, Open Source, Fast, Scalable, and Distributed Version Control System
    - Free as in lunch
    - Open Source as in Linux
        - Git was built as a VCS _for_ Linux!
    - Distributed Version Control System??



## What is DVCS, and Why Do I Care?

- Consider this...



## Your Projects, in the Present Day

- Backing up your code?
    - Create a file
    - Save several copies (with different names?)
    - Oops, we overwrote our backup ... it's gone!
- Trying new things?
    - Save old code to a new file
    - Merging good stuff with bad stuff is hard!
    - Found a bug later on? When did it get here?



## Trying to work in a group? Yuck.

- Emailing versions back and forth
- `diff` and `patch`
- What if you screwed up?
    - How does everyone get the fix?
- What if a new group member joins?



## A _Version Control System_ handles it all!

- Store a file to a **repository** (a.k.a. a **repo**)
- The software tracks the versions
- Provides tools for...
    - Finding when bugs were added
    - Finding who wrote a piece of code
    - Restoring old versions of code
    - Merging different versions of the same code (teams, etc.)
    - And more!
- New team members checkout/clone the repo
- Now we're *gitting* somewhere!



## Getting Started with git

- First, `git config --global`:
    - user.name   "Mr. President"
    - user.email acm@cs.clemson.edu
    - core.editor Vim
    - color.ui True
- `git init` - creates a new repo in the current folder
- `git clone <url>` - get your own copy of another repo



## Tracking and Updating Files

- `git add files...` - staging new changes and files
- `git status` - see the current status
- `git commit` - saves a set of changes and a *commit message*



## Commit to Good Commit Messages

- A good commit addresses the following:
   1.   Why is this change necessary?
   2.   How does this address this the issue?
   3.   Big picture what was changed?



## Investigating the Past

- `git log` - See what you did
- `git diff` - See the actual changes as a *diff*
- `git blame` - See when a line was last changed
- `git reflog` - Look through *all* recent commits!



## Dealing with Mistakes

- `git checkout -- <file>` to reset a file to the last commit
- `git reset`: reset state to a specific commit
- `git revert`: record that you're reverting to a specific commit
- As a last resort: `git reset HEAD --hard` 



## What is a branch?

- A branch is a set of related versions
- Great for...
    - Trying something new 
    - Building new features 
- Toss it or Merge it when you're done



## What is Master?

- One Branch to rule them all?
- Stable, Final, Sharable Product
- Try not to make changes directly here
    - at least for team projects
- **Always** test changes merged into Master



## Because Branches

- `git branch`
- `git checkout -b MyNewBranch`
- `git merge MyNewBranch`



## Sharing code

- GitHub and Bitbucket offer free "hosts" 
    - Free stuff for `.edu` email addresses!
    - Check out `buffet.cs.clemson.edu`!
- Fairly easy to set up a git "server"
- `git remote add origin`
- `git push -u MyNewBranch`
- `git push` after the first push



## When sharing is not caring

- Some files should not be shared
    - May contain sensitive information
        - API Keys
        - Passwords
    - May be machine/developer specific
    - May be a breach of academic integrity
- Use a `.gitignore` or `core.excludes` file



## Merge Conflicts

- `git mergetool`
- There are also tools to do this better
- Often fairly painless
- Don't forget to retest after merges



## Need more power?

- Some hosts provide wikis and issue trackers
- Pull Requests are a great code review tool
- Git provides hooks for automating tasks
- Create your own commands with git!
- Vim's Fugitive plugin
- `git help`



## But my lovely UI... <span id=emoticon>:(</span>

- There are tools that use git with GUIs
- Some of them are quite good
    - Github has a great desktop client
- Meld is fantastic, but there are others
    - Downside is Meld is not on lab machines
    - gvimdiff and vimdiff for the Vim crowd
    - For the emacs OS use `emerge`



# Wrap-Up



## Summary

- Please use version control!
- Git is an easy to use DVCS
- Spend less time reverting, more time coding



## Further Resources

- [Great Book](http://git-scm.com/book)
- [Cheatsheet](https://www.atlassian.com/dms/wac/images/landing/git/atlassian_git_cheatsheet.pdf)
- [Workflows](https://www.atlassian.com/git/workflows)
- [Mecurial (hg)](http://blogs.atlassian.com/2012/02/mercurial-vs-git-why-mercurial/?utm_source=wac-dvcs&utm_medium=text&utm_content=dvcs-options-git-or-mercurial)
- [Why commits messages are important](https://robots.thoughtbot.com/5-useful-tips-for-a-better-commit-message)



## Questions

Send us feedback at `acm@cs.clemson.edu`!

This material available under [CC By-SA 4.0](http://creativecommons.org/licenses/by-sa/4.0/)
