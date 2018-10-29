PRG=gnu.exe
# web script will insert definition of PRG here 
# it will include student's login (security)
GCC=gcc #required for online testing
GCCFLAGS=-ansi -Wall -Wextra -pedantic -Werror

VALGRIND_OPTIONS=-q --leak-check=full
DIFF_OPTIONS=-y --strip-trailing-cr --suppress-common-lines

OSTYPE := $(shell uname)
ifeq ($(OSTYPE),Linux)
CYGWIN=
else
CYGWIN=-Wl,--enable-auto-import
endif

SUBMISSION0=invoice-gen.c

gcc0:
	$(GCC) $(SUBMISSION0) $(GCCFLAGS) $(CYGWIN) -o $(PRG) #PRG will be defined by web script
1 2 3 4 5 6:
	echo "running test$@"
	@echo "should run in less than 300 ms"
	./$(PRG) < in$@.txt >studentout
	diff out$@.txt studentout $(DIFF_OPTIONS) > difference$@	
clean:
	rm -f *.exe *.o *.obj *.tds *.exe.manifest student* difference*
