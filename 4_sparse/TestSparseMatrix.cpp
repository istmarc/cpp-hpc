#include "SparseMatrix.hpp"

#include <iostream>

int main() {
   using Matrix = COOMatrix<double>;
   Matrix a(6, 6);
   a.insert(0, 0, 3.);
   a.insert(0, 3, 8.);
   a.insert(1, 1, 1.);
   a.insert(1, 2, 4.);
   a.insert(1, 4, 6.);
   a.insert(2, 5, 7.);
   a.insert(3, 0, 5.);
   a.insert(3, 2, 4.);
   a.insert(3, 3, 1.);
   a.insert(4, 1, 3.);
   a.insert(4, 4, 5.);
   a.insert(5, 5, 9.);

   using Vec = Vector<double>;
   Vec x(6, 1.);
   Vec y(6);

   a.matvec(x, y);

   std::cout << a << std::endl;
   std::cout << y << std::endl;
}
