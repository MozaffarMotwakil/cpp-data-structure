#pragma once

#include "..\P4-DynamicArrayClass\clsDynamicArray.h"

template <class T> class clsQueueArray {
protected:
	clsDynamicArray<T> _list;

public:

	void push(T data) {
		_list.InsertAtEnd(data);
	}

	void pop() {
		_list.DeleteFirstItem();
	}

	void Print() {
		_list.Print();
	}

	int Size() {
		return _list.Size();
	}

	T front() {
		return _list.GetItem(0);
	}

	T back() {
		return _list.GetItem(Size() - 1);
	}

	bool IsEmpty() {
		return _list.IsEmpty();
	}

	T GetItem(int index) {
		return _list.GetItem(index);
	}

	bool UpdateItem(int index, T newData) {
		return _list.SetItem(index, newData);
	}

	bool InsertAfter(int index, T data) {
		return _list.InsertAfter(index, data);
	}

	bool InsertBefore(int index, T data) {
		return _list.InsertBefore(index, data);
	}

	void InsertAtFront(T data) {
		_list.InsertAtBeginning(data);
	}

	void InsertAtBack(T data) {
		_list.InsertAtEnd(data);
	}

	void Reverse() {
		_list.Reverse();
	}

	void Clear() {
		_list.Clear();
	}

};