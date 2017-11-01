#ifndef NODE_H
#define NODE_H

/*
The Node class for the linked list.
*/
template<class T>
class Node
{
	public:
		Node(T d, Node<T>* n = 0, Node<T>* p = 0)
		{
			data = d;
			next = n;
			prev = p;
		}
		
		~Node()
		{
			next = 0;
			prev = 0;
		}
		
		//The data stored in the node
		T data;
		//The next node in the list
		Node<T>* next;
		//The previous node in the list
		Node<T>* prev;
};

#endif
