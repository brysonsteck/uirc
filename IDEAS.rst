************
Feature list
************

* Return ratios from all popular image types
  * JPG
  * PNG
  * BMP
  * etc.
* Allow image input from multiple sources, such as an image...
  * On the local file system
  * From a HTTP or HTTPS web server
    * Using programs such as ``wget`` or using some random C library

# Possible help message
::

  uirc: an unecessary image ratio calculator
  pronounced 'u.i.r.c.' or 'work', does not matter

  Copyright 2022 Bryson Steck
  Licensed under the GNU General Public License Version 2

  usage: uirc [-uhlr] IMAGE1 [IMAGE2] [...]

  Options:
    -u  --url         > Mark images as urls.
                        >> This will cause uirc to make HTTP/HTTPS requests for all the arguments specified instead of using local files. 
                        >> Links must start with 'http://' or 'https://' before uirc makes any GET requests.
    -r  --resolution  > Display the resolution of the image
    -h  --help        > Display this message and exit.
    -l  --license     > Open the license for uirc

  Help:
    If you get stuck using uirc, you can read the manpage.

    'man uirc'

Potential output for example commands
#####################################

::

  $ uirc cool-image.png
  3:2
::

  $ uirc one-image.jpg two-image.png red-image.bmp blue-image.jpeg
  one-image.jpg > 16:9
  two-image.png > 5:4
  red-image.bmp > 4:3
  blue-image.jpeg > 1.24:1
::

  $ uirc -r 'file with spaces.png'
  2:3 (2000x3000)
::

  $ uirc -u https://brysonsteck.net/peter_griffin.png
  GET https://brysonsteck.net/peter_griffin.png
  HTTP request returned 200 (OK)
  Downloading...done

  9:16
