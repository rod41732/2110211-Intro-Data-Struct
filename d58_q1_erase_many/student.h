#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
int i=-1,j=0,L=0,k=pos.size();
while (++i<mSize||j<k)
  if (j==k||i!=pos[j]) mData[L++]=mData[i];
  else j++;
mSize=L;
}

#endif
