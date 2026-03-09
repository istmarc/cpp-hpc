#include <iostream>
#include <thread>

void sayHello(size_t num) {
   std::cout << "Hello, World! " << num << "\n";
}

int main() {
   constexpr size_t N = 16;
   std::thread tid[N];

   for (size_t i = 0; i < N; i++) {
      tid[i] = std::thread(sayHello, i);
   }
   for (size_t i = 0; i < N; i++) {
      tid[i].join();
   }

   return 0;
}
