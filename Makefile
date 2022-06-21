# makefile for uirc
# to configure install locations and compiler settings, see config.mk
include config.mk

SRC = uirc.c

uirc: ${SRC}
	${CC} ${OPTIONS} -o uirc ${SRC} -lcurl -lm 

debug: uirc
	${CC} -g ${OPTIONS} -o d_uirc -O3 ${SRC} -lcurl -lm 
	gdb d_uirc
	rm d_uirc

clean:
	rm ./uirc

install: uirc
	mkdir -p ${PREFIX}/bin
	cp -f uirc ${PREFIX}/bin
	chmod 755 ${PREFIX}/bin/uirc
	mkdir -p ${MAN_PREFIX}/man1
	cp -f uirc.1 ${MAN_PREFIX}/man1

uninstall:
	rm ${PREFIX}/bin/uirc
	rm ${MAN_PREFIX}/man1/uirc.1

stb:
	@echo "It is best to download the stb library from your system's package manager."
	@echo "Press ENTER to manually install the stb headers needed instead. Otherwise, quit with ^C"
	@read
	mkdir -p ${INCLUDE_PREFIX}/stb
	wget https://raw.githubusercontent.com/nothings/stb/master/stb_image.h -P ${INCLUDE_PREFIX}/stb

.PHONY: uirc clean install uninstall stb
