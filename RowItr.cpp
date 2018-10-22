
#include "RowItr.h"

RowItr::RowItr(){
  element = std::make_shared <Row > ();
  element->beginElement = std::make_shared <RowElementItr > ();

}


RowItr& RowItr::operator++(){ //pre
  element = element->next;
  return *this;

}



RowItr& RowItr::operator++(int){ //post
  /*auto tempVar = *this;
  element = element->next;
  return tempVar;*/
  element = element->next;
  return *this;
}

RowItr& RowItr::operator--() { // pre, monday
  element = element->prev;
  return *this;
}

RowItr& RowItr::operator--(int) { // post, monday
  /*auto tempVar = *this;
  element = element->prev;
  return tempVar;*/
  element = element->prev;
  return *this;
}

double& RowItr::operator[](int i){
  auto current = element->beginElement->element;
  for (int j = 0; j <= i; j++){
    current = current->next;
  }
  return current->rowValue;
}

bool RowItr::operator!=(const RowItr& rhs) const{ //saturday
  return !((this) == &rhs);
}

bool RowItr::operator==(const RowItr& rhs) const{ //saturday
  return ((this) == &rhs);

  /*for(auto itr = rhs.beginElement; itr != nullptr; itr = itr->next) {

    if (*itr == rhs){
      return true;
    }
  }
  return false;*/
}


/*
RowItr& RowItr::operator+=(const int& rhs){ //move self rhs elements forward, monday
  itr += rhs;
  return *this;
}
RowItr RowItr::operator+(const int& rhs){ //new iterator rhs elements past self,  monday

  RowItr Itr(*this); // Make Itr as a copy of *this
  Itr.itr += rhs;
  return Itr;
}

RowItr& RowItr::operator-=(const int& rhs) { // move self rhs elements back, monday
  itr -= rhs;
  return *this;
}

RowItr RowItr::operator-(const int& rhs) { //new iterator rhs elements before self, monday
  RowItr Itr(*this); // Make Itr as a copy of *this
  Itr.itr -= rhs;
  return Itr;
}*/
