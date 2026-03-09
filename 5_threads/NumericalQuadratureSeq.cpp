#include <iostream>

int main() {
   size_t N = 2048;
   double h = 1.0 / N;

   double pi = 0.;
   for (size_t i = 0; i < N; i++) {
      pi += h * 4.0 / (1 + i*h*i*h);
   }
   std::cout << "Pi = " << pi << std::endl;
}
