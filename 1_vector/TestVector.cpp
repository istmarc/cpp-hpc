#include "Vector.hpp"

#include <cstddef>

int main() {
   {
      size_t num_rows = 1024;

      Vector<double> v1(num_rows);

      for (size_t i = 0; i < v1.num_rows(); i++) {
         v1(i) = i;
      }

      Vector<double> v2(v1);
      Vector<double> v3 = v2;
      v3 = v2;
   }

   {
      size_t num_rows = 10;
      Vector<double> x(num_rows);
      Vector<double> y(num_rows);
      auto z = x + y;
   }

   return 0;
}
