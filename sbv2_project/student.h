#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <iostream>
#define min(a, b) ((a)<(b))?(a):(b)

template <typename T>
size_t CP::stack<T>::size() const {
  return v.size();
}

template <typename T>
const T& CP::stack<T>::top() const {
  return v.back();
}

template <typename T>
void CP::stack<T>::push(const T& element) {
  v.push_back(element);
}

template <typename T>
void CP::stack<T>::pop() {
  if (v.size() != 0) v.pop_back();
}

template <typename T>
void CP::stack<T>::deep_push(const T& element, int depth) {
  if (depth > v.size()) depth = v.size();
  v.insert(v.begin() + v.size()-depth, element);
}

template <typename T>
void CP::stack<T>::multi_push(const std::vector<T> &w) {
  for (T elem: w){
    push(elem);
  }
}

template <typename T>
void CP::stack<T>::pop_until(const T& e) {
  while (!v.empty() && v.back() != e)
    v.pop_back();
}

#endif

