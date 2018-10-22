#include "RowElementItr.h"

RowElementItr::RowElementItr(){
  element = std::make_shared <Value > ();

}


/*double& RowElementItr::operator*(){  //monday
  return *rowValue;
}*/
/*
RowElementItr& RowElementItr::operator+=(const int& rhs){ //move self rhs elements forward, monday
  itr += rhs;
  return *this;
}
RowElementItr RowElementItr::operator+(const int& rhs){ //new iterator rhs elements past self,  monday

  RowElementItr Itr(*this); // Make Itr as a copy of *this
  Itr.itr += rhs;
  return Itr;
}

RowElementItr& RowElementItr::operator-=(const int& rhs) { // move self rhs elements back, monday
  itr -= rhs;
  return *this;
}

RowElementItr RowElementItr::operator-(const int& rhs) { //new iterator rhs elements before self, monday
  RowElementItr Itr(*this); // Make Itr as a copy of *this
  Itr.itr -= rhs;
  return Itr;
}

RowElementItr::operator bool() const{
  if(itr >= 0 && itr < matrix.GetNumRows()){
    return true;
  } else { return false; }
}*/


RowElementItr& RowElementItr::operator++(){ //pre, monday
  element = element->next;
  return *this;
}


RowElementItr& RowElementItr::operator++(int) { //post, monday
  element = element->next;
  return *this;
}

RowElementItr& RowElementItr::operator--() { // pre, monday
  element = element->prev;

  return *this;
}

RowElementItr& RowElementItr::operator--(int) { // post, monday
  element = element->prev;

  return *this;
}


