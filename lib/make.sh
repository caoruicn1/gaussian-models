#!/bin/bash
cd $(dirname "$0")
CC=g++
OS=`uname`
FLAGS="-std=c++11 -fopenmp -Ofast"
if [ $OS == "Linux" ]; then
  CC="nvcc"
  FLAGS="-std=c++11 -O3 -lblas -lcublas -Xcompiler -fopenmp"
fi
if command -v clang-format >/dev/null 2>&1; then
  echo "Linting..."
  clang-format -i *.cpp *.hpp *.cu
fi
echo "Compiling..."
if [ $OS == "Darwin" ]; then
  CC="/usr/local/opt/llvm/bin/clang++"
  FLAGS="$FLAGS -framework Accelerate -framework OpenCL -lclBLAS -L/usr/local/opt/llvm/lib -Wl,-rpath,/usr/local/opt/llvm/lib -I/usr/local/opt/llvm/include"
fi
echo "... using $CC."
rm *.out
$CC $FLAGS -c $(find . -name \*.cpp) -lm
if [ $OS == "Linux" ]; then
  $CC $FLAGS -c $(find . -name \*.cu) -lm
fi
#if [ $OS == "Darwin" ]; then
#  rm benchmark-native.o
#fi
echo "Building..."

$CC $FLAGS $(find . -name \*.o -not -name demo_cv.o -not -name demo.o -not -name k2.o) -o test.out -lm
$CC $FLAGS $(find . -name \*.o -not -name test.o -not -name demo.o -not -name k2.o) -o demo_cv.out -lm
$CC $FLAGS $(find . -name \*.o -not -name demo_cv.o -not -name test.o -not -name k2.o) -o demo.out -lm
$CC $FLAGS $(find . -name \*.o -not -name demo_cv.o -not -name test.o -not -name demo.o) -o k2.out -lm
rm $(find . -name \*.o)
