#pragma once

#include "..\P2-QueueClass\clsQueue.h"

template <class T> class clsStack : public clsQueue<T> {
public:

	void push (T data) {
		clsQueue<T>::_list.InsertAtBeginning(data);
	}

	T Top() {
		return clsQueue<T>::front();
	}

	T Bottom() {
		return clsQueue<T>::back();
	}

};