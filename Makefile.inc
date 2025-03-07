CXX=g++
CXX_COMMON_LIB=-Wall -Werror -Wpedantic -pipe -O2 -fPIC -c

CPP_TOOLS_SRC_DIR=src
CPP_TOOLS_INCLUDE=-I./include
CPP_TOOLS_BUILD_DIR=build
CPP_TOOLS_LIB=-L $(CPP_TOOLS_LIB_DIR) -Wl,-rpath,$(CPP_TOOLS_LIB_DIR) -lBox -lTime -lTable -lIOTools -lStrTools -lErrorHandler 
