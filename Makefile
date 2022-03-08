# makefile for uirc
# to configure install locations and compiler settings, see config.mk
include config.mk

SRC = uirc.c

uirc: ${SRC}
	${CC} -o uirc -O ${SRC}

install: uirc
	mkdir -p ${PREFIX}/bin
	cp -f uirc ${PREFIX}/bin
	chmod 755 ${PREFIX}/bin/uirc

.PHONY: uirc install

