#include <iostream>
#include <thread>

void sayHello() {
   std::cout << "Hello, World!\n";
}

int main() {
   std::thread helloThread(sayHello);
   helloThread.join();
   return 0;
}
