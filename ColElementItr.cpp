#include "ColElementItr.h"

double& ColElementItr::operator*(){ //monday
  return *colValue;
}

ColElementItr& ColElementItr::operator++(){ //pre, monday
  return *this->next;
}


ColElementItr& ColElementItr::operator++(int){ //post, monday
  return *this->next;
}


ColElementItr& ColElementItr::operator--() {// pre, monday
  return *this->prev;
}


ColElementItr& ColElementItr::operator--(int) { // post, monday
  return *this->prev;
}


/*
ColElementItr& ColElementItr::operator+=(const int& rhs){ //move self rhs elements forward, monday
  (*this) = (*this)->next;
  itr += rhs;
  return *this;
}
ColElementItr ColElementItr::operator+(const int& rhs){ //new iterator rhs elements past self,  monday

  ColElementItr Itr(*this); // Make Itr as a copy of *this
  Itr.itr += rhs;
  return Itr;
}

ColElementItr& ColElementItr::operator-=(const int& rhs) { // move self rhs elements back, monday
  itr -= rhs;
  return *this;
}

ColElementItr ColElementItr::operator-(const int& rhs) { //new iterator rhs elements before self, monday
  ColElementItr Itr(*this); // Make Itr as a copy of *this
  Itr.itr -= rhs;
  return Itr;
}*/
