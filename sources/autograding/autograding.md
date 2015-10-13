# Automation in the Classroom


## An introduction to Automation

Brought to you by Clemson ACM.

### Speakers:

Robert Underwood - ACM Vice President

Austin Anderson - ACM President



## Coming Up

1. Who are we?
2. Why use automation in the class room?
3. How can I automate in the class room?
4. Tools for Automation?
5. Case study in Automation



## Who are we?


## Clemson ACM

- Student Chapter of the ACM
- Host professional and social events for students
- We want to make the School of Computing a better place



## Why use automation in the classroom?


## Instructor Perspective

- Saves you time grading for large classes
- Encourages students to submit early and often
- Encourages students to use an iterative approach
- Reinforces Test Driven Development


## Student Perspective

- Same benefits as Test Driven Development
- Early feedback on how the project is progressing.
- Helps us determine when we have completed the project.



## How can I automate in the class room?

- Generating test data
- Grading programming projects
- Many repetitive tasks



## Tools for Automation


## awk

Pattern scanning and processing

- `BEGIN {action}` executes before processing
- `pattern {action}` default pattern style
- `END {action}` executes after the file is processed
- patterns are based on `re_format`
- missing patterns always match, missing actions always print
- `perl`, `python`, `ruby`


## Example awk Script

```awk
#computes the average of space delimited data
#where the second column is even
BEGIN {n = 0}
$2%2 == 0 {s += $1; n++}
END {print "sum is", s, " average is", s/n}
```


## sed

Command line text manipulation

- `sed 's/hello/goodbye/g [file]'` replaces "hello" with "goodbye"
    - Prints to stdout, redirect it!
- `sed /bad/d` deletes lines containing "bad"
- `sed 1d;$d` deletes first and last line
- Can use `/regexes/` or other rules, check `man sed`


## bash

Gluing programs together

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
	cd $i
	git pull
	cd ..
done
```


## bats

Unit testing for CLI Applications

- Simple way to test output and return values
- Parsable output
- Lightweight


## Sample Bats file

```bash
@test "Set example code matches Sample Output" {
	run ./set.exe
	[ "$status" -eq 0 ]
	[ "$output" = "$(cat set.in)" ]
}
```


## grep

Find pattern in a text

- uses `re_format` style regex
- `-C3` print 3 lines of context around match
- `-c` print number of matches
- `-e` specify multiple patterns
- `-r` recursively search
- `--exclude` ignore file paths
- `ack` and `ag`


## valgrind

A debugger that detects memory leaks and other profiling + `gdb`

        valgrind --leak-check=yes program-name
        valgrind --tool=callgrind program-name
        valgrind --tool=cachegrind program-name


## cron

Running jobs at fixed times

- Probably the least standardized tool on this list
- On most modern Linux boxes replaced by systemd
- `crontab -e` edit user crontab
- persistent crontab; system dependent location
- *warning* cron ignores *all* environment variables
- `anacron` and `systemd` timers



## Case study in Automation


## Introduction

- Auto-grader designed by Dr. Sorber
- Mix of python and bash
- Downloads student submissions
- Can award partial credit
- Emails students their results


## Deploying the Auto-grader

- Walk through the steps of creating cronjob etc


## Writing a grading module

- Include some steps on writing modules


## Outcomes of the Auto-grader

- Include stats before and after auto-grader



## Wrap-Up


## Summary

- Automation can save time and effort
- Please consider automation


## Further Resources

- Addional command references:
  - UNIX `man` pages - most commands have a `man` page
  - [Grymoire][1] - great scripting resource
  - [Archwiki][2] - great command resource
- Dr. Sorber's [Auto-grader][3]

[1]: http://www.grymoire.com/
[2]: https://wiki.archlinux.org/index.php/Main_Page
[3]: http://buffet.cs.clemson.edu


## Questions

Send us feedback at `acm@cs.clemson.edu`!

This material available under [CC By-SA 4.0](http://creativecommons.org/licenses/by-sa/4.0/)
