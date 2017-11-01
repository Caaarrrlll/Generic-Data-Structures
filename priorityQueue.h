#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "queue.h"
#include "linearStructure.h"

template<class T>
class PriorityQueue : public Queue<T>
{
	public:
		/*
		The constructor initializes the PriorityQueue with 
		the structure which will contain the elements.
		*/
		PriorityQueue(LinearStructure<T>* c);
		
		/*
		Copy constructor
		*/
		PriorityQueue(const PriorityQueue<T>& other);
		
		/*
		Overloaded assignment operator.
		*/
		virtual PriorityQueue<T>& operator=(const PriorityQueue<T>& other);
						
		/*
		Destructor.
		*/
		virtual ~PriorityQueue();
		
		/*
		This function removes and returns the element
		with the highest priority in the PriorityQueue.
		*/
		virtual T remove();
		
		/*
		This function returns, but does NOT remove, the
		element with the higest priority.
		*/
		virtual T next();
		
		/*
		Simply flips the max member variable.
		*/
		virtual void reverse();
		
	private:
		/*
		This flag determines whether the largest or smallest
		element in the queue is returned next.  If it is set 
		to true, then return the largest element. Otherwise
		return the smallest element.  This flag should be initialized
		to true in your constructor.
		*/
		bool max;
};

#include "priorityQueue.cpp"

#endif
