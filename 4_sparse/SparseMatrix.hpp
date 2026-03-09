#ifndef CPP_HPC_SPARSE_MATRIX
#define CPP_HPC_SPARSE_MATRIX

#include "../1_vector/Vector.hpp"

#include <ostream>
#include <vector>

template<class T>
class COOMatrix{
public:
   COOMatrix(std::size_t M, std::size_t N) : num_rows_(M), num_cols_(N) {}

   inline std::size_t num_rows() const {return num_rows_;}
   inline std::size_t num_cols() const {return num_cols_;}

   void insert(std::size_t i, std::size_t j, T value) {
      row_indices_.push_back(i);
      col_indices_.push_back(j);
      storage_.push_back(value);
   }

   void matvec(const Vector<T>& x, Vector<T>& y) const {
      for (std::size_t k = 0; k < y.num_rows(); k++) {
         y(k) = T(0);
      }
      for (std::size_t k = 0; k < storage_.size(); k++) {
         y(row_indices_[k]) += storage_[k] * x(col_indices_[k]);;
      }
   }

   template<class Ty>
   friend std::ostream& operator<<(std::ostream& os, const COOMatrix<Ty>&);
private:
   std::size_t num_rows_;
   std::size_t num_cols_;
   std::vector<std::size_t> row_indices_;
   std::vector<std::size_t> col_indices_;
   std::vector<T> storage_;
};

// Overload ostream << operator
template<class T>
std::ostream& operator<<(std::ostream& os, const COOMatrix<T>& x) {
   if (std::is_same_v<T, float>) {
      os << "COOMatrix<float>\n";
   } else if (std::is_same_v<T, double>) {
      os << "COOMatrix<double>\n";
   } else {
      throw
         std::runtime_error("Unsupported type by print <<");
   }
   os << "[";
   for (size_t i = 0; i < x.storage_.size(); i++) {
      os << "(";
      os << x.row_indices_[i];
      os << ", ";
      os << x.col_indices_[i];
      os << ", ";
      os << x.storage_[i];
      os << ")";
      if (i + 1 < x.storage_.size()) {
         os << ", ";
      }
   }
   os << "]";
   return os;
}

#endif
