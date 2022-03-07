# makefile for uirc
SRC = uirc.c

uirc: ${SRC}
	gcc -o uirc -O ${SRC}

