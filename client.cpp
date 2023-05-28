
//=========================================================
// Program: Queue
// Your name: Konrad Kucharek
// Complier:  G++
// File type: Client file
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "queue.h"

// Purpose of the program: ** This program will generate all
// possible strings using A, B, and C as the letters.
// Algorithm: Queue.

int main()
{
	queue Queue;
	string data;
	string A = "A";
	string B = "B";
	string C = "C";
  
	while (!Queue.isFull())
	{
		try
		{
			if (Queue.isEmpty())
			{
				Queue.add("A");
				Queue.add("B");
				Queue.add("C");
			}
    
			else
			{
				Queue.remove(data);
				Queue.add(data + A);
				Queue.add(data + B);  
				Queue.add(data + C);
			}
       	}
      
		// Catches  
		catch (queue::Overflow)
		{
			Queue.displayAll();
			cout << "ERROR!!! OVERFLOW. Queue is full." << endl;
		}
		
		catch (queue::Underflow)
		{
			Queue.displayAll();
			cout << "ERROR!!! UNDERFLOW. Queue is empty." << endl;
		}	
	}
}


