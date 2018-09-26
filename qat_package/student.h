#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
T CP::queue<T>::operator[](int idx) {
  return mData[(mFront+idx+(idx<0?mSize:mSize))%mCap];
}

#endif
