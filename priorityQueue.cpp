//Provide the implementation for the PriorityQueue class in this file.
#include <iostream>

using namespace std;

template <class T>
PriorityQueue<T>::PriorityQueue(LinearStructure<T>* c) : Queue<T>(c){
	max = true;
}

template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& other) : Queue<T>(other){
	max = true;
}

template <class T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& other){
	this->dataStructure = other.dataStructure->clone();
	this->max = new bool(other.max);
	return *this;
}

template <class T>
PriorityQueue<T>::~PriorityQueue(){
	this->dataStructure->clear();
}

template <class T>
T PriorityQueue<T>::remove(){
	if(max){
		T result = this->dataStructure->remove(this->dataStructure->getIndexLast());
		return result;
	}
	else{
		T result = this->dataStructure->remove(this->dataStructure->getIndexFirst());
		return result;
	}
}

template <class T>
T PriorityQueue<T>::next(){
	if(!max){
		T result = this->dataStructure->get(this->dataStructure->getIndexLast());
		return result;
	}
	else{
		T result = this->dataStructure->get(this->dataStructure->getIndexFirst());
		return result;
	}
}

template <class T>
void PriorityQueue<T>::reverse(){
	if(max){
		max = false;
	}
	else{
		max = true;
	}
}
