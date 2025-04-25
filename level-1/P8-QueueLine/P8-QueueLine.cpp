#include "clsQueueLine.h"
#include <iostream>

using namespace std;

int main()
{
	clsQueueLine payBillsQueue("A0", 10);
	
	payBillsQueue.IssueTicket();
	payBillsQueue.IssueTicket();
	payBillsQueue.IssueTicket();

	payBillsQueue.PrintInfo();

	payBillsQueue.PrintTicketsLineLTR();
	payBillsQueue.PrintTicketsLineRTL();

	payBillsQueue.PrintAllTickets();

	payBillsQueue.ServeNextClient();

	payBillsQueue.PrintInfo();

	payBillsQueue.ServeNextClient();
	payBillsQueue.ServeNextClient();

	payBillsQueue.PrintInfo();

	payBillsQueue.IssueTicket();
	payBillsQueue.IssueTicket();

	payBillsQueue.PrintInfo();

	payBillsQueue.PrintAllTickets();

	return 0;
}