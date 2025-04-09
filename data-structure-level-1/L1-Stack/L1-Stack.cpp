#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<short> stcNumbers;
	
	stcNumbers.push(10);
	stcNumbers.push(20);
	stcNumbers.push(30);
	stcNumbers.push(40);
	stcNumbers.push(50);

	cout << "Stack size: " << stcNumbers.size() << endl;
	cout << "Stack elements: ";

	while (!stcNumbers.empty()) {
		cout << stcNumbers.top() << " ";
		stcNumbers.pop();
	}

	cout << "\n________________________\n";

	stack<short> stcTest1, stcTest2;

	stcTest1.push(1);
	stcTest1.push(2);
	stcTest1.push(3);

	cout << "\nStack #1 size: " << stcTest1.size() << endl;
	cout << "Stack #1 elements: ";

	while (!stcTest1.empty()) {
		cout << stcTest1.top() << " ";
		stcTest1.pop();
	}

	stcTest2.push(4);
	stcTest2.push(5);
	stcTest2.push(6);

	cout << "\nStack #2 size: " << stcTest2.size() << endl;
	cout << "Stack #2 elements: ";

	while (!stcTest2.empty()) {
		cout << stcTest2.top() << " ";
		stcTest2.pop();
	}

	cout << "\n________________________\n";

	cout << "\nAfter swaping:\n";

	stcTest1.push(1);
	stcTest1.push(2);
	stcTest1.push(3);
	stcTest1.push(4);
	stcTest1.push(5);

	stcTest2.push(6);
	stcTest2.push(7);
	stcTest2.push(8);

	stcTest1.swap(stcTest2);

	cout << "\nStack #1 size: " << stcTest1.size() << endl;
	cout << "Stack #1 elements: ";

	while (!stcTest1.empty()) {
		cout << stcTest1.top() << " ";
		stcTest1.pop();
	}

	cout << "\nStack #2 size: " << stcTest2.size() << endl;
	cout << "Stack #2 elements: ";

	while (!stcTest2.empty()) {
		cout << stcTest2.top() << " ";
		stcTest2.pop();
	}

	cout << "\n________________________\n";

	return 0;
}