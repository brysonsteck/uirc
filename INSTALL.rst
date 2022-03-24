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

  $ doas pkg_add git curl
  # in BSD, you must install the 'stb' library manually from GitHub.
  # in order to do this, make sure wget is installed with:
  $ doas pkg_add wget
  # then, clone the repository and install the 'stb' library:
  $ git clone https://github.com/brysonsteck/uirc && cd uirc
  $ doas make stb

To build ``uirc`` on BSD, you need to uncomment the OPTIONS line at the bottom of the `config.mk <config.mk>`_ file. Additionally, if you would rather use ``cc`` instead of ``gcc``, you can change that in this file as well. Then, you can continue with the instructions.

.. code:: bash

  # build uirc with:
  $ make
  # or, if you want to install globally, use:
  $ doas make install
