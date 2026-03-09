#include <iostream>
#include <thread>
#include <vector>

#include "../3_timer/Timer.hpp"

void partial_pi(size_t begin, size_t end, double h, double& pi) {
   double partial_pi = 0.;
   for (size_t i = begin; i < end; i++)  {
      partial_pi += 4.0 / (1.0 + i*h*i*h);
   }
   pi += h * partial_pi;
}

double bench(std::size_t block_size) {
   std::vector<std::thread> threads;


   constexpr size_t intervals = 1024;
   double h = 1.0 / intervals;
   size_t num_blocks = intervals / block_size;

   threads.reserve(num_blocks);

   double pi = 0.;
   for (size_t k = 0; k < num_blocks; k++) {
      threads.push_back(std::thread(partial_pi, k*block_size, (k+1)*block_size, h, std::ref(pi)));
   }
   for (size_t k = 0; k < num_blocks; k++) {
      threads[k].join();
   }
   return pi;
}

int main() {
   Timer t;
   for (size_t block_size = 2; block_size <= 1024; block_size *=2) {
      std::cout << "Block size = " << block_size << std::endl;
      t.start();
      double pi = bench(block_size);
      t.stop();
      std::cout << "Pi = " << pi << std::endl;
      std::cout << "Elapsed = " << t.elapased() << std::endl;
   }

}
