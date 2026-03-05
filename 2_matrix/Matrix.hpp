#ifndef CPP_HPC_MATRIX
#define CPP_HPC_MATRIX

#include <stdexcept>
#include <vector>

template <class T> class Matrix {
 public:
   Matrix(size_t M, size_t N)
       : num_rows_(M), num_cols_(N), storage_(num_rows_ * num_cols_) {}

   Matrix(size_t M, size_t N, T init)
       : num_rows_(M), num_cols_(N), storage_(num_rows_ * num_cols_, init) {}

   T &operator()(size_t i, size_t j) { return storage_[i * num_cols_ + j]; }
   const T &operator()(size_t i, size_t j) const {
      return storage_[i * num_cols_ + j];
   }

   size_t num_rows() const { return num_rows_; }
   size_t num_cols() const { return num_cols_; }

 private:
   size_t num_rows_;
   size_t num_cols_;
   std::vector<T> storage_;
};

template <class T>
Matrix<T> reference_matmul(const Matrix<T> &a, const Matrix<T> &b) {
   if (a.num_cols() != b.num_rows()) {
      throw std::runtime_error(
          "Reference matrix multiplication dimension mismatch.");
   }
   size_t M = a.num_rows();
   size_t N = b.num_cols();
   size_t K = a.num_cols();
   Matrix<T> c(M, N, T(0));
   for (size_t i = 0; i < M; i++) {
      for (size_t j = 0; j < N; j++) {
         for (size_t k = 0; k < K; k++) {
            c(i, j) += a(i, k) * b(k, j);
         }
      }
   }
   return c;
}

template <class T>
Matrix<T> hoisted_matmul(const Matrix<T> &a, const Matrix<T> &b) {
   if (a.num_cols() != b.num_rows()) {
      throw std::runtime_error(
          "Reference matrix multiplication dimension mismatch.");
   }
   size_t M = a.num_rows();
   size_t N = b.num_cols();
   size_t K = a.num_cols();
   Matrix<T> c(M, N, T(0));
   for (size_t i = 0; i < M; i++) {
      for (size_t j = 0; j < N; j++) {
         T s = T(0);
         for (size_t k = 0; k < K; k++) {
            s += a(i, k) * b(k, j);
         }
         c(i, j) = s;
      }
   }
   return c;
}

template <class T>
Matrix<T> blocked_matmul(const Matrix<T> &a, const Matrix<T> &b) {
   if (a.num_cols() != b.num_rows()) {
      throw std::runtime_error(
          "Reference matrix multiplication dimension mismatch.");
   }
   size_t M = a.num_rows();
   size_t N = b.num_cols();
   size_t K = a.num_cols();
   Matrix<T> c(M, N, T(0));
   for (size_t i = 0; i < M; i += 2) {
      for (size_t j = 0; j < N; j += 2) {
         T s00 = c(i, j);
         T s01 = c(i, j + 1);
         T s10 = c(i + 1, j);
         T s11 = c(i + 1, j + 1);
         for (size_t k = 0; k < K; k++) {
            s00 += a(i, k) * b(k, j);
            s01 += a(i, k) * b(k, j + 1);
            s10 += a(i + 1, k) * b(k, j);
            s11 += a(i + 1, k) * b(k, j + 1);
         }
         c(i, j) = s00;
         c(i, j + 1) = s01;
         c(i + 1, j) = s10;
         c(i + 1, j + 1) = s11;
      }
   }
   return c;
}

#endif
