#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "linearStructure.h"
#include "node.h"

template<class T>
class LinkedList;

template<class T>
ostream& operator<<(ostream&,LinkedList<T>&);

/* 
   Circular doubly-linked list.
   Note: head->prev must point to the last node at all times.
*/

template<class T>
class LinkedList : public LinearStructure<T>
{
	public:
		/*The overloaded stream operator for the LinkedList class. If
		a LinkedList object is printed and contains the elements a,c,b and m, with
		element 'a' at index 0 (head) and element 'm' at index 3 (first to last), the 
		output MUST be in the following format:
		[a,c,b,m]
		with no white space or new lines.
		
		NOTE: if the list is empty, output empty square brackets:
		[]
		*/
		friend ostream& operator<< <T>(ostream&,LinkedList<T>&);
		
		/*
		The constructor initializes an empty list.
		*/
		LinkedList();
				
		/*
		The copy constructor.
		*/
		LinkedList(const LinkedList<T>& other);
		
		/*
		The overloaded assignment operator.
		*/
		LinkedList<T>& operator=(const LinkedList<T>& other);
		
		/*
		Creates a dynamically allocated deep copy of the object and returns
		a pointer to it
		*/
		virtual LinkedList<T>* clone();
		
		/*
		The destructor.
		*/
		virtual ~LinkedList();
		
		/*
		Inserts an element at the given index.  The following holds 
		for this function:
		
		1.) It is valid to insert at index 0 of an empty list.
		
		2.) It is valid to insert at the index returned by size().  Simply
		    append the element to the back of the list.
		
		3.) Only indices between 0 and size() are valid.
		
		4.) For an invalid index, throw an exception message "invalid index".
		*/
		virtual void insert(int index, T element);
		
		/*
		Removes and returns the element at the index passed in 
		as a parameter. If an invalid index is provided,
		throw the string "No element found".
		*/
		virtual T remove(int index);		
		
		/*
		Returns the element at the index passed in 
		as a parameter. The element is not removed from the data structure.
		If an invalid index is given, throw the string "No element found".
		*/
		virtual T get(int index) const;
		
		/*
		Returns the first element from the list, i.e. element stored at head.
		If the list is empty, throw the string "No element found".
		*/
		virtual const T& getFirst() const;
		
		/*
		Returns the last element from the list.
		If the list is empty, throw the string "No element found".
		*/
		virtual const T& getLast() const;

		/*
		Returns the index of the first (head) element in the list.
		If the list is empty, throw the string "No element found".
		*/
		virtual int getIndexFirst() const;
		
		/*
		Returns the index of the last element in the list.
		If list is empty, throw the string "No element found".
		*/
		virtual int getIndexLast() const;	

		/*
		Returns true if the list is empty, and false
		otherwise.
		*/
		virtual bool isEmpty();
		
		/*
		Removes all of the nodes from the list.  After this function has
		been called on a LinkedList object, the list must be empty.
		*/
		virtual void clear();
		
		/*
		Returns the head, not the element at the head.
		*/
		Node<T>* getLeader();
		
	protected:
		ostream& print(ostream& os);

	private:	
		/* 
		   Use this function to calculate the total number of nodes in the list.
		 */
		int size() const;
	
		/* 
		   The first node in the list (index 0 would always correspond to the head)
		*/
		Node<T>* head;
};

#include "linkedList.cpp"

#endif
