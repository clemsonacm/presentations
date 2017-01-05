## Writing Semantic Code

### Using refactoring and patterns for better code

Robert Underwood


## Overview

1.	What is bad code?
2.	What we can do about it
3.	Get practical
4.	Further Resources


## Who is this for?

1.	Intermediate to advanced talk
2.	Experienced with imperative languages
3.	Want to write better code


## Bad code is a problem

+	Bad code takes longer to:
	1.	Understand
	2.	Edit
	3.	Get right


## What is bad code?

+	We know it when we see it
	+	But we can be more precise <!-- .element class="fragment" data-fragment-index="1" -->
	+	Often called "code smells" or "spaghetti code"<!-- .element class="fragment" data-fragment-index="1" -->


## Codes Smells

<p class="fragment current-visible" data-fragment-index="1">From Martin Fowler's Refactoring</p>
<div class="fragment" style="float: left;" data-fragment-index="1">
	<ol>
		<li>Duplicate Code</li>
		<li>Long Methods</li>
		<li>Long Parameter Lists</li>
		<li>Data Clumps</li>
		<li>Primitive Obsession</li>
	<ol>
</div>
<div class="fragment" style="float: right;" data-fragment-index="1">
	<ol start="6">
		<li>Speculative Generality</li>
		<li>Incomplete Library</li>
		<li>Heavy Comments</li>
		<li class="fragment" data-fragment-index="2" >Magic Values</li>
		<li class="fragment" data-fragment-index="2" >Pyramid of Death</li>
	<ol>
</div>


## How do we fix it?

1.	Do it right the first time <!-- .element:  class="fragment"-->
2.	Style Guides <!-- .element:  class="fragment"-->
3.	Code Review/Testing <!-- .element:  class="fragment"-->
4.	Rewrite <!-- .element:  class="fragment"-->
5.	Refactor <!-- .element:  class="fragment"-->


## What is Refactoring?

> Refactoring is the process of changing a software system in such a way that it does not alter the
> external behavior of the code yet improves its internal structure.

Martin Fowler

"Refactoring: Improving the Design of Existing Code"


## What do we refactor to?

+	Code that:
	1.	Is more readable
	2.	Provides new features
	3.	Builds on design knowledge


## Let's Get Practical

And go to some case studies



## Further Resources

+   Martin Fowler
	+   [Refactoring: Improving the Design of Existing Code](refactoring.com)
	+   [Personal Site](martinfowler.com)
+	[Design Patterns](https://en.wikipedia.org/wiki/Design_Patterns) by the Gang of Four 
+	[Refactoring to Patterns](https://www.industriallogic.com/xp/refactoring/) by Joshua Kerievsky
+	[Functional Programming](http://fsharpforfunandprofit.com/fppatterns/) by Scott Wlaschin


## Tooling to make it easier

+   LLVM's libtooling (C/C++)
+   Eclipse and Eclim (Java et al)
+   Pycharm, Rope, et al (Python)


## Questions

Send feedback to <robertu@clemson.edu>

This material available under [CC By-SA 4.0](http://creativecommons.org/licenses/by-sa/4.0/)
