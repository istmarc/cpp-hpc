#include <iomanip>
#include <iostream>

namespace math{
   double pi = 3.14;
}

double pi = 3.1415;

int main() {
   std::cout << "The value of pi is ";
   std::cout << std::setprecision(6) << math::pi << std::endl;
   // Globale namespace using ::
   std::cout << "The other pi is ";
   std::cout << std::setprecision(6) << ::pi << std::endl;
   return 0;
}
