An Unnecessary Image Ratio Calculator
====================================================

You can either say the acronym ``U I R C`` or, as I've been doing, pronouncing it as ``work``.

What is this?
-------------

Well, it's an unnecessary image ratio calculator.

It takes an image as an argument in the form of a file on the local file system or a link to an image on a web server, and returns the ratio of the image. That's literally it.

Why does this exist? 
--------------------

The reason UIRC exists is actually the combination of two events:

1. I've recently started learning more and more about the C programming language, it's history, and how nice and flirty it gets with the actual machine (maybe even making your relationship more serious if you're a psychopath). It runs my OS (Linux) and my window manager (dwm). I use it every day, and it makes me want to learn more and what it can do. Ever since I've been looking for an excuse to make a C program of my own.
2. I was working at my on-campus job when I needed to know the ratio of an image. Being too lazy to do the math with the image's resolution and oddly hesitant to use a web tool (which I did eventually use), I switched to my terminal quickly to find the file I needed to see what the resolution was, and badda bing badda boom.

Born was my idea. I found an excuse to learn and code in C for an issue that is over-saturated with solutions everywhere.

Why should I use this?
----------------------

Don't. 

Or you could I guess, I won't stop you. There's just *way* more convenient (and possibly easier for the command-line-illiterate) ways to find the ratio of an image. This is just an idea that I had and the excuse to get me learning how to program in C.

I've made my decision. How do I install?
----------------------------------------

Ah, the UNIX community. Stubborn about always wanting to use command line tools over convenience. It just warms my heart.

In order to install, you must have ``make`` (installed on basically all \*nix systems) or another compatible tool installed. Then, simply run::

  $ make install
