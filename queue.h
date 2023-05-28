
// =====================================================
// Program: Queue
// Name: Konrad Kucharek
// Compiler: G++
// File type: Queue Header file 
//=====================================================

//----- Globally setting up the aliases ----------------
using namespace std;
#include<string>
typedef string el_t; // el_t is an alias for the data type
					 // el_t is unknown to the client  

const int MAX_SIZE = 10; // this is the max number of elements
						 // MAX is unknown to the client
//-------------------------------------------------------

class queue  
{
  private:
  // Data members are:
  el_t el[MAX_SIZE]; // An array called el.
                     // Elements will be found between front and rear but
                     // front may be behind rear since the queue wraps around.
  int  count; // How many elements do we have right now?
  int  front; // Where the front element of the queue is.
  int  rear;  // Where the rear element of the queue is.

  public:    
  // Prototypes to be used by the client.
  // Note that no parameter variables are given.

  // Exception Handling Classes
   class Overflow{}; // Thrown when the queue overflows
   class Underflow{}; // Thrown when the queue underflows


   queue(); // Constructor to create an object 
   ~queue(); // Destructor to destroy an object

   // Returns true if queue is empty, otherwise false
   bool isEmpty();

   // Returns true if queue is full, otherwise false
   bool isFull();

   // If full, throws an exception Overflow.
   // If not full, enters an element at the rear.
   // PRAMETER: provide the element to be added.
   void add(el_t);

   // If empty, throws an exception Underflow.
   // If not empty, removes the front element to give it back. 
   // PRAMETER: provide a holder for the element removed (pass by ref).
   void remove(el_t&);

   // If empty, throws an exception Underflow.
   // If not empty, give back the front element (but does not remove it).
   // PARAMETER: provide a holder for the element (pass by ref).
   void frontElem(el_t&);

   // Returns the current size to make it accessible to the client caller.
   int getSize();

   // Display everything in the queue from front to rear enclosed in [].
   // If empty, displays [ empty ].
   void displayAll();

   // If empty, throws an exception Underflow.
   // If queue has just 1 element, does nothing.
   // If queue has more than 1 element, moves the front one to the rear.
   void goToBack();


};           

