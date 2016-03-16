# Automation in the Classroom


## An introduction to Automation

Brought to you by Clemson ACM

### Speakers:

Robert Underwood - ACM Vice President



## Coming Up


- Why would you want to automate your work?
- What sorts of things can you automate?
- When is automation and scripting applicable?
- What tools should I use?
- Thinking bigger: a case study
- The dangers of automation



# Who are we?


## Clemson ACM

- Student Chapter of the ACM
- Host professional and social events for students
- Host the competitive programming team coached by Dr. Dean
- We want to make the School of Computing a better place



## Why would you want to automate your work?


## Instructor Perspective

- Saves you time grading for large classes
- Encourages students to submit early and often
- Encourages students to use an iterative approach
- Done correctly, reinforces Test Driven Development


## Student Perspective

- Same benefits as Test Driven Development
- Early feedback on how the project is progressing.
- Helps us determine when we have completed the project.
- Avoid missing stupid mistakes



## When is automation and scripting applicable?


## When is it applicable?

- Generating test data
- Grading programming projects
- Many repetitive tasks


## When is it not applicable?

- Where output is
 - difficult to parse
 - non-deterministic



## What Tools Should I Use for Automation?


## Tools to consider

- High level languages (bash, perl, python, ruby)
- `cron` - set it and forget it
- `hg` - source control back-end for Handin
- `time` - get running times
- `timeout` - enforce runtime limits


## bash

Great for gluing programs together

- `|` pipelining
- `&> dest` redirect stderr and stdout to dest
- `word` executes word in a subshell first
- support `for` and `while` loops
- even includes functions!
- `zsh`, `fish`


## Example bash script

```bash
for i in $(ls)
	do
	if [ "$i" != "prof" ]; then
		cd $i
		hg pull
		cd ..
	fi
done
```


## bats

Unit testing for CLI Applications

- Written in bash
- Ease to write
- Parse-able output
- Lightweight


## Sample Bats file

```bash
@test "Set example code matches Sample Output" {
	run ./set.exe < set.in
	[ "$status" -eq 0 ]
	[ "$output" = "$(cat set.out)" ]
}
```


## cron

Running jobs at fixed times

- On most modern Linux systems it is replaced by systemd
- `crontab -e` edit user crontab
- persistent crontab; system dependent location
- *warning* cron ignores *all* environment variables
- `anacron` and `systemd` timers


## Example crontab

    PATH=/usr/bin
    SHELL=/bin/bash
    MAILTO=acm
    # minute hour dayOfMonth month dayOfWeek cmd
    0 0 0 * * echo "Cron Example"


## hg

Source Control System

- Configure ssh access to avoid passwords
- `hg clone` clone a repository for the first time
- `hg incomming` see if there are updates without pulling them
- `hg pull -u` update to the latest submission


## time

Time how long it takes a program to execute

- `time tar -czf foobar`


## timeout

Kill a program after a timeout

- `timeout 10 ./script.sh`



## Examples of Automation


## Cloning Repositories

	hg clone ssh://handin@handin.cs.clemson.edu/semester_name/course_name 
	pushd course_name
	./update


## Testing a student's work

	#!/bin/bash
	TESTS=$PWD
	OUTPUT=$PWD/output
	pushd assignments/asg_name
	for dir in *
	do
		if [ -d "$dir" ];then
			mkdir -p $OUTPUT/"$dir"
			pushd $dir
			timeout 10 make > $OUTPUT/$dir/output-make.txt
			timeout 10 $TESTS/test1.sh &> $OUTPUT/$dir/output-1.txt
			timeout 10 $TESTS/test2.sh &> $OUTPUT/$dir/output-2.txt
			popd
		fi
	done


## Emailing Results

	#!/bin/bash
	mail -s 'Autograder Results' student@clemson.edu < results.txt


## Generating large datasets

	#!/usr/bin/env python3
	import random
	with open("testdata.in","w") as outfile:
		for i in range(100000):
			outfile.write(random.randint(0,100))

Then test with sample solution



## Thinking bigger: a Case Study


## What is it, and what does it do?

- Autograder used in CPSC 322
- Written in Python
- Downloads student submissions
- Can award partial credit
- Emails students their results


## How does it help students?

- Faster feedback


## How does it help Dr. Sorber?

- Saves time in grading
- Statistics regarding his experience


## How does it work?

- Downloads projects with `hg`
- Tests student code with `python`
- Emails results to students via `mail`
- Saves a json file with results for grade book



## The Costs of Automation

- Certain mess-ups can be *catastrophic*
	- Lost projects
	- Wrong grades
	- Accidental leaks
- Using a established framework can eliminate these problems
- Writing scripts will take time


## However you'll probably use it again

![](http://imgs.xkcd.com/comics/is_it_worth_the_time.png)

source: xkcd



## A Word on Security

- The risk isn't much higher
	-  Unless you currently carefully audit every line of code
- Tools such as systrace, containers, vms can improve security.
- Treat violations as Academic Integrity Issues.


## Wrap-Up


## Summary

- Automation can save time and effort
- Please consider automation


## Further Resources

- Additional command references:
  - UNIX `man` pages - most commands have a `man` page
  - [Grymoire][1] - great scripting resource
  - [Archwiki][2] - great command resource
- Dr. Sorber's [Auto-grader][3]
- [USACO][4], [OpenKatis][5]

[1]: http://www.grymoire.com/
[2]: https://wiki.archlinux.org/index.php/Main_Page
[3]: http://buffet.cs.clemson.edu
[4]: http://www.usaco.org/
[5]: https://open.kattis.com/


## Questions

Send us feedback at `acm@cs.clemson.edu`!

This material available under [CC By-SA 4.0](http://creativecommons.org/licenses/by-sa/4.0/)
