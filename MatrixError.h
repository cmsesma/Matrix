#ifndef MATRIX_MATRIXERROR_H
#define MATRIX_MATRIXERROR_H

#include <exception>
#include <string>
#include <iostream>
#include <memory>
class MatrixError : std::exception  {
 protected:
 public:
  virtual const char* what() const noexcept override;
 protected:
  std::string errString;
};

#endif //MATRIX_MATRIXERROR_H

