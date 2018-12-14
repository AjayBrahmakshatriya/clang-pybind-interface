TARGET=clang
TARGET_FILE_NAME=$(TARGET)$(shell python3-config --extension-suffix)

INCLUDES="-I/data/scratch/ajaybr/miniconda2/envs/ml-env/include/python3.7m -I/data/scratch/ajaybr/miniconda2/envs/ml-env/include/python3.7m"
INCLUDES="-I/afs/csail.mit.edu/u/a/ajaybr/scratch/pybind/pybind11/include"
INCLUDES=$(shell python3-config --includes)
CXXFLAGS=-O0 -Wall -shared -std=c++11 -fPIC -g
LIB=-lclang_so -L/afs/csail.mit.edu/u/a/ajaybr/scratch/llvm-learnt/build/lib

all: $(TARGET_FILE_NAME)

$(TARGET_FILE_NAME): $(TARGET).cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< -o $@ $(LIB)


clean:
	rm -f $(TARGET_FILE_NAME)

