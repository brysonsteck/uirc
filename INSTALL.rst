Installation
=============

To install ``uirc``, you need to have the following items:

* A C compiler (``uirc`` uses ``gcc`` by default, but you can change what compiler you use in the `config.mk file <config.mk>`_.)
* The cURL libraries
* The ``stb`` libraries

If you want to install all three at once, follow the instructions for your system below.

Debian/Debian-based (Ubuntu, Pop!_OS, etc.)
--------------------------------------
.. code:: bash

  $ sudo apt install git libcurl3-gnutls libstb-dev

RHEL-based (Fedora, CentOS, etc.)
----------------------------------
.. code:: bash

  $ sudo dnf install git 

OpenSUSE
---------
.. code:: bash

  $ sudo zypper install

Arch/Arch-based (Manjaro, EndeavourOS, etc.)
---------------------------------------------
.. code:: bash

  $ sudo pacman -S

FreeBSD/OpenBSD
----------------
.. code:: fish

  $ doas pkg_add
