# Set the shell.
SHELL=/usr/bin/env bash

# Include the configuration
-include Makefile.inc

# Rules without physical targets (secondary expansion for specific rules).
.SECONDEXPANSION:
.PHONY: all clean ErrorHandler StrTools IOTools Box Time Table

.SILENT:

all: ErrorHandler StrTools IOTools Box Time Table
	@echo "All done"

ErrorHandler: $(CPP_TOOLS_BUILD_DIR)/libErrorHandler.so
StrTools: $(CPP_TOOLS_BUILD_DIR)/libStrTools.so
IOTools: $(CPP_TOOLS_BUILD_DIR)/libIOTools.so
Box: $(CPP_TOOLS_BUILD_DIR)/libBox.so
Table: $(CPP_TOOLS_BUILD_DIR)/libTable.so
Time: $(CPP_TOOLS_BUILD_DIR)/libTime.so

$(CPP_TOOLS_BUILD_DIR): 
	mkdir -p $@

$(CPP_TOOLS_BUILD_DIR)/ErrorHandler.o: $(CPP_TOOLS_SRC_DIR)/ErrorHandler.cpp | $(CPP_TOOLS_BUILD_DIR)
	@echo Building CXX object $@
	$(CXX) $< $(CXX_COMMON_LIB) -o $@

$(CPP_TOOLS_BUILD_DIR)/StrTools.o: $(CPP_TOOLS_SRC_DIR)/StrTools.cpp | $(CPP_TOOLS_BUILD_DIR)
	@echo Building CXX object $@
	$(CXX) $< $(CXX_COMMON_LIB) -o $@

$(CPP_TOOLS_BUILD_DIR)/IOTools.o: $(CPP_TOOLS_SRC_DIR)/IOTools.cpp | ErrorHandler StrTools
	@echo Building CXX object $@
	$(CXX) $< $(CXX_COMMON_LIB) $(CPP_TOOLS_INCLUDE) -o $@ \
	-L./$(CPP_TOOLS_BUILD_DIR) -Wl,-rpath,./$(CPP_TOOLS_BUILD_DIR) -lErrorHandler -lStrTools

$(CPP_TOOLS_BUILD_DIR)/Box.o: $(CPP_TOOLS_SRC_DIR)/Box.cpp | IOTools
	@echo Building CXX object $@
	$(CXX) $< $(CXX_COMMON_LIB) $(CPP_TOOLS_INCLUDE) -o $@ \
	-L./$(CPP_TOOLS_BUILD_DIR) -Wl,-rpath,./$(CPP_TOOLS_BUILD_DIR) -lErrorHandler -lStrTools -lIOTools

$(CPP_TOOLS_BUILD_DIR)/Table.o: $(CPP_TOOLS_SRC_DIR)/Table.cpp | IOTools
	@echo Building CXX object $@
	$(CXX) $< $(CXX_COMMON_LIB) $(CPP_TOOLS_INCLUDE) -o $@ \
	-L./$(CPP_TOOLS_BUILD_DIR) -Wl,-rpath,./$(CPP_TOOLS_BUILD_DIR) -lErrorHandler -lIOTools

$(CPP_TOOLS_BUILD_DIR)/$(CPP_TOOLS_BUILD_DIR)%.so: $(CPP_TOOLS_BUILD_DIR)/%.o
	@echo Building CXX shared library $@
	$(CXX) -shared -o $@ $<

$(CPP_TOOLS_BUILD_DIR)/Time.o: $(CPP_TOOLS_SRC_DIR)/Time.cpp | $(CPP_TOOLS_BUILD_DIR)
	@echo Building CXX object $@
	$(CXX) $< $(CXX_COMMON_LIB) -o $@

$(CPP_TOOLS_BUILD_DIR)/lib%.so: $(CPP_TOOLS_BUILD_DIR)/%.o
	@echo Building CXX shared library $@
	$(CXX) -shared -o $@ $<

clean: 
	@echo Cleaning
	rm -rf $(CPP_TOOLS_BUILD_DIR)/*.so $(CPP_TOOLS_BUILD_DIR)/*.o
