# Attempt at a somewhat automatic Makefile
# make init to create directories

CC := gcc
CFLAGS := -std=c99 -Wall -Wextra -fsanitize=address
LDFLAGS :=

FLAGS := $(CFLAGS)
LINKFLAGS := $(LDFLAGS)
DEBUGFLAGS := $(FLAGS) -g -O0 -DDEBUG
TESTFLAGS := $(FLAGS) -lcriterion

EXEC := main
TEST := test
SOURCEDIR := src
HEADERDIR := headers
OBJECTSDIR := obj

EXECOBJ := $(OBJECTSDIR)/$(EXEC).o
TESTOBJ := $(OBJECTSDIR)/$(TEST).o

SOURCES := $(shell find $(SOURCEDIR) -name '*.c' ! -name "$(TEST).c" ! -name "$(EXEC).c" 2>&1)
OBJECTS := $(patsubst $(SOURCEDIR)/%.c, $(OBJECTSDIR)/%.o, $(SOURCES))


.PHONY: all clean remake init
.DELETE_ON_ERROR:

all: $(EXEC)

$(EXEC): $(OBJECTSDIR)/$(OBJECTS) $(EXECOBJ)
	$(CC) $(FLAGS) -I$(HEADERDIR) -I$(SOURCEDIR) $(OBJECTS) $(EXECOBJ) $(LINKFLAGS) -o $(EXEC)

#$(OBJECTSDIR)/%.o: $(SOURCEDIR)/%.c
#	$(CC) $(FLAGS) -I$(HEADERDIR) -I$(SOURCEDIR) -c $< -o $@

test : $(TEST)

$(TEST): $(OBJECTSDIR)/$(OBJECTS) $(TESTOBJ)
	$(CC) $(TESTFLAGS) -I$(HEADERDIR) -I$(SOURCEDIR) $(OBJECTS) $(TESTOBJ) $(LINKFLAGS) -o $(TEST)

$(OBJECTSDIR)/%.o: $(SOURCEDIR)/%.c 
	$(CC) $(FLAGS) -I$(HEADERDIR) -I$(SOURCEDIR) -c $< -o $@

list:
	@echo $(SOURCES)
	@echo $(OBJECTS)
clean:
	$(RM) -r $(OBJECTSDIR)/* $(EXEC) $(TEST)

remake: clean all

init:
	@mkdir -p $(SOURCEDIR) $(HEADERDIR) $(OBJECTSDIR)
