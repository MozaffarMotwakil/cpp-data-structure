#include <iostream>
#include "clsString.h"

using namespace std;

int main()
{
	clsString text;

	text.value = "Mozaffar";
	text.value = "Mozaffar Motwakil";
	text.value = "Mozaffar Motwakil Khider";
	text.value = "Mozaffar Motwakil Khider Salman";

	cout << "Original Text:   " << text.value << endl;

	// Undo

	text.Undo();
	cout << "Text after undo: " << text.value << endl;

	text.Undo();
	cout << "Text after undo: " << text.value << endl;

	text.Undo();
	cout << "Text after undo: " << text.value << endl;

	text.Undo();
	cout << "Text after undo: " << text.value << endl;

	// Redo

	text.Redo();
	cout << "Text after redo: " << text.value << endl;

	text.Redo();
	cout << "Text after redo: " << text.value << endl;

	text.Redo();
	cout << "Text after redo: " << text.value << endl;

	text.Redo();
	cout << "Text after redo: " << text.value << endl;

	return 0;
}