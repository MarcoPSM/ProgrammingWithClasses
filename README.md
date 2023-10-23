# Programming with Classes

* Practice object-oriented programming with C++

## Requirements

* Requires googletest library
  * cd lib/
  * wget <https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip>
  * unzip v1.13.0.zip
  * mv googletest-1.13.0 googletest

## Acknowledgements

* Project based on this book:
  * Programação com Classes em C++ 3ªed FCA

## Compile & Run

* mkdir build && cd build
* cmake ..
* make
* ./src/ProgramacaoComClasses_run

For clang

* rm -rf build
* mkdir build && cd build
* cmake -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang ../
* make
* ./src/ProgramacaoComClasses_run
