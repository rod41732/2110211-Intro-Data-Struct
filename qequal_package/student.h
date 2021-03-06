#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::queue<T>::operator==(const CP::queue<T> &other) const {
  if (mSize != other.mSize) return false;
  for (int i=0; i<mSize; i++)
    if (mData[mFront+i] != other.mData[other.mFront+i]) return false;
  return true;
}

#endif
