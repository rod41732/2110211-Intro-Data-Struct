#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
	int d=last-first, idx=position-begin();
	expand(mSize+d);
	for (int i=mSize-1; i>=idx; i--){
		mData[i+d] = mData[i];
	}
	auto pos = mData+idx;
	while (last>first) *pos++=*first++;
	mSize += d;
}

#endif