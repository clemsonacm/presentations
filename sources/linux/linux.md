# Linux is Scary


### Brought to you by Clemson ACM

We're on [Steam](http://steamcommunity.com/groups/clemsonacm)
and Freenode on `#clemsonacm`

### Speakers:

Robert Underwood - ACM Vice President 

Marshall Clyburn - ACM President


## Coming up

1. What's up with Linux?
2. The Linux file system
3. Terminal Power
4. Getting owned by Permissions
5. Working from Other Machines
6. Your free web hosting at people.cs.clemson.edu
7. Wrap-up



# What's up with Linux?


## Linux: A Short History

- Created in 1991 by **Linus Torvalds**
- Written in C and Assembly Languages
- Uses a *Unix-like* file structure (more on that later)
- Kernel is still being maintained by Torvalds et al
	- You could contribute if you wanted!


## What's a Distribution?

- A "flavor" of Linux with small differences
- Might differ in...
    - *Desktop Environment* - controls windows
        - Examples are **Mate**, **Gnome**, and **KDE**
    - *Package manager*  - install and update software
    - Behind-the-scenes *applications* and *settings*
    - Default *applications* 


## Common Distributions

- **Debian based**: uses the DEB package system
	- Ubuntu (Xubuntu, Kubuntu, Ubuntu Mate)
	- Elementary OS, Linux Mint, et al
- **RedHat based**: uses the RPM package system
	- Fedora, CentOS, Scientific Linux


## Common Distributions
- **OpenSUSE**: heavy focus on OS innovation
- **Source based**: focus on customization
	- Gentoo, ArchLinux


## Big Names in \*nix

- **Linus Torvalds**:  creator of Linux,
- **Greg Kroah-Hartman**: stable branch maintainer
- **Richard Stallman**: founder of GNU
- **GNU Project**: "GNU's Not Unix", 
	- leader in Open Source Software Licensing
	- Wrote GNU Public License (GPL)


## "Kernel" and Other Scary Words

- **Kernel**: part of Linux that interacts with hardware
- **Shell**: terminal-based control application
	- manipulate anything on the system 
	- starts programs
- **Bash**: is the most common shell


## "Kernel" and Other Scary Words

- **Environment Variables**: variable that controls program behavior
- **PATH**: where to the shell searches for executables
- **EDITOR**: what editor to use when needed
- **HOME** where your files are kept


## "Kernel" and Other Scary Words

- **Version control systems**: track history of code
	- Common VCSs include `git`, `mercurial`, and `svn`
    - Web handin uses `mercurial` as a back end 
	- See our seminars on `git` or projects for more
- `make` and `Makefile`: a tool for installing software


## "Building from Source"

- When you can't get a pre-compiled executable
- Download the source code
- Read the README file, then often run
- `./configure`
- `make`
- `sudo make install`


## Packaging systems

- Easy way to install many applications
- Most distributions have **Package Managers**
    - package managers need to be run using `sudo`


## APT

- `apt` - used on Debian based systems, including Ubuntu.
	- `apt update` - update metadata
	- `apt search <package>` - find package
	- `apt install <package>` - install package
	- `apt upgrade` - update all packages


## Other Packaging systems

- `dnf`: installed on Fedora
- `rpm`: backend for yum, dnf, et al
- `pacman`: used on Arch Linux



# The Linux File System


## Basic Hierarchy

- Based on *one* root directory, not drives like C: or D:
- Physical devices (drives, output) and important folders are
    *mounted* to subdirectories of `/`

**Some distros are a little different in how they manage these folders**


## Basic Hierarchy

- `/home`: where user's files normally live
- `/bin`: stores system executables
- `/usr`: where system libraries and the like are
- `/dev`: device nodes; Don't mess with things here
- `/mnt`: where you can mount things like USB drives


## Everything is a File

- Linux sees every object as a subclass of a file
- Folders, links, devices, and executables are "files"!


## Where are my .exes?

- File extensions categorize, not restrict
- A file with any name could be executed
    - `a.out`, `prog1`, `.bashrc`
- Files starting with a dot like `.bashrc` are usually *hidden* from
    listings
- Running a command like `sl` is really just running an executable
    file within the `PATH`



# Terminal Power


## echo "navigation commands"

- Stuck? `Ctrl+c` often quits the running program
- `pwd` lists your current directory
- `cd directory` moves the terminal to `directory`
- `ls` lists files and folders in the current directory
    - `ls -l` gives additional file information
    - `ls -a` shows even `.hidden-files`


## echo "file commands"

*** THERE IS NO TRASH CAN! ***

```bash
mv orig.file new.file  # move a file
cp orig.file copy.file # copy a file
rm orig.file           # remove a file
rm -r directory        # remove a directory and contents
```


## --Flags?! : Command Structure

- Generally
    `progname -one-letter-flags --longer-flag parameter`
    `[optional parameters]  parameter-list...`
- Some flags need arguments after them
    - `ping -c 12` OR `ping --count=12`


## Common Flags

- Structure varies by program 
- for help try: `progname --help` or `-h` 
    - Sometimes simpler than `man progname`
- for output try: `progname --verbose` or `-v` 


## Terminal Symbols & Shorthand

- `.` (one dot) is the *current directory*
- `..` (two dots) is the *parent directory*
- `/` is the *root directory*
- `~` is your *user directory*
- `!!` is the *previously entered command*
    - Use `sudo !!` to run the last command under sudo


## Terminal Symbols & Shorthand

- `\` begins an escape character sequence
    - `\n` is a newline character
    - `\` (space) inserts a space into one argument (otherwise the
        argument will break)
    - `\\` actually inserts a backslash


## Terminal Symbols & Shorthand

- `$(command)` or \`command\` inserts the output of `command` into
- `command &` will run `command` in the background


## Messing with Output

- Any text output you see in the terminal comes from **standard out**
	- Think **cout** in C++ and **printf()** in C
- `echo input` - print `input` to standard out
- `cat input.file` - print `file` to the terminal


## Messing with Output

- Many commands like `grep` and `less` read from **standard in**
    - Think **cin** in C++ and  **scanf()** reads from in C
- `grep pattern input.file`: filters a pattern
- `less input.file`: buffers output


## Piping and Redirection

- **Piping** `command-a | command-b` 
	- connects the *standard output* of `command-a` 
	- to *standard input* of `command-b`
	- useful for chaining commands
    - Ex: `command-a | less` easy reading


## Redirection

- **Redirection** reassign standard in/out/error to files
- `progname > output.file` overwrites `output.file` with output
- `>>` *appends to* `file` with `progname`'s output
- `&>` overwrites `file` with `progname`'s *error output*
- `&>>` *appends to* `file` with `progname`'s *error output*
- `progname < input.file` uses `input.file`'s content as input for
    `progname`


## Shell History

*** How did I run that again? ***

- Press the up key to cycle through your previously entered commands
- `history` - print previous commands
- Search it with grep -- `history | grep ls`
- `Ctrl-r` for a history search


## Shell configuration

- On your home machine, you could replace **bash** with another shell
    like **zsh** or **ksh**
- Editing `~/.bashrc` can customize your shell with functions,
    **aliases**, and **functions**.
- Aliases are simple: `alias sl=echo "Steam Locomotive"`
- There are a ton of tutorials on customizing the shell, so we'll skip
    it for now.


## `man` and Other Awesome Commands

- `man` - summons an *extensive* manual page for about anything
    - `man stdio.h`, `man grep`, `man man`
- `touch name.file` creates an empty `name.file` if none exists
- `find` locate a file on your computer


## `man` and Other Awesome Commands

- `vim [edit.file]` awesome text editor with steep learning curve
- `emacs -nw [edit.file]` great OS needing a good editor
- `curl -LO [URL]` copies a file from the web


## `man` and Other Awesome Commands

- `tar` - manage tar ball (.tar) and tar ball + gzipped (.tgz, .tar.gz)
    archives
    - `tar -xzf` (e**x**tract **z**e **f**iles!!) `<archive>`
        - `tar -xf` for just `.tar`
    - `tar -czf` (**c**reate **z**e **f**iles!!)
        `archivename.tgz files...` to create an archive
    - [Relevant XKCD comic](http://imgs.xkcd.com/comics/tar.png)


## Shell Scripts

- put commands into a file to run them all at once repeatedly
- add `#!/bin/bash` as the first line
- one command per line
- `chmod u+x script.sh`
- `./script.sh`



# Getting Owned by Permissions


## Users, Root and Groups

- *Users* are unique accounts
- *Root* is the **superuser** and can do *anything*.
    - **DON'T TRY TO USE ROOT ON THE CU MACHINES**.
    - Run a command as root with `sudo <command>` 
	- temporarily login as root with `sudo --login`


## Users, Root and Groups

- Users in the same *Groups* share permissions pertaining to that
    group
    - Ex:users in `sudoers` can use `sudo` 
	- the admin group might be different
    - Users can be in multiple groups
- `man chmod` and `man chgrp` for more info on permissions and groups



# Working from other machines


## Getting to your files with SSH

- `ssh username@access.cs.clemson.edu` starts a remote connection to
    the Lab computer
- Pick one of the servers listed in the message and `ssh` to it
- **DON'T RUN/COMPILE ON access.cs.clemson.edu**


## Using a VM

- VirtualBox
    - Can run a Linux VM inside of Windows/Mac OS X


## Windows: Cygwin?

*** Bad Idea ***


## Ubuntu for Windows?

*** Better Idea ***


## Dual-boot or VM

*** Best Idea ***



## Final warnings

*** NEVER RUN A RANDOM COMMAND FROM THE INTERNET ***

- **DON'T CHEAT**
    - Professors use advanced software that checks the algorithms your
        code uses
    - Changing variable names won't help
- Don't use `sudo` on the lab machines
    - They yell at you and phone home to the sysadmins
- Want to install something? Email `ithelp@clmeson.edu` and put
    `School of Computing` in the subject line.


## The snapshot system

- Contents are in `~/.snapshot`
- Keeps hourly, nightly, and weekly backups of files in `~`
- Especially useful when you accidentally overwrite a project at 2 am

*** SNAPSHOTS ARE UNIQUE TO CLEMSON. DON'T RELY ON IT! ***


## Your Free Clemson Web Hosting

- Run `cd /web/home/username/public_html`
    - Trust us, it's there
- Files you put there will be served on the web at
    `people.cs.clemson.edu/~username/`
- Change permissions so the web server can access them
    - `chmod a+r [serving files]`
    - `chmod a+g [sub-directories]`



# Wrap up 


## Further resources

- [Cheetsheet](http://www.cs.clemson.edu/help/linux-workshop/soc_linux_cheatsheet.pdf) of commands
- Plug a long command into
    [ExplainShell.com](http://explainshell.com/) to see what it does
- We're on [Steam](http://steamcommunity.com/groups/clemsonacm) and freenode at `#clemsonacm`
- Admins work in the main hallway


## Questions

Send us feedback at `acm@cs.clemson.edu`!

This material available under [CC By-SA 4.0](http://creativecommons.org/licenses/by-sa/4.0/)

