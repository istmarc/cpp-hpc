#ifndef CPP_HPC_VECTOR
#define CPP_HPC_VECTOR

#include <stdexcept>
#include <vector>

template<class T>
class Vector {
public:
   Vector(std::size_t m) : num_rows_(m), storage_(num_rows_) {}

   const T& operator()(std::size_t i) const {return storage_[i];}
   T& operator()(std::size_t i) {return storage_[i];}

   std::size_t num_rows() const {return num_rows_;}

private:
   std::size_t num_rows_;
   std::vector<T> storage_;
};

// Overload + operator
template<class T>
Vector<T> operator+(const Vector<T>& x, const Vector<T>& y) {
   if (x.num_rows() != y.num_rows()) {
      throw
         std::runtime_error("Error adding two vectors of different sizes.");
   }
   Vector<T> z(x.num_rows());
   for (std::size_t i = 0; i < z.num_rows(); i++) {
      z(i) = x(i) + y(i);
   }
   return z;
}

#endif
