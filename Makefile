no: no.c
	gcc -o no no.c

install: no
	sudo cp no /usr/bin

clean: no
	rm no

uninstall: no
	sudo rm -f no
	sudo rm -f /usr/bin/no
