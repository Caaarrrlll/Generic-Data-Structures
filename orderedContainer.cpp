// Implement non-pure virtual functions of OrderedContainer here
//u14177553 Francois Venter

#include <iostream>
#include <typeinfo>

using namespace std;

template <class T>
OrderedContainer<T>::OrderedContainer(LinearStructure<T>* c){
	this->dataStructure = c->clone();
}

template <class T>
OrderedContainer<T>::OrderedContainer(const OrderedContainer<T>& other){
	this->dataStructure = other.dataStructure->clone();
}

template <class T>
OrderedContainer<T>& OrderedContainer<T>::operator=(const OrderedContainer<T>& other){
	this->dataStructure = other.dataStructure->clone();
	return *this;
}

template <class T>
OrderedContainer<T>::~OrderedContainer(){
	this->dataStructure->clear();
	delete this->dataStructure;
	this->dataStructure = NULL;
}

template <class T>
bool OrderedContainer<T>::isEmpty(){
	return this->dataStructure->isEmpty();
}

template <class T>
LinearStructure<T>* OrderedContainer<T>::getImplementation(){
	return this->dataStructure;
}