
//=========================================================
// Program: Queue
// Name: Konrad Kucharek
// Complier:  G++
// File type: Queue Program file
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// Constructor 
queue::queue()
{
	front = 0;
	rear = -1;
	count = 0;
}

// Destructor 
queue::~queue()
{
}

// Returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
	if (count == 0) 
	{
		return true; 
	}
 
	else 
	{
		return false;
	}
}

// Returns true if queue is full, otherwise false
bool queue::isFull()
{
	if (count == MAX_SIZE) 
	{
		return true; 
	}
 
	else
	{
		return false;
	}
}

// If full, throws an Overflow exception.
// If not full, enters an element at the rear.
// PAREMETER: Provide the element (newElem) to be added.
void queue::add(el_t newElem)
{
	if (isFull()) 
	{
		throw Overflow(); 
	} 

	else
	{
		count++;
		rear = ((rear+1) % MAX_SIZE);
		el [rear] = newElem; 
	}
}

// If empty, calls an emergency exit routine.
// If not empty, removes the front element to give it back.
// PARAMETER: Provide a holder (removedElem) for the element removed (pass by ref).
void queue::remove(el_t& removedElem)
{
	if (isEmpty()) 
	{
		throw Underflow();
	}
 
	else
	{
		removedElem = el[front];
		front = ((front+1) % MAX_SIZE);
		count--;
	}
}

// If empty, throws an Underflow exception.
// If not empty, give back the front element (but does not remove it).
// PARAMETER: Provide a holder (theElem) for the element (pass by ref).
void queue::frontElem(el_t& theElem)
{
	if (isEmpty()) 
	{
		throw Underflow();
	}
  
	else 
	{
		theElem = el[front];
	}
}

// Returns the current size to make it accessible to the client caller
int queue::getSize()
{
	return count;
}

// Display everything in the queue horizontally from front to rear
// enclosed in [].

void queue::displayAll()
{
	// If empty, displays [ empty ].
	if (isEmpty())
	{
		cout << "[ empty ]";
	}
 
	else
	{
		cout << "[ ";
		if (rear >= front)
		{
			for (int i = front; i < rear + 1; i++)
			{
				cout << el[i] << " ";
			}
		}
		else if (rear < front)
		{
			for (int i = front; i < MAX_SIZE + 1; i++)
			{  
				if (i == MAX_SIZE)
				{
					int j = i % MAX_SIZE;
					for (int i = j; i < rear + 1; i++)
					{
						cout << el[i] << " ";
					}
					cout << " ] " << endl;
					return;
				}  
				cout << el [i] << " ";
			}
		}
		cout << " ] " << endl;
	}
}

// If empty, throws an Underflow exception.
// If queue has just 1 element, does nothing.
// If queue has more than 1 element, moves the front one to the rear by
// doing remove followed by add.
void queue::goToBack()
{
	if (isEmpty()) 
	{
		throw Underflow();
	}
  
	else if (count > 1)
	{
		string elem;
		remove (elem);
		add (elem);
	}
}




