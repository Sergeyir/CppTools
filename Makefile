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
.PHONY: all clean ErrorHandler StrTools IOTools Box Time Table

.SILENT:

all: ErrorHandler StrTools IOTools Box Time Table
	@echo "All done"

ErrorHandler: $(CPP_TOOLS_LIB_DIR)/libErrorHandler.so
StrTools: $(CPP_TOOLS_LIB_DIR)/libStrTools.so
IOTools: $(CPP_TOOLS_LIB_DIR)/libIOTools.so
Box: $(CPP_TOOLS_LIB_DIR)/libBox.so
Table: $(CPP_TOOLS_LIB_DIR)/libTable.so
Time: $(CPP_TOOLS_LIB_DIR)/libTime.so

$(CPP_TOOLS_LIB_DIR): 
	mkdir -p $@

$(CPP_TOOLS_LIB_DIR)/ErrorHandler.o: $(CPP_TOOLS_SRC_DIR)/ErrorHandler.cpp | $(CPP_TOOLS_LIB_DIR)
	@$(ECHO) Building CXX object $@
	$(CXX) $< $(CXX_COMMON_LIB) -o $@

$(CPP_TOOLS_LIB_DIR)/StrTools.o: $(CPP_TOOLS_SRC_DIR)/StrTools.cpp | $(CPP_TOOLS_LIB_DIR)
	@$(ECHO) Building CXX object $@
	$(CXX) $< $(CXX_COMMON_LIB) -o $@

$(CPP_TOOLS_LIB_DIR)/IOTools.o: $(CPP_TOOLS_SRC_DIR)/IOTools.cpp | ErrorHandler StrTools
	@$(ECHO) Building CXX object $@
	$(CXX) $< $(CXX_COMMON_LIB) $(CPP_TOOLS_INCLUDE) -o $@ \
	-L./$(CPP_TOOLS_LIB_DIR) -Wl,-rpath,./$(CPP_TOOLS_LIB_DIR) -lErrorHandler -lStrTools

$(CPP_TOOLS_LIB_DIR)/Box.o: $(CPP_TOOLS_SRC_DIR)/Box.cpp | IOTools
	@$(ECHO) Building CXX object $@
	$(CXX) $< $(CXX_COMMON_LIB) $(CPP_TOOLS_INCLUDE) -o $@ \
	-L./$(CPP_TOOLS_LIB_DIR) -Wl,-rpath,./$(CPP_TOOLS_LIB_DIR) -lErrorHandler -lStrTools -lIOTools

$(CPP_TOOLS_LIB_DIR)/Table.o: $(CPP_TOOLS_SRC_DIR)/Table.cpp | IOTools
	@$(ECHO) Building CXX object $@
	$(CXX) $< $(CXX_COMMON_LIB) $(CPP_TOOLS_INCLUDE) -o $@ \
	-L./$(CPP_TOOLS_LIB_DIR) -Wl,-rpath,./$(CPP_TOOLS_LIB_DIR) -lErrorHandler -lIOTools

$(CPP_TOOLS_LIB_DIR)/$(CPP_TOOLS_LIB_DIR)%.so: $(CPP_TOOLS_LIB_DIR)/%.o
	@$(ECHO) Building CXX shared library $@
	$(CXX) -shared -o $@ $<

$(CPP_TOOLS_LIB_DIR)/Time.o: $(CPP_TOOLS_SRC_DIR)/Time.cpp | $(CPP_TOOLS_LIB_DIR)
	@$(ECHO) Building CXX object $@
	$(CXX) $< $(CXX_COMMON_LIB) -o $@

clean: 
	@echo Cleaning
	rm -rf $(CPP_TOOLS_LIB_DIR)

endif
