#include <iostream>
#include "clsStack.h"

using namespace std;

// Show implementation of clsStack class in clsStack.h file

int main()
{

	clsStack<int> stack;

	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	stack.push(50);

	cout << "Stack's List: ";
	stack.Print();

	cout << "Stack's Size   : " << stack.Size() << endl;
	cout << "Stack's Top    : " << stack.Top() << endl;
	cout << "Stack's Bottom : " << stack.Bottom() << endl;

	stack.pop();
	cout << "Stack's List after pop: ";
	stack.Print();

	stack.InsertAtFront(10);
	cout << "Stack's List after insert 10 at front: ";
	stack.Print();

	stack.InsertAtBack(60);
	cout << "Stack's List after insert 60 at back: ";
	stack.Print();

	cout << "Item(2): " << stack.GetItem(2) << endl;

	stack.InsertAfter(2, 50);
	cout << "Stack's list after inserting 50 after item(2): ";
	stack.Print();

	stack.UpdateItem(4, 100);
	cout << "Stack's list after update item(4) to 100: ";
	stack.Print();

	stack.Reverse();
	cout << "Stack's list after reverse: ";
	stack.Print();

	stack.Clear();
	cout << "Stack's list after clear: ";
	stack.Print();

	return 0;
}