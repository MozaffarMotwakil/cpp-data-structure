#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string, int> mapPersons;

	// Remember the map sorting the elements from smallest to largest
	mapPersons["Mozaffar"] = 21;
	mapPersons["Ahmed"] = 25;
	mapPersons["Mortada"] = 22;
	mapPersons["Faris"] = 12;
	mapPersons["Awab"] = 18;

	// Traverse all elements by "For Each" or "Ranged Looop"
	cout << "Students:\n";
	for (const auto& pair : mapPersons) {
		cout << "Name: " << pair.first << "\t| Age: " << pair.second << endl;
	}

	// Traverse all elements by "Iterator"
	cout << "\nStudents:\n";
	for (map<string, int>::iterator it = mapPersons.begin(); it != mapPersons.end(); ++it) {
		cout << "Name: " << it->first << "\t| Age: " << (*it).second << endl;
	}

	//Searshing on map
	string name = "Mozaffar";
	if (mapPersons.find(name) != mapPersons.end()) {
		cout << "\nFound Seccessfuly:\n";
		cout << "Name: " << name << "\t| Age: " << mapPersons[name] << endl;
	}
	else {
		cout << "\nSorry, Found Filed\n";
	}

	name = "Motwakil";
	if (mapPersons.find(name) != mapPersons.end()) {
		cout << "\nFound Seccessfuly:\n";
		cout << "Name: " << name << "\t| Age: " << mapPersons[name] << endl;
	}
	else {
		cout << "\nSorry, Found Filed\n";
	}

	return 0;
}