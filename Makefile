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

all: ex1 ex3 ex5 ex6 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 ex16 ex17 ex18

clean:
	rm -f ex1 ex3 ex5 ex6 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 ex16 ex17 ex18

list:
	ls
