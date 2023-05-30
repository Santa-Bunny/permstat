# designate which compiler to use
CXX			= g++

# list of sources used in project
SOURCES 	= $(wildcard *.cpp)
# list of objects used in project
OBJECTS		= $(SOURCES:%.cpp=%.o)

#Default Flags
CXXFLAGS = -std=c++14 -Wconversion -Wall -Werror -Wextra -pedantic 

EXECUTABLE = permstat

# make release - will compile "all" with $(CXXFLAGS) and the -O3 flag
#				 also defines NDEBUG so that asserts will not check
release: CXXFLAGS += -O3 -DNDEBUG
release: all

# make debug - will compile "all" with $(CXXFLAGS) and the -g flag
#              also defines DEBUG so that "#ifdef DEBUG /*...*/ #endif" works
debug: CXXFLAGS += -g3 -DDEBUG
debug: clean all

# make profile - will compile "all" with $(CXXFLAGS) and the -pg flag
profile: CXXFLAGS += -pg
profile: clean all

all: ${EXECUTABLE}

# Compile the pager and tag this compilation
${EXECUTABLE}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXECUTABLE}

# Generic rules for compiling a source file to an object file
%.o: %.cpp
	${CC} -c $<
%.o: %.cc
	${CC} -c $<

# make clean - remove .o files, executables
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

define MAKEFILE_HELP
Makefile Help
* Building permstat:
	- debug   : Makes permstat with -g3 and -DDEBUG Flags
	- release : Makes permstat with -o3 and -DNDEBUG Flags
	- profile : Makes permstat with -pg flag for gprof
endef
export MAKEFILE_HELP

help:
	@echo "$$MAKEFILE_HELP"

.PHONY: all release debug profile clean help
# disable built-in rules
.SUFFIXES: