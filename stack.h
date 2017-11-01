#ifndef STACK_H
#define STACK_H

#include "orderedContainer.h"
#include "linearStructure.h"

template<class T>
class Stack : public OrderedContainer<T>
{
	public:
		/*
		The constructor initializes the stack with the
		structure which will contain the elements. Remember to
		make a deep copy of the input structure.
		*/
		Stack(LinearStructure<T>* c);
		
		/*
		Copy constructor
		*/
		Stack(const Stack<T>& other);
		
		/*
		Overloaded assignment operator.
		*/
		Stack<T>& operator=(const Stack<T>& other);
		
		/*
		Destructor.
		*/
		virtual ~Stack();
		
		/*
		This function pops and returns the element 
		on the top of the Stack.
		*/
		virtual T remove();
		
		/*
		This function returns, but does NOT remove, the
		element at the top of the stack.
		*/
		virtual T next();
		
		/*
		This function pushes the element sent in as a 
		parameter onto the top of the Stack.
		*/
		virtual void insert(T el);
		
		/*
		This function reverses the order of the elements
		in the stack.  For example, if the stack contains the 
		elements w, x, y and z, where w is at the top of the
		stack, then the stack should be z, y, x, w after the 
		reverse with z now being at the top of the stack.
		*/
		virtual void reverse();
};

#include "stack.cpp"

#endif
