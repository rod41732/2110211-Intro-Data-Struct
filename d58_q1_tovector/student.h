#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const{
std::vector<T> res(k);
for (int i=0;i<k;i++)res[i]=mData[mFront+i];
return res;
}
template <typename T>
CP::queue<T>::queue(iterator from, iterator to){
int X=to-from,i=0;
mData=new T[X]();mCap=mSize=X;mFront=0;
while (X--) mData[i++]=*from++;
}

#endif