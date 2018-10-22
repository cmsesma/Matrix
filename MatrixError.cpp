
#include "MatrixError.h"

const char* MatrixError::what() const noexcept {
  return errString.c_str();
}
