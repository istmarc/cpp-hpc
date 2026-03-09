# C++ for high perfomance computing

Examples of using modern C++ for high performance computing.

## Examples

- [Newton's method for computing the square root](0_hello_world/newton.cpp)

- [vector class](1_vector/Vector.hpp)

- [Matrix class](2_matrix/Matrix.hpp)

- [Timer class](3_timer/Timer.hpp)

- [Threads](4_threads/TestThreads.cpp)

- [Multithreading](4_threads/TestMultithreading.cpp)

- [Concurrency](4_threads/TestConcurrent.cpp)

- [Sequential numerical quadrature](4_threads/NumericalQuadratureSeq.cpp)

- [Numerical quadrature in parallel](4_threads/NumericalQuadratureParallel.cpp)

## Benchamrks

- Matrix multiplication

![Benchmarks for matrix multiplication](3_timer/bench.png)

## Run the examples

```shell
clang++/g++ -std=c++23 example.cpp
```

## Ressources used
- [AMATH 483/583: High-Performance Scientific Computing](https://amath583.github.io/sp21/index.html)

