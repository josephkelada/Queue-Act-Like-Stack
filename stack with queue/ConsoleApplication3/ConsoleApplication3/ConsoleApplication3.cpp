#include <iostream>
#include <queue>
#include <stack>
#include <chrono>
#include <thread>
using namespace std::this_thread;

using namespace std;

class Stack
{
	queue<int> q1, q2;// array
	int curr_size;


public:
	Stack()
	{
		curr_size = 0;
	}

    void push(int x)
	{
		curr_size++;


		q2.push(x);//we add x to the top of the queue

		while (!q1.empty())//while queue 1 isnt empty			
		{
			q2.push(q1.front());//add what ever is at the front of queue 1 to the top of queue 2 
			q1.pop();// remove what ever was just added to the queue 2 
		}

		queue<int> q = q1;
		q1 = q2;//change q1 to the value of q2
		q2 = q;//change q2 to the old value of q1, should always be empty 
	}

	void pop()
	{
		if (q1.empty())
			return;
		q1.pop();
		curr_size--;
	}

	int top()
	{
		if (q1.empty())
			return -1;
		return q1.front(); // returns the first element of the queue 1 
	}

	void showQueue(Stack s) {
		Stack dummy = s;

		for (int i = 0; i < q1.size(); i++) {
			cout << endl << dummy.top();
			dummy.pop();
		}
	}

	int size()
	{
		return curr_size;
	}
};
int main()
{
	int input = 999;
	int innerInput = 999;
	Stack s;
	while (input != 0) {
		cout << "Press 1 to Push a number in Queue or type \"0\" to exit" << endl;
		cout << "Press 2 to Pop() queue or type \"0\" to exit" << endl;
		cout << "Press 3 to show queue or type \"0\" to exit" << endl;
		cout << "Press 0 to exit" << endl;
		cin >> input;
		switch (input) {
		case 1:
			while (innerInput != 0) {
				cout << "Enter a number to put in the queue or type \"0\" to exit" << endl;
				cin >> innerInput;
				if (innerInput == 0) {
					break;
				}
				s.push(innerInput);
			}
			break;
		case 2:
			s.pop();
			cout << endl << "Popped!";
			sleep_for(std::chrono::milliseconds(3000));
			break;
		case 3:
			s.showQueue(s);
			sleep_for(std::chrono::milliseconds(6000));
			break;
		case 0:
			exit(0);
		}
		system("CLS");
	}
	return 0;
}


