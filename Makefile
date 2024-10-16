# Set the shell.
SHELL=/usr/bin/env bash

# Include the configuration
-include Makefile.inc

_mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
I := $(patsubst %/,%,$(dir $(_mkfile_path)))

ifneq ($(words $(MAKECMDGOALS)),1)
.DEFAULT_GOAL = all
%:
	@$(MAKE) $@ --no-print-directory -rRf $(firstword $(MAKEFILE_LIST))
else
ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
     -nrRf $(firstword $(MAKEFILE_LIST)) \
     ECHO="COUNTTHIS" | grep -c "COUNTTHIS")
N := x
C = $(words $N)$(eval N := x $N)
ECHO = python3 $(I)/makefile_progress.py --stepno=$C --nsteps=$T
endif

# Rules without physical targets (secondary expansion for specific rules).
.SECONDEXPANSION:
.PHONY: all clean ErrorHandler StrTools IOTools Box

.SILENT:

all: ErrorHandler StrTools IOTools Box
	@echo "All done"

ErrorHandler: lib/ErrorHandler.o lib/ErrorHandler.so lib/libErrorHandler.a
StrTools: lib/StrTools.o lib/StrTools.so lib/libStrTools.a
IOTools: lib/IOTools.o lib/IOTools.so lib/libIOTools.a
Box: lib/Box.o lib/Box.so lib/libBox.a

lib: 
	mkdir -p $@

lib/ErrorHandler.o: src/ErrorHandler.cpp | lib
	@$(ECHO) Building CXX object $@
	$(CXX) $< $(CXX_COMMON_LIB) -o $@

lib/StrTools.o: src/StrTools.cpp | lib
	@$(ECHO) Building CXX object $@
	$(CXX) $< $(CXX_COMMON_LIB) -o $@

lib/IOTools.o: src/IOTools.cpp \
					lib/ErrorHandler.o \
					lib/StrTools.o
	@$(ECHO) Building CXX object $@
	$(CXX) $< $(CXX_COMMON_LIB) -I./include -o $@ \
	-L lib -lErrorHandler -lStrTools

lib/Box.o: src/Box.cpp lib/IOTools.o
	@$(ECHO) Building CXX object $@
	$(CXX) $< $(CXX_COMMON_LIB) -I./include -o $@ \
	-L lib -lErrorHandler -lStrTools -lIOTools

lib/%.so: lib/%.o
	@$(ECHO) Building CXX shared library $@
	$(CXX) -shared -o $@ $<

lib/lib%.a: lib/%.o
	@$(ECHO) Building CXX static library $@
	ar rcs $@ $<

clean: 
	@echo Cleaning
	rm -rf lib

endif
