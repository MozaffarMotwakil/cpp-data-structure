#include <iostream>
#include "clsQueueArray.h"

using namespace std;

// Show implementation of clsQueueArray class in clsQueueArray.h file

int main()
{

	clsQueueArray<int> queue;

	queue.push(10);
	queue.push(20);
	queue.push(30);
	queue.push(40);
	queue.push(50);

	cout << "Queue's List: ";
	queue.Print();

	cout << "Queue's Size : " << queue.Size() << endl;
	cout << "Queue's Front: " << queue.front() << endl;
	cout << "Queue's Back : " << queue.back() << endl;

	queue.pop();
	cout << "Queue's List after pop: ";
	queue.Print();

	queue.InsertAtFront(10);
	cout << "Queue's List after insert 10 at front: ";
	queue.Print();

	queue.InsertAtBack(60);
	cout << "Queue's List after insert 60 at back: ";
	queue.Print();

	cout << "Item(2): " << queue.GetItem(2) << endl;

	queue.InsertAfter(2, 35);
	cout << "Queue's list after insert 35 after 30: ";
	queue.Print();

	queue.UpdateItem(6, 55);
	cout << "Queue's list after update 60 to 55: ";
	queue.Print();

	queue.Reverse();
	cout << "Queue's list after reverse: ";
	queue.Print();

	queue.Clear();
	cout << "Queue's list after clear: ";
	queue.Print();

	return 0;
}