#pragma once

#include "..\P5-QueueArrayClass\clsQueueArray.h"

template <class T> class clsStackArray : public clsQueueArray<T> {
public:

	void push(T data) {
		clsQueueArray<T>::_list.InsertAtBeginning(data);
	}

	T Top() {
		return clsQueueArray<T>::front();
	}

	T Bottom() {
		return clsQueueArray<T>::back();
	}

};