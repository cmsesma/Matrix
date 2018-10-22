#include "Matrix.h"
#include <vector>
#include <iostream>

Matrix::Matrix() {
  row = 0;
  col = 0;
  firstrow = nullptr;
  firstcol = nullptr;
}

Matrix::Matrix(const double val, const int numRows, const int numCols) {
  firstrow = std::make_shared<RowItr>();
  firstcol = std::make_shared<ColItr>();

  col = numCols;
  row = numRows;
  mat.resize(row);
  for (int i = 0; i < row; i++) {
    mat[i].resize(col);
    for (int j = 0; j < col; j++) {
      mat[i][j] = val;
    }
  }
}


Matrix &Matrix::operator*=(const Matrix &rhs) {
  *this = *this * rhs;
  return *this;

}

Matrix &Matrix::operator*=(const double &rhs) { //scalar multiplication!
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      mat[i][j] = mat[i][j] * rhs;
    }
  }
  return (*this);
}

Matrix Matrix::operator*(const double &rhs) const { //scalar mult!
  Matrix newMat(0, row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      newMat.mat[i][j] = mat[i][j] * rhs;
    }
  }
  return newMat;
}

Matrix operator*(const double &lhs, const Matrix &rhs) { //scalar mult
  Matrix newMat(0, rhs.row, rhs.col);
  for (int i = 0; i < rhs.row; i++) {
    for (int j = 0; j < rhs.col; j++) {
      newMat.mat[i][j] = rhs.mat[i][j] * lhs;
    }
  }
  return newMat;
}

Matrix Matrix::operator*(const Matrix &rhs) const {
  Matrix newMat(0, this->row, rhs.col);
  {
    for (int i = 0; i < this->row; i++) {
      for (int j = 0; j < rhs.col; j++) {
        //newMat.mat[i][j] = 0;
        for (int k = 0; k < rhs.row; k++) {
          newMat.mat[i][j] += mat[i][k] * rhs.mat[k][j];
        }
      }
    }
  }
  return newMat;
}


Matrix::Matrix(const std::vector<std::vector<double>> &mat) {
  //create a matrix from a vector of vector of doubles
  //where each inner vector is a row of the matrix


  firstrow = std::make_shared<RowItr>();
  row = mat.size();
  col = mat[0].size();

  this->mat.resize(row);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      this->mat[i].resize(col);
      this->mat[i][j] = mat[i][j];
    }
  }
}

/*
  std::shared_ptr <Row > current;
  current = firstrow->element;

  for (int i = 1 ; i < row ; i++ ){
    auto tempRow = std::make_shared<Row >();
    current->next = tempRow; //point at each other
    tempRow->prev = current;
    current = current->next; //update current
  }


  for(auto itr = rowBegin(), end = rowEnd(); itr != end; itr++) {
    std::cout << "made it" << std::endl;
    auto currentEle = itr.element->beginElement->element;

    for (int i = 1; i < col; i++) {
      std::cout << "PRINTING I" << i << std::endl;
      auto tempEle = std::make_shared <Value > ();

      currentEle->next = tempEle; //point at each other
      tempEle->prev = currentEle;
      currentEle = currentEle->next; //update current
    }
  }

  int i = 0;
  for(auto itr = rowBegin(), end = rowEnd(); itr != end; itr++) {
    std::cout << "made it !! " << std::endl;
    for (int j = 0 ; j < col ; j++ ){
      std::cout << i << std::endl;
      std::cout << j << std::endl;

      std::cout << "made it..... " << std::endl;
      itr[j] = mat[i][j];
      std::cout << "made it here " << std::endl;


    }
    i++;
  }
}*/


RowItr Matrix::rowBegin() {
  return *firstrow;

}

RowItr Matrix::rowEnd() {
  auto current = firstrow;
  while (current->element->next != nullptr) {
    current->element = current->element->next;
  }

  return *current;

}

RowItr Matrix::operator[](int i) {
  auto current = firstrow;
  for (int j = 0; j <= i; j++) {
    current->element = current->element->next;
  }
  return *current;
}

std::istream &operator>>(std::istream &in, Matrix &matrix) {
  int row, col;

  //std::cin >> row;
  //std::cin >> col;
  in >> row;
  in >> col;

  matrix.row = row;

  matrix.col = col;

  matrix.mat.resize(row);

  for (int i = 0; i < row; i++) {

    matrix.mat[i].resize(col);
    for (int j = 0; j < col; j++) {

      //std::cin >> matrix[i][j];
      //std::cin >> matrix.mat[i][j];
      in >> matrix.mat[i][j];
    }
  }
  return in;
}

std::ostream &operator<<(std::ostream &out, Matrix &matrix) {

  int row = matrix.getNumRows();
  int col = matrix.getNumCols();

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      out << matrix.mat[i][j] << " ";

    }
    out << std::endl;
  }

  return out;
}

int Matrix::getNumCols() const {
  return col;
}

int Matrix::getNumRows() const {
  return row;
}

ColItr Matrix::colBegin() { // get itr to first column
  return *firstcol;
}

ColItr Matrix::colEnd() { // get itr to one past last column
  auto current = firstcol;
  while (current->next != nullptr) {
    current = current->next;
  }
  return *current;
}

/*
friend Matrix::Matrix operator-(const double lhs, const Matrix& rhs){
  lhs - rhs = lhs + (-rhs) = (-rhs) + lhs;
}*/



Matrix Matrix::operator-() const {
  Matrix copy(*this);
  for (int i = 0; i < row; i++){
    for (int j = 0; j < col; j++) {
      copy.mat[i][j] = -mat[i][j];
     }
  }

  return copy;
}

Matrix Matrix::operator+(const Matrix &rhs) const {
  Matrix copy(*this);
  copy += rhs;
  return copy;
}

Matrix Matrix::operator+(const double &rhs) const { //scalar!
  Matrix copy(*this);
  copy += rhs;
  return copy;
}

Matrix operator+(const double lhs, const Matrix &rhs) { //scalar additon
  Matrix copy(rhs);
  return copy + lhs;
}

Matrix Matrix::operator-(const Matrix &rhs) const {
  /*Matrix newMat(0, row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      //mat[i][j] = (*this)[i][j] - rhs[i][j];
      newMat.mat[i][j] = mat[i][j] - rhs.mat[i][j];
    }
  }
  return newMat;*/

  return *this + -rhs;

}

Matrix Matrix::operator-(const double &rhs) const { //scalar!

  return *this + -rhs;
}

Matrix operator-(const double lhs, const Matrix &rhs) { //scalar subtraction


  return lhs + -rhs;
}

Matrix &Matrix::operator-=(const Matrix &rhs) {

  return *this += -rhs;
}

Matrix &Matrix::operator-=(const double &rhs) { //scalar

  return *this += -rhs;

}

Matrix &Matrix::operator+=(const Matrix &rhs) {
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      mat[i][j] += rhs.mat[i][j];
    }
  }
  return *this;
}

Matrix &Matrix::operator+=(const double &rhs) { //scalar
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      mat[i][j] += rhs;
    }
  }
  return *this;
}

RowItr Matrix::operator[](int i) const {
  auto current = firstrow;
  for (int j = 0; j <= i; j++) {
    current->element = current->element->next;
  }
  return *current;
}
