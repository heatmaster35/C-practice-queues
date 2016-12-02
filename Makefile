############################
# Name: Leo Gomez          #
# CruzID: legomez          #
# Class: CMPS-12M          #
# Date: Nov 24, 2014       #
# filename: Makefile       #
# Details: file that builds#
#   and runs lab6 tests and#
#   files    		   #
############################

MKFILE    = Makefile
DEPSFILE  = ${MKFILE}.deps

GCC      = gcc -g -O0 -Wall -Wextra -std=gnu99
MKDEPS   = gcc -MM
GRIND    = valgrind --leak-check=full

CHEADER   = queue.h
CSOURCE   = queue.c main.c
OBJECTS   = ${CSOURCE:.c=.o}
EXECBIN   = queue
SOURCES   = ${CHEADER} ${CSOURCE} ${MKFILE}

all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${GCC} -o $@ ${OBJECTS}

%.o : %.c
	${GCC} -c $<

clean :
	rm -f ${OBJECTS} ${DEPSFILE} core test.lis

spotless : clean
	rm -f ${EXECBIN} ${LISTING:.ps=.p*} test.lis

test : ${EXECBIN}
	${GRIND} --log-file=test.log ./${EXECBIN}

deps : ${CSOURCE} ${CHEADER}
	@ echo "# ${DEPSFILE} created `date`" >${DEPSFILE}
	${MKDEPS} ${CSOURCE} >>${DEPSFILE}

${DEPSFILE} :
	@ touch ${DEPSFILE}
	${MAKE} --no-print-directory deps

include ${DEPSFILE}

.PHONY: all clean spotless test deps
