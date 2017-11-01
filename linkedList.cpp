//Provide the implementation for the LinkedList class in this file.
#include <iostream>

using namespace std;

template<class T>
ostream& operator<<(ostream& out,LinkedList<T>& ll){
	out << "[";

	if(ll.head == NULL){
		out << "]";
	}
	else if(ll.head->next == NULL){
		out << ll.head->data << "]";
	}
	else{
		Node<T> * t = ll.head;

		while(t->next != ll.head){
			out << t->data << ",";
			t = t->next;
		}
	
		out << t->data << "]";
	}

	return out;
}

template<class T>
LinkedList<T>::LinkedList(){
	head = NULL;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other){
	head = NULL;
	if(other.head){
		int counter = 0;
		Node<T> * oCurr = other.head;
		insert(counter, oCurr->data);
		oCurr = oCurr->next;
		while(oCurr != other.head){
			counter++;
			insert(counter, oCurr->data);
			oCurr = oCurr->next;
		}
	}
	else
		head = NULL;
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other){
	while(head)
		remove(0);

	if(other.head){
		int counter = 0;
		Node<T> * oCurr = other.head;
		insert(counter, oCurr->data);
		oCurr = oCurr->next;
		while(oCurr != other.head){
			counter++;
			insert(counter, oCurr->data);
			oCurr = oCurr->next;
		}
	}
	else
		head = NULL;

	return *this;
}

template<class T>
int LinkedList<T>::size() const{
	int result = 0;
	
	if(head == NULL){
		result = 0;
		return result;
	}
	else if(head->next == head){
		result = 1;
		return result;
	}
	else{
		Node<T> * t = head;
		result++;
		while(t->next != head){
			result++;
			t = t->next;
		}

		return result;
	}	
}

template<class T>
LinkedList<T>* LinkedList<T>::clone(){
	LinkedList<T> * LL = new LinkedList<T>(*this);
	return LL;
}

template<class T>
LinkedList<T>::~LinkedList(){
	while(head != NULL){
		remove(0);
	}
}

template<class T>
void LinkedList<T>::insert(int index, T element){
	if(index < 0 || index > size()){
		throw "invalid index";
	}
	else if(size() == 0){
		Node<T> * newNode = new Node<T>(element);
		head = newNode;
		head->next = newNode;
		head->prev = newNode;
	}
	else{
		if(index == 0){
			Node<T> * newNode = new Node<T>(element, head, head->prev);
			head->prev->next = newNode;
			head->prev = newNode;
			head = newNode;
		}
		else{
			Node<T> * curr = head;
			int counter = 0;

			while(counter < index){
				curr = curr->next;
				counter++;
			}
	
			Node<T> * newNode = new Node<T>(element, curr, curr->prev);
			curr->prev->next = newNode;
			curr->prev = newNode;
		}
	}
}

template<class T>
T LinkedList<T>::remove(int index){
	if(index < 0 || index > LinkedList::size() || head == NULL)
		throw "No element found";
	else{
		T temp;
		
		if(index == 0 && head->next == head){
			temp = head->data;
			delete head;
			head = NULL;
		}
		else if(index == 0){
			temp = head->data;
			Node<T> * t = head;
			head->prev->next = head->next;
			head->next->prev = head->prev;
			head = t->next;
			delete t;
		}
		else{
			Node<T> * t = head;

			for(int i = 0; i < index; i++){
				t = t->next;
			}

			temp = t->data;

			t->prev->next = t->next;
			t->next->prev = t->prev;
			delete t;
		}

		return temp;
	}
}

template<class T>
T LinkedList<T>::get(int index) const{
	int size = LinkedList::size();
	
	if((index < 0)||(index >= size))
		throw "No element found";
	else{
		Node<T> * t = head;

		for(int i = 0; i < index; i++)
			t = t->next;

		return t->data;
	}
}

template<class T>
const T& LinkedList<T>::getFirst() const{
	if(head == NULL)
		throw "No element found";
	else
		return head->data;
}

template<class T>
const T& LinkedList<T>::getLast() const{
	if(head == NULL)
		throw "No element found";
	else if(head->next == head){
		return head->data;
	}
	else{
		return head->prev->data;
	}
}

template<class T>
int LinkedList<T>::getIndexFirst() const{
	if(head == NULL)
		throw "No element found";
	else
		return 0;
}

template<class T>
int LinkedList<T>::getIndexLast() const{
	if(head == NULL)
		throw "No element found";
	else
		return (LinkedList::size() - 1);
}

template<class T>
bool LinkedList<T>::isEmpty(){
	if(head == NULL)
		return true;
	else
		return false;
}

template<class T>
void LinkedList<T>::clear(){
	while(head)
		remove(0);
}

template<class T>
Node<T>* LinkedList<T>::getLeader(){
	if(head)
		return head;
	else
		return NULL;
}

template<class T>
ostream& LinkedList<T>::print(ostream& os){
	os << "[";
	
		if(head == NULL){
			os << "]";
		}
		else if(head->next == NULL){
			os << head->data << "]";
		}
		else{
			Node<T> * t = head;
	
			while(t->next != head){
				os << t->data << ",";
				t = t->next;
			}
		
			os << t->data << "]";
		}
	
		return os;
}
