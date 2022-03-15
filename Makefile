# makefile for uirc
# to configure install locations and compiler settings, see config.mk
include config.mk

SRC = uirc.c

uirc: ${SRC}
	${CC} -DLICENSE_DIR='"./"' -o uirc -O ${SRC}

install: uirc
	mkdir -p ${PREFIX}
	cp -f uirc ${PREFIX}
	chmod 755 ${PREFIX}/uirc
	mkdir -p ${LIB_PREFIX}/uirc
	cp -f LICENSE ${LIB_PREFIX}/uirc

uninstall:
	rm ${PREFIX}/uirc
	rm -r ${LIB_PREFIX}/uirc
	test -s ${INCLUDE_PREFIX}/uirc || rm -r ${INCLUDE_PREFIX}/uirc

stb:
	@echo "It is best to download the stb library from your system's package manager."
	@echo "Press ENTER to manually install the stb headers needed instead. Otherwise, quit with ^C"
	@read
	mkdir -p ${INCLUDE_PREFIX}/stb
	wget https://raw.githubusercontent.com/nothings/stb/master/stb_image.h -P /usr/include/stb/stb_image.h

.PHONY: uirc install stb
