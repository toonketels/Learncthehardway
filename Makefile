CFLAG=-Wall -g

# Info:
# http://la-samhna.de/library/compile/makefile.html
#
# Common to have targets in makefile for
#   all
#   intall
#   uninstall
#   clean
#   distclean

all: ex1 ex3 ex5 ex6

clean:
	rm -f ex1 ex3 ex5 ex6

list:
	ls
