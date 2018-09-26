#ifndef _CP_STUDENT_QUEUE_INCLUDED_
#define _CP_STUDENT_QUEUE_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once
#include <vector>
#include <queue>
#include "queue.h"

template <typename T>
std::vector< CP::queue<T> > CP::queue<T>::split_queue(int k) {
	std::vector<CP::queue<T> > qs(k);
	int i=0,c=0;
	while (mSize){
		qs[((i++)>=k)?(c++,i-=k)-1:i-1].push(mData[mFront+i-1+c*k]), mSize--;
	}
	return qs;
}

#endif

