//Provide the implementation for the DynamicArray class in this file.
//u14177553 Francois Venter
#include <iostream>

using namespace std;

template<class T>
ostream& operator<<(ostream& out, DynamicArray<T>& da){
	out << "[";

	for(int i = 0; i < da.size - 1; i++){
		if(da.elements[i] == NULL)
			out << "*,";
		else
			out << da.get(i) << ",";
	}

	if(da.elements[da.size - 1] == NULL)
		out << "*]";
	else
		out << da.get(da.size - 1) << "]";

	return out;
}

template<class T>
DynamicArray<T>::DynamicArray(int s){
	if(s <= 0)
		throw "Invalid size provided";
	else{
		size = s;
		numElements = 0;
		elements = new T *[size];

		for(int i = 0; i < size; i++)
			elements[i] = NULL;
	}
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other){
	size = other.size;
	numElements = other.numElements;

	elements = new T *[size];

	for(int i = 0; i < size; i++){
		if(other.elements[i] == NULL)
			elements[i] = NULL;
		else
			this->insert(i, other.get(i));
	}
}

template<class T>
bool DynamicArray<T>::isEmpty(){
	//false = elements in array
	//true = empty
	bool result = true;
	for(int i = 0; i < size; i++){
		if(elements[i] != NULL){
			result = false;
		}
	}
	return result;
}

template<class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other){
	delete [] elements;

	elements = new T * [other.size];
	size = other.size;
	numElements = other.numElements;

	for(int i = 0; i < size; i++){
		if(other.elements[i] == NULL)
			elements[i] = NULL;
		else
			this->insert(i, other.get(i));
	}

	return *this;
}

template<class T>
DynamicArray<T>* DynamicArray<T>::clone(){
	DynamicArray * da = new DynamicArray(*this);

	return da; 
}

template<class T>
DynamicArray<T>::~DynamicArray(){
	delete [] elements;
	elements = NULL;
}

template<class T>
void DynamicArray<T>::insert(int index, T element){
	//cout << element << endl;
	if(index < 0)
		throw "invalid index";
	else if(index < size){
		if(elements[index] == NULL){
			elements[index] = new T(element);
			numElements++;
		}
		else{
			resize(size + 1);
		
			for(int i = size - 1; i > index; i--){
				if(elements[i - 1] != NULL)
					elements[i] = new T(*elements[i - 1]);
				else
					elements[i] = NULL;
			}
	
			elements[index] = new T(element);
			numElements++;
		}	
	}
	else{
		int newS = index + 1;
		resize(newS);

		for(int i = newS - 1; i > index; i--){
			elements[i] = new T(*elements[i - 1]);
		}

		elements[index] = new T(element);
		numElements++;
	}
}

template<class T>
T DynamicArray<T>::remove(int index){
	if(elements[index] == NULL)
		throw "No element found";
	else{
		T temp = *elements[index];
		elements[index] = NULL;
		for(int i = index; i < size; i++){
			if(elements[i + 1] == NULL){
				elements[i] = NULL;
			}
			else{
				elements[i] = elements[i + 1];
			}
		}
		elements[size - 1] = NULL;

		return temp;
	}
}

template<class T>
T DynamicArray<T>::get(int index) const{
	if(elements[index] == NULL)
		throw "No element found";
	else{
		return *elements[index];
	}
}

template<class T>
const T& DynamicArray<T>::getFirst() const{
	T * result;
	if(elements[0] != NULL){
		result = new T(*elements[0]);
		return *result;
	}
	else{
		for(int i = 1; i < size; i++){
			if(elements[i] != NULL){
				result = new T(*elements[i]);
				break;
			}
		}
		if(result == 0)
			throw "No element found";
		else
			return *result;
	}
}

template<class T>
const T& DynamicArray<T>::getLast() const{
	T * result;
	if(elements[size - 1] != NULL){
		result = new T(*elements[size - 1]);
		return *result;
	}
	else{
		for(int i = size - 2; i >= 0; i--){
			if(elements[i] != NULL){
				result = new T(*elements[i]);
				break;
			}
		}
		if(result == 0)
			throw "No element found";
		else
			return *result;
	}
}

template<class T>
int DynamicArray<T>::getIndexFirst() const{
	int result = 0;

	if(size == 0)
		throw "No element found";
	else if(elements[0] != NULL){
		return result;
	}
	else{
		for(int i = 1; i < size; i++){
			if(elements[i] != NULL){
				result = i;
				break;
			}
		}
		return result;
	}
}

template<class T>
int DynamicArray<T>::getIndexLast() const{
	int result = 0;
	if(elements[size - 1] != NULL){
		result = size - 1;
		return result;
		
	}
	else{
		for(int i = size - 2; i >= 0; i--){
			if(elements[i] != NULL){
				result = i;
				break;
			}
		}
		if(result == (size - 1))
			throw "No element found";
		else
		
			return result;
	}

	
}

template<class T>
void DynamicArray<T>::clear(){
	for(int i = 0; i < size; i++){
		delete this->elements[i];
		elements[i] = NULL;
		numElements--;
	}
}

template<class T>
void DynamicArray<T>::shiftToFront(){
	if(!isEmpty()){
		int counter = 0;
		T ** tempElems = new T *[size];
		
		for(int i = 0; i < size; i++){
			tempElems[i] = NULL;
		}
		
		for(int i = 0; i < size; i++){
			if(elements[i] != NULL){
				tempElems[counter] = new T(*elements[i]);
				counter++;
			}
		}

		elements = new T *[size];

		for(int i = 0; i < size; i++){
			if(tempElems[i] == NULL){
				elements[i] = NULL;
			}
			else{
				elements[i] = new T(*tempElems[i]);
			}
		}
	}
}

template<class T>
ostream& DynamicArray<T>::print(ostream& os){
	os << "[";
	
	for(int i = 0; i < size - 1; i++){
		if(elements[i] == NULL)
			os << "*,";
		else
			os << get(i) << ",";
	}

	if(elements[size - 1] == NULL)
		os << "*]";
	else
		os << get(size - 1) << "]";

	return os;
}

template<class T>
void DynamicArray<T>::resize(int newSize){
	T ** tempElems = new T *[newSize];

	for(int i = 0; i < size; i++){
		if(elements[i] == NULL){
			tempElems[i] = NULL;
		}
		else{
			tempElems[i] = new T(*elements[i]);
		}
	}

	elements = new T *[newSize];

	for(int i = 0; i < size; i++){
		if(tempElems[i] == NULL){
			elements[i] = NULL;
		}
		else{
			elements[i] = new T(*tempElems[i]);
		}
	}

	size = newSize;
}