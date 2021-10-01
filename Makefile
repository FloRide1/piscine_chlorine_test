CC = gcc
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
EXE = a.out
LIBS = -lcriterion

CFLAGS = -Werror -Wall -Wextra -std=c99 -pedantic
LDFLAGS = -o $(EXE) $(LIBS)

# Compile and Assemble C Source Files into Object Files
%.o: %.c
	$(CC) -c $(CFLAGS) $*.c

# Link all Object Files with external Libraries into Binaries
$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS)

# Create a gdb/dbx Capable Executable with DEBUG flags turned on
#debug:
#	$(CC) $(CFDEBUG) $(SRC)

# Remove all useless include /!\ NOT SAFE RECOMPILE AFTER FOR SAFETY /!\ 
.PHONY: clean_include
clean_include:
	cp -f ../kill_clude.sh .
	sh kill_clude.sh *.c *.h
	rm -f ./kill_clude.sh

# Clean Up Objects, Exectuables, Dumps out of source directory
.PHONY: clean
clean:
	$(RM) $(OBJS) $(EXE) core a.out 

# Use the clang-format on all your files
.PHONY: format
format:
	find . -name "*.h" -o -name "*.c" | xargs clang-format -i


.PHONY: commit
commit: clean format
	git add .
