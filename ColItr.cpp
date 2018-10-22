#include "ColItr.h"



ColItr& ColItr::operator++(){ //pre
  return *this->next;
}


ColItr& ColItr::operator++(int){ //post
  return *this->next;
}


ColItr& ColItr::operator--() {// pre, monday
  return *this->prev;
}


ColItr& ColItr::operator--(int) { // post, monday
  return *this->prev;
}

/*
ColElementItr ColItr::operator* (){ //monday
  ColElementItr colElementItr(mat, *this, 0);
  return colElementItr;
}

ColElementItr ColItr::begin(){ //monday
  ColElementItr colElementItr(mat, *this, 0);
  return colElementItr;
}

double& ColItr::operator[](int i){
  auto current = beginElement;
  for (int j = 0; j <= i; j++){
    current = current->next;
  }
  return *current->colValue;
}



ColItr& ColItr::operator+=(const int& rhs){ //move self rhs elements forward, monday
  itr += rhs;
  return *this;
}
ColItr ColItr::operator+(const int& rhs){ //new iterator rhs elements past self,  monday

  ColItr Itr(*this); // Make Itr as a copy of *this
  Itr.itr += rhs;
  return Itr;
}

ColItr& ColItr::operator-=(const int& rhs) { // move self rhs elements back, monday
  itr -= rhs;
  return *this;
}

ColItr ColItr::operator-(const int& rhs) { //new iterator rhs elements before self, monday
  ColItr Itr(*this); // Make Itr as a copy of *this
  Itr.itr -= rhs;
  return Itr;
}
*/

bool ColItr::operator!=(const ColItr& rhs) const{ //saturday
  return !((*this) == rhs);
}

bool ColItr::operator==(const ColItr& rhs) const{ //saturday
  return ((this->next) == rhs.next);
/*for(auto itr = rhs.beginElement; itr != nullptr; itr = itr->next) {

    if (itr == )

      b = 0;
    for (auto i = itr->beginElement; i != nullptr; itr = itr->next) {
      i->colValue = &(*this)[a][b];
      b++;
    }
    a++;
  }*/

}