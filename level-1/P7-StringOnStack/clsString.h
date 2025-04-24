#pragma once
#include "..\P3-StackClass\clsStack.h"
#include <string>

using namespace std;

class clsString {
private:
	clsStack<string> _undoStack;
	clsStack<string> _redoStack;
	string _value;

public:
	void SetValue(string value) {
		_undoStack.push(_value);
		_value = value;
	}

	string GetValue() {
		return _value;
	}
	
	__declspec(property(get = GetValue, put = SetValue)) string value;

	void Undo() {
		if (!_undoStack.IsEmpty()) {
			_redoStack.push(_value);
			_value = _undoStack.Top();
			_undoStack.pop();
		}
	}

	void Redo() {
		if (!_redoStack.IsEmpty()) {
			_undoStack.push(_value);
			_value = _redoStack.Top();
			_redoStack.pop();
		}
	}

	bool CanUndo() {
		return !_undoStack.IsEmpty();
	}

	bool CanRedo() {
		return !_redoStack.IsEmpty();
	}

};