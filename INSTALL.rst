Installation
*************

Instructions are available for the following operating systems:

* `Linux/BSD <#linuxbsd>`_
* `macOS <#macos>`_
* `Windows <#windows>`_

Linux/BSD
==========

To install ``uirc``, you need to have the following items:

* Git (obviously) 
* A C compiler (``uirc`` uses ``gcc`` by default, but you can change what compiler you use in the `config.mk file <config.mk>`_.)
* The cURL libraries
* The ``stb`` libraries

If you want to install all four at once, follow the instructions for your system below.

Debian/Debian-based (Ubuntu, Pop!_OS, etc.)
--------------------------------------
.. code:: bash

  $ sudo apt install git gcc libcurl3-gnutls libstb-dev
  $ git clone https://github.com/brysonsteck/uirc && cd uirc
  # build uirc with:
  $ make
  # or, if you want to install globally, use:
  $ sudo make install

RHEL-based (Fedora, CentOS, etc.)
----------------------------------
.. code:: bash

  $ sudo dnf install git gcc libcurl-devel stb-devel
  $ git clone https://github.com/brysonsteck/uirc && cd uirc
  # build uirc with:
  $ make
  # or, if you want to install globally, use:
  $ sudo make install

OpenSUSE
---------
.. code:: bash

  $ sudo zypper install git gcc libcurl-devel stb-devel
  $ git clone https://github.com/brysonsteck/uirc && cd uirc
  # build uirc with:
  $ make
  # or, if you want to install globally, use:
  $ sudo make install

Arch/Arch-based (Manjaro, EndeavourOS, etc.)
---------------------------------------------
.. code:: bash

  # 'stb' is an AUR package and must be installed with an AUR helper, such as 'yay'.
  $ yay -S git gcc libcurl-gnutls stb
  $ git clone https://github.com/brysonsteck/uirc && cd uirc
  # build uirc with:
  $ make
  # or, if you want to install globally, use:
  $ sudo make install

FreeBSD/OpenBSD
----------------
.. code:: bash

  $ doas pkg_add git curl wget
  $ git clone https://github.com/brysonsteck/uirc && cd uirc
  # in BSD, you must install the 'stb' library manually from GitHub. do this with:
  $ doas make stb

To build ``uirc`` on BSD, you need to uncomment the OPTIONS line at the bottom of the `config.mk <config.mk>`_ file. Additionally, if you would rather use ``cc`` instead of ``gcc``, you can change that in this file as well. Then, you can continue with the instructions.

.. code:: bash

  # build uirc with:
  $ make
  # or, if you want to install globally, use:
  $ doas make install

Other Linux/UNIX-based systems
-------------------------------
If you fit this category, you probably know what you need to build ``uirc``.

macOS
======

To build ``uirc`` on macOS, make sure `brew <https://brew.sh>`_ and the Xcode Command Line tools (run ``xcode-select --install`` to make sure) are installed, then follow the instructions below.

.. code:: bash

  % brew install curl wget
  % git clone https://github.com/brysonsteck/uirc && cd uirc

You will also need to uncomment the INCLUDE_PREFIX line at the top of the `config.mk <config.mk>`_ file to make sure that the stb library is downloaded correctly.

.. code:: bash

  # in macOS, you must install the 'stb' library manually from GitHub. do this with:
  % make stb
  # build uirc with:
  % make
  # or, if you want to install globally, use:
  % make install

Windows
========

To build on Windows, you need to install a Linux distribution through WSL. This can be done with the following command in Command Prompt::

  >wsl --install

Once installed and you set up your user account, run ``sudo apt update && sudo apt upgrade`` and confirm to install the updates. Let it sit here, this might take a while.

Once you have updated your WSL instance, read the `Linux <#linuxbsd>`_ section above, following instructions for your WSL distribution (if you followed this guide to install, you will be following instructions for Debian).
