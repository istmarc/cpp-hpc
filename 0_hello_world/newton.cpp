#include <iostream>
#include <cmath>

/* Computing the square root using Newton's method
   f(x) = x^2 - y
   y = sqrt(x)
   f'(x) = 2x
   delta_x = -f(x) / f'(x)
   with f(x + delta_x) = f(x) + delta_x f'(x) = delta_x f'(x)
*/
double sqrt(const double y, const size_t n, const double eps = 1e-9) {
   double x = 1.0;
   for (size_t i = 0; i < n; i++) {
      double dx = - (x*x - y) / (2. * x);
      x += dx;
      if (std::abs(dx) < eps) break;
   }
   return x;
}

int main() {
   std::cout << "Square root of 2 = " << sqrt(2., 32) << std::endl;
   std::cout << "Square root of 3 = " << sqrt(3., 32) << std::endl;
}
