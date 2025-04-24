#pragma once

using namespace std;

template <class T> class clsDynamicArray {
protected:
	int _size;
	T* tempArray;

public:
	T* originalArray;

	clsDynamicArray(int size = 0) {
		if (size < 0) 
			size = 0;

		_size = size;
		originalArray = new T[_size];
	}
	
	~clsDynamicArray() {
		delete[] originalArray;
	}

	bool SetItem(int index, T data) {
		if (index < 0 || index >= _size) 
			return false;

		originalArray[index] = data;
		return true;
	}

	bool InsertAt(int index, T data) {
		if (index > _size || index < 0)
			return false;

		_size = _size + 1;

		tempArray = new T[_size];

		// Copy the part before index
		for (int i = 0; i < index; i++) {
			tempArray[i] = originalArray[i];
		}

		tempArray[index] = data;

		// Copy the part after index
		for (int i = index + 1; i < _size; i++) {
			tempArray[i] = originalArray[i - 1];
		}

		delete[] originalArray;
		originalArray = tempArray;

		return true;
	}

	bool InsertAtBeginning(T data) {
		return InsertAt(0, data);
	}

	bool InsertAtEnd(T data) {
		return InsertAt(_size, data);
	}

	bool InsertBefore(int index, T data) {
		return InsertAt(index - 1, data);
	}

	bool InsertAfter(int index, T data) {
		return InsertAt(index + 1, data);
	}

	int Size() {
		return _size;
	}

	void Resize(int newSize) {
		tempArray = new T[newSize];

		if (newSize < 0)
			newSize = 0;

		if (newSize < _size)
			_size = newSize;

		for (int i = 0; i < _size; i++) {
			tempArray[i] = originalArray[i];
		}

		_size = newSize;
		
		delete[] originalArray;
		originalArray = tempArray;
	}

	T GetItem(int index) {
		return (index >= _size || index < 0) ? NULL : originalArray[index];
	}

	int Find(T data) {
		for (int i = 0; i < _size; i++) {
			if (data == originalArray[i]) {
				return i;
			}
		}

		return -1;
	}

	bool DeleteItemAt(int index) {
		if (index >= _size || index < 0)
			return false;

		tempArray = new T[_size - 1];
		
		// Copy the part before index
		for (int i = 0; i < index; i++)	{
			tempArray[i] = originalArray[i];
		}
		
		// Copy the part after index
		for (int i = index + 1; i < _size; i++)	{
			tempArray[i - 1] = originalArray[i];
		}

		_size = _size - 1;
		delete[] originalArray;
		originalArray = tempArray;

		return true;
	}

	bool DeleteItem(T data) {
		return DeleteItemAt(Find(data));
	}

	bool DeleteFirstItem() {
		return DeleteItemAt(0);
	}

	bool DeleteLastItem() {
		return DeleteItemAt(_size - 1);
	}

	void Reverse() {
		T temp;

		for (int i = 0;  i < _size / 2;  i++) {
			temp = originalArray[i];
			originalArray[i] = originalArray[_size - 1 - i];
			originalArray[_size - 1 - i] = temp;
		}
	}

	void Clear() {
		_size = 0;
		delete[] originalArray;
		originalArray = new T[0];
	}
	
	bool IsEmpty() {
		return _size == 0;
	}

	void Print() {
		for (int i = 0; i < _size; i++) {
			cout << originalArray[i] << " ";
		}

		cout << endl;
	}

};