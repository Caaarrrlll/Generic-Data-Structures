//Provide the implementation for the Stack class in this file.
#include <iostream>

using namespace std;

template <class T>
Stack<T>::Stack(LinearStructure<T>* c) : OrderedContainer<T>(c){}

template <class T>
Stack<T>::Stack(const Stack<T>& other) : OrderedContainer<T>(other){}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other){
	this->dataStructure = other.dataStructure->clone();
	return *this;
}

template <class T>
Stack<T>::~Stack(){
	this->dataStructure->clear();
}

template <class T>
T Stack<T>::remove(){
	T result = this->dataStructure->remove(this->dataStructure->getIndexLast());
	return result;
}

template <class T>
T Stack<T>::next(){
	T result = this->dataStructure->get(this->dataStructure->getIndexLast());
	return result;
}

template <class T>
void Stack<T>::insert(T el){
	if(this->dataStructure->isEmpty()){
		this->dataStructure->insert(0, el);
	}
	else{
		this->dataStructure->insert(this->dataStructure->getIndexLast() + 1, el);
	}
}

template <class T>
void Stack<T>::reverse(){
	int i = 0;
	LinearStructure<T> * temp = this->dataStructure->clone();

	this->dataStructure->clear();

	while(!temp->isEmpty()){
		this->dataStructure->insert(i, temp->remove(temp->getIndexLast()));
		i++;
	}
}
