#pragma once
#include "..\Library\clsDate.h"
#include <queue>
#include <stack>
#include <string>

using namespace std;

class clsQueueLine {
private:
	class clsTicket {
	private:
		int _number = 0;
		string _prefix;
		string _currentDateTime;
		short _expectedServeTime = 0;
		short _watingClients = 0;

	public:
		clsTicket(int number, string prefix, short averageServeTime, int watingClients) {
			_number = number;
			_prefix = prefix;
			_currentDateTime = clsDate::LocalDateTime();
			_expectedServeTime = averageServeTime * watingClients;
			_watingClients = watingClients;
		}

		void Print() {
			cout << "\n\t\t\t______________________________\n";
			cout << "\n\t\t\t\t     " << GetFullNumber() << endl;
			cout << "\n\t\t\t     " << _currentDateTime;
			cout << "\n\t\t\t      Waiting Clients: " << _watingClients;
			cout << "\n\t\t\t       Served Time IN";
			cout << "\n\t\t\t         " << _expectedServeTime << " Minutes";
			cout << "\n\t\t\t______________________________\n";
		}

		int GetNumber() {
			return _number;
		}

		string GetPrefix() {
			return _prefix;
		}

		short GetExpectedServeTime() {
			return _expectedServeTime;
		}

		string GetCurrentDateTime() {
			return _currentDateTime;
		}

		string GetFullNumber() {
			return _prefix + to_string(_number);
		}

	};
	
	queue<clsTicket> _queueLineList;
	string _prefix;
	short _averageServeTime;
	int _totalClients;

public:
	clsQueueLine(string prefix, short averageServeTime) {
		_prefix = prefix;
		_averageServeTime = averageServeTime;
		_totalClients = 0;
	}

	void IssueTicket() {
		_totalClients++;
		_queueLineList.push(clsTicket(_totalClients, _prefix, _averageServeTime, WaitingClients()));
	}

	void PrintInfo() {
		cout << "\n\t\t\t______________________________\n";
		cout << "\n\t\t\t\t  Queue Info";
		cout << "\n\t\t\t______________________________\n";
		cout << "\n\t\t\tPrefix: " << _prefix;
		cout << "\n\t\t\tTotal Client   : " << _totalClients;
		cout << "\n\t\t\tServed Clients : " << ServedClients();
		cout << "\n\t\t\tWaiting Clients: " << WaitingClients();
		cout << "\n\t\t\t______________________________\n";
	}

	int WaitingClients() {
		return _queueLineList.size();
	}

	int ServedClients() {
		return _totalClients - WaitingClients();
	}

	void PrintTicketsLineLTR() {
		queue<clsTicket> tempTicketsList = _queueLineList;

		cout << "\t\t\tTickets: ";
		while (!tempTicketsList.empty()) {
			cout << tempTicketsList.front().GetFullNumber() << " --> ";
			tempTicketsList.pop();
		}

		cout << endl;
	}

	void PrintTicketsLineRTL() {
		queue<clsTicket> tempTicketsList = _queueLineList;
		stack<clsTicket> tempStack;

		while (!tempTicketsList.empty()) {
			tempStack.push(tempTicketsList.front());
			tempTicketsList.pop();
		}

		cout << "\t\t\tTickets: ";
		while (!tempStack.empty()) {
			cout << tempStack.top().GetFullNumber() << " <-- ";
			tempStack.pop();
		}

		cout << endl;
	}

	void PrintAllTickets() {
		queue<clsTicket> tempTicketsList = _queueLineList;

		cout << "\n\t\t\t\t--- Tickets ---";

		if (_queueLineList.empty()) 
			cout << "\n\t\t\t\tNo Available Tickets";
		else
			while (!tempTicketsList.empty()) {
				tempTicketsList.front().Print();
				tempTicketsList.pop();
			}
	}

	bool ServeNextClient() {
		if (_queueLineList.empty())
			return false;
		else {
			_queueLineList.pop();
			return true;
		}
	}

};