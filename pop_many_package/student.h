#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
  while (mSize && K--) pop();
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
  std::stack<int> tm, rt;
  while (mSize && K--) tm.push(top()), pop();
  while (!tm.empty()) rt.push(tm.top()), tm.pop();
  return rt;
}

#endif
