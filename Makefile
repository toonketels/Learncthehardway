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

all: ex1 ex3 ex5 ex6 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 ex16 ex17 ex18 ex20 ex22_main ex23

ex22_main: ex22.o

clean:
	rm -f ex1 ex3 ex5 ex6 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 ex16 ex17 ex18 ex20 ex22_main ex22.o ex23

list:
	ls
