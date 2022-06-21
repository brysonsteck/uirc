# install location
PREFIX = /usr/local
MAN_PREFIX = ${PREFIX}/share/man
LIB_PREFIX = ${PREFIX}/lib
INCLUDE_PREFIX = /usr/include
# comment the line above and uncomment the following line
# if you are building on macOS, otherwise it is optional
#INCLUDE_PREFIX = /usr/local/include

# additional compiler options
OPTIONS = -O2

# manual install location
MANPREFIX = ${PREFIX}/share/man

# compiler, default is gcc
# if you are on BSD, you might want to change this to cc unless you have gcc installed.
CC = gcc

# other options you want to add
# uncomment the following line if you are building on BSD
#OPTIONS = -L /usr/local/lib -I /usr/local/include
