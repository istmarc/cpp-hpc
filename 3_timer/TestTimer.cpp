#include "../2_matrix/Matrix.hpp"
#include "Timer.hpp"
#include <fstream>
#include <functional>
#include <iostream>
#include <stdexcept>

double benchmark(size_t M, size_t N, size_t K, size_t NumRuns,
                 std::function<void(const Matrix<double> &,
                                    const Matrix<double> &, Matrix<double> &)>
                     f) {
  Matrix<double> a(M, K);
  Matrix<double> b(K, N);
  Matrix<double> c(M, N);

  Timer t;
  t.start();
  for (size_t i = 0; i < NumRuns; i++) {
    f(a, b, c);
  }
  t.stop();
  return t.elapased() / (double)NumRuns;
}

int main() {
  std::ofstream file("bench.csv");
  if (!file.is_open()) {
    throw std::runtime_error("Error opening file");
  }
  file << "size;reference;hoisted;register_blocked;tiled\n";
  std::cout << "size reference hoisted register_blocked tiled\n";
  for (size_t N = 16; N <= 1024; N *= 2) {
    double ref = benchmark(N, N, N, 3, reference_matmul<double>);
    double hoisted = benchmark(N, N, N, 3, hoisted_matmul<double>);
    double blocked = benchmark(N, N, N, 3, blocked_matmul<double>);
    double tiled = benchmark(N, N, N, 3, tiled_matmul<double>);
    file << N << ";" << ref << ";" << hoisted << ";" << blocked << ";" << tiled << "\n";
    std::cout << N << " " << ref << " " << hoisted << " " << blocked << " " << tiled << "\n";
  }
}
