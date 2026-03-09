#ifndef CPP_HPC_VECTOR
#define CPP_HPC_VECTOR

#include <stdexcept>
#include <vector>
#include <ostream>

template<class T>
class Vector {
public:
   Vector(std::size_t m) : num_rows_(m), storage_(num_rows_) {}
   Vector(std::size_t m, T init) : num_rows_(m), storage_(num_rows_, init) {}

   inline const T& operator()(std::size_t i) const {return storage_[i];}
   inline T& operator()(std::size_t i) {return storage_[i];}

   inline std::size_t num_rows() const {return num_rows_;}

   template<class Ty>
   friend std::ostream& operator<<(std::ostream&, const Vector<Ty>&);
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

// Overload ostream << operator
template<class T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& x) {
   if (std::is_same_v<T, float>) {
      os << "Vector<float>\n";
   } else if (std::is_same_v<T, double>) {
      os << "Vector<double>\n";
   } else {
      throw
         std::runtime_error("Unsupported type by print <<");
   }
   os << "[";
   for (size_t i = 0; i < x.num_rows_; i++) {
      os << x.storage_[i];
      if (i + 1 < x.num_rows_) {
         os << ", ";
      }
   }
   os << "]";
   return os;
}

#endif
