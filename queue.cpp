//Provide the implementation for the Queue class in this file.
//u14177553 Francois Venter

#include <iostream>

using namespace std;

template <class T>
Queue<T>::Queue(LinearStructure<T>* c) : OrderedContainer<T>(c){}

template <class T>
Queue<T>::Queue(const Queue<T>& other) : OrderedContainer<T>(other){}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other){
	this->dataStructure = other.dataStructure->clone();
	return *this;
}

template <class T>
Queue<T>::~Queue(){
	this->dataStructure->clear();
}

template <class T>
T Queue<T>::remove(){
	T result = this->dataStructure->remove(this->dataStructure->getIndexFirst());
	return result;
}

template <class T>
T Queue<T>::next(){
	T result = this->dataStructure->get(this->dataStructure->getIndexFirst());
	return result;
}

template <class T>
void Queue<T>::insert(T el){
	if(this->dataStructure->isEmpty()){
		this->dataStructure->insert(0, el);
	}
	else{
		this->dataStructure->insert(this->dataStructure->getIndexLast() + 1, el);
	}
}

template <class T>
void Queue<T>::reverse(){
	int i = 0;
	LinearStructure<T> * temp = this->dataStructure->clone();

	this->dataStructure->clear();

	while(!temp->isEmpty()){
		this->dataStructure->insert(i, temp->remove(temp->getIndexLast()));
		i++;
	}
}