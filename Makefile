TARGET=clang
TARGET_FILE_NAME=$(TARGET)$(shell python3-config --extension-suffix)

INCLUDES=$(shell python3-config --includes)
CXXFLAGS=-O3 -Wall -shared -std=c++11 -fPIC
LIB=-lclang_so -L/afs/csail.mit.edu/u/a/ajaybr/scratch/llvm-learnt/build/lib

all: $(TARGET_FILE_NAME)

$(TARGET_FILE_NAME): $(TARGET).cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< -o $@ $(LIB)


clean:
	rm -f $(TARGET_FILE_NAME)

