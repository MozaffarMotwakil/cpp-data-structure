#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> queNumbers;

	queNumbers.push(10);
	queNumbers.push(20);
	queNumbers.push(30);

	cout << "Size : " << queNumbers.size() << endl; // 3
	cout << "Front: " << queNumbers.front() << endl; // 10
	cout << "Back : " << queNumbers.back() << endl; // 30

	cout << "Queue elements: ";
	while (!queNumbers.empty()) {
		cout << queNumbers.front() << " ";
		queNumbers.pop();
	}

	return 0;
}