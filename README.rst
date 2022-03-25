An Unnecessary Image Ratio Calculator
====================================================

You can either say the acronym ``U I R C`` or, as I've been doing, pronouncing it as ``work``.

What is this?
-------------

Well, it's an unnecessary image ratio calculator.

It takes an image as an argument in the form of a file on the local file system or a link to an image on a web server, and returns the ratio of the image. That's literally it.

Perhaps I can give you some visual representation. Let's say you have an image of a neat little `background of an unrealistically oversaturated landscape <https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fwww.hdwallpapers.in%2Fdownload%2Fsunset_scenery-1920x1080.jpg&f=1&nofb=1>`_ and want to make sure it fully fits in your 16:9 monitor::

  $ uirc unrealistically-oversaturated-landscape.png
  unrealistically-oversaturated-landscape.png > 16:9

Neat! What about images that don't really play nice? Take this lovely image of Peter Griffin `here <https://upload.wikimedia.org/wikipedia/en/c/c2/Peter_Griffin.png>`_. Let's throw him into uirc::

  $ uirc peter.jpg
  peter.jpg > 1:1.45 (uneven)

Good to know! I can also give the ``-r`` flag to display the resolution if I so incline, or even find out the ratio of both images::

  $ uirc -r peter.jpg unrealistically-oversaturated-landscape.png
  peter.jpg > 1:1.45 (uneven) [247x359]
  unrealistically-oversaturated-landscape.png > 16:9 [1920x1080]

What if I don't want my wife to find a photo of Peter Griffin on my laptop? Well, you can use a link instead::

  $ uirc https://upload.wikimedia.org/wikipedia/en/c/c2/Peter_Griffin.png
  Peter_Griffin.png > 1:1.45 (uneven)
 
There's also a help menu with the ``-h`` flag if you really need it. 

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

Ah, the UNIX community. Stubborn about always wanting to use command line tools over convenience. It just warms my heart. Read the `INSTALL <INSTALL.rst>`_ file for instructions on how to install on your system.
