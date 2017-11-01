#ifndef LINEARSTRUCTURE_H
#define LINEARSTRUCTURE_H

#include <iostream>

using namespace std;

template<class T>
class LinearStructure;

template<class T>
ostream& operator<<(ostream&,LinearStructure<T>&);

template<class T>
class LinearStructure
{
	public:
		/*
		Calls print() function to print the data
		*/
		friend ostream& operator<< <T>(ostream& os,LinearStructure<T>& l);
		
		/*
		Creates a dynamically allocated deep copy of the object and returns
		a pointer to it.
		*/
		virtual LinearStructure<T>* clone() = 0;
		
		/*
		Virtual destructor
		*/
		virtual ~LinearStructure(){}

		/*
		Inserts an element at the given index.  
		See subclasses for more details.
		*/
		virtual void insert(int index, T element) = 0;
		
		/*
		Removes and returns an element from the index passed
		as a parameter.  See subclasses for more details.
		*/
		virtual T remove(int index) = 0;

		/*
		Returns an element from the index passed
		as a parameter.  See subclasses for more details.
		*/
		virtual T get(int index) const = 0;
		
		/*
		Returns the first element from the structure.
		See subclasses for more details.
		*/
		virtual const T& getFirst() const = 0;
		
		/*
		Returns the last element from the structure.
		See subclasses for more details.
		*/
		virtual const T& getLast() const = 0;

		/*
		Returns the index of the first element in the structure.
		See subclasses for more details.
		*/
		virtual int getIndexFirst() const = 0;
		
		/*
		Returns the index of the last element in the structure.
		See subclasses for more details.
		*/
		virtual int getIndexLast() const = 0;
						
		/*
		Returns true if the structure is empty, and false
		otherwise.
		*/
		virtual bool isEmpty() = 0;
		
		/*
		Empties out the structure. See subclasses for more details.
		*/
		virtual void clear() = 0;	
		
	protected:
		
		/*
		Stream operators are not members of a class and are
		therefore not inherited and cannot be overridden as
		subclass members.  See the implementation of this
		class' stream operator below.  The print function
		in each subclass should be implemented as you would
		an overloaded stream operator.
		*/
		virtual ostream& print(ostream& os) = 0;
	
};

template<class T>
ostream& operator<<(ostream& os,LinearStructure<T>& l)
{l.print(os); return os;}
 
#endif
