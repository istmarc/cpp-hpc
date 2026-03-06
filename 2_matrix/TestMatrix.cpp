#include <chrono>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "Matrix.hpp"

int main() {
   std::ofstream file("bench.csv");
   if (!file.is_open()) {
      throw std::runtime_error("Can't open file.");
   }
   file << "size;reference;hoisted;register_blocked\n";

   using mat = Matrix<double>;
   for (size_t N = 16; N <= 1024; N*=2) {
      std::cout << "Matmul for size = " << N << std::endl;
      mat a(N, N, 1.);
      mat b(N, N, 1.);
      mat c(N, N, 1.);
      auto c1 = std::chrono::high_resolution_clock::now();
      reference_matmul(a, b, c);
      auto c2 = std::chrono::high_resolution_clock::now();
      hoisted_matmul(a, b, c);
      auto c3 = std::chrono::high_resolution_clock::now();
      blocked_matmul(a, b, c);
      auto c4 = std::chrono::high_resolution_clock::now();
      auto d1 =
          std::chrono::duration_cast<std::chrono::seconds>(c2 - c1).count();
      auto d2 =
          std::chrono::duration_cast<std::chrono::seconds>(c3 - c2).count();
      auto d3 =
          std::chrono::duration_cast<std::chrono::seconds>(c4 - c3).count();
      file << N << ";" << d1 << ";" << d2 << ";" << d3 << "\n";
   }
   file.close();
}
