#include <iostream>
#include "dynamicArray.h"
#include "linkedList.h"
#include "stack.h"
#include "queue.h"
#include "priorityQueue.h"

using namespace std;

int main() {
	// Test your implementation here
  
 	cout << "\n..::[ Dynamic Array Testing ]::..\n" << endl;
  
  DynamicArray<int> arr1(5);  
  DynamicArray<int> arr2(arr1);  
  DynamicArray<int> arr3(3);
  
  arr3 = arr2;

  arr1.insert(0,1);
	arr2.insert(1,2);
  arr3.insert(2,3);

	cout << arr1 << endl;
	cout << arr2 << endl;
	cout << arr3 << endl;
	 
	cout << "First in arr2: " << arr2.getFirst() << endl;
	cout << "Last in arr2: " << arr2.getLast() << endl;

	int val = arr1.remove(0);
	cout << val << endl;
	cout << arr1 << endl;
	if(arr1.isEmpty()) cout << "Empty!" << endl;
	else cout << "Failure!" << endl;

	try { val = arr1.remove(0); }
 	catch( char const * e ) { cout << e << endl; }

	arr3.clear();
	if(arr3.isEmpty()) cout << "Empty!" << endl;
 	else cout << "Failure!" << endl;
	cout << arr3 << endl;
	
	for(int i = 0; i < 10; i++)
    arr3.insert(i,i);
  cout << arr3 << endl;

	arr3.insert(15,15);
  cout << arr3 << endl;

	DynamicArray<int> * aPtr = arr3.clone();
	cout << *aPtr << endl;
	cout << aPtr->get(15) << endl;
	cout << *aPtr << endl;
  aPtr->insert(3,-1);
	cout << *aPtr << endl;
	cout << "First: " << aPtr->getFirst() << endl;
	cout << "Last: " << aPtr->getLast() << endl;
	aPtr->remove(aPtr->getIndexFirst());
	aPtr->remove(aPtr->getIndexLast());
	cout << *aPtr << endl;
	cout << "First: " << aPtr->getFirst() << endl;
	cout << "Last: " << aPtr->getLast() << endl;
	
  delete aPtr;
  
  cout << arr3 << endl;
  arr3.shiftToFront();
  cout << arr3 << endl;

  /////////////////////////////////////////////////////////
  
  cout << "\n..::[ Linked List Testing ]::..\n" << endl;
  
  LinkedList<int> list;
  cout << list << endl;
  list.insert(0,1);
  cout << list << endl;
  list.remove(0);
  cout << list << endl;
  list.insert(0,1);
  cout << list << endl;
  list.insert(1,2);
  cout << list << endl;
  list.insert(2,3);
  cout << list << endl;
  list.insert(1,7);
  cout << list << endl;
  list.insert(0,7);
  cout << list << endl;
  list.insert(5,7);
  cout << list << endl;
  list.remove(2);
  cout << list << endl;
  list.remove(0);
  cout << list << endl;
  list.remove(3);
  cout << list << endl;

  LinkedList<int> list2(list);
  LinkedList<int> list3;
  list3 = list2;

  list.clear();
  cout << "Copies: " << endl;
  cout << list << endl;
  cout << list2 << endl;
  cout << list3 << endl;

  if(list.isEmpty()) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  if(list3.isEmpty()) cout << "No" << endl;
  else cout << "Yes" << endl; 

  Node<int> * node = list3.getLeader();
  node->data = 55;
  cout << node->prev->data << endl;
  node->prev->data = 33;
  
  cout << "Circular + doubly: " << endl;
  cout << list3 << endl;

  LinkedList<int> * lPtr = list3.clone();
  cout << *lPtr << endl;
  cout << lPtr->get(1) << endl;
  cout << *lPtr << endl;
  delete lPtr;

  try {
    list3.insert(20, 10);
    cout << list3 << endl;
  } catch (const char * e) {
    cout << e << endl;
  }
  try {
    list3.remove(10);
  } catch (const char * e) {
    cout << e << endl;
  }

  cout << "Own testing\n";
  LinkedList<int> l = LinkedList<int>();
  //cout << "Size should be 0: " << list.size() << endl;
  cout<< "[]"<<endl;
  cout<< l << endl;
  l.insert(0, 3);
  cout<< "[3]"<<endl;
  cout<< l << endl;
  l.insert(0, 2);
  cout<< "[2,3]"<<endl;
  cout<< l << endl;
  l.insert(0, 1);//Should be (1,2,3)
  cout<< "[1,2,3]"<<endl;
  cout<< l << endl;
  l.insert(3,16);
  cout<< "[1,2,3,16]"<<endl;
  cout<< l << endl;
  
  try{
    l.insert(8,12);
  }
  catch(...){
    cout<< "[1,2,3,16]"<<endl;
    cout<< l << endl;
  }
  
  cout<<"Goodbye"<<endl;
  LinkedList<int> l2 = LinkedList<int>();
  cout<<"Assignment Test"<<endl;
  l2 = l;
  cout<< l<<endl;
  cout<< l2<<endl;
  l2.insert(1,77);
  cout<<l<<endl;
  cout<<l2<<endl;
  l2.remove(0);
  cout<<"next two should be same, testing copy constructor"<<endl;
  cout<<l2<<endl;
  LinkedList<int> l3 = LinkedList<int>(l2);
  cout<< l3<<endl;
  LinkedList<int>* l4 = l3.clone();
  l3.remove(3);
  cout<<l3<<endl;
  
  cout<<*l4<<endl;

  LinkedList<int> l5;
  for(int i = 0; i < 5; i++)
    l5.insert(0, i + 1);

  cout << l5 << endl;

  LinkedList<int> l6;
  for(int i = 0; i < 5; i++)
    l6.insert(i, i + 1);

  cout << l6 << endl;

  cout << "remove from l7\n";

  LinkedList<int> l7;
  l7 = l6;
  cout << l7 << endl;
  for(int i = 0; i < 5; i++){
    l7.remove(0);
    cout << l7 << endl;
  }
    
  l7 = l6;
  cout << l7 << endl;
  l7.clear();
  cout << l7 << endl;
  cout << l6 << endl;

  l7 = l6;
  
  for(int i = 4; i >= 0; i--){
    l7.remove(i);
    cout << l7 << endl;
  }

  cout << l7 << endl;

  ////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////
  
  cout << "\n..::[ Stack Testing ]::..\n" << endl;
  
	LinkedList<int> ll;
  DynamicArray<int> arr(1);
	
  Stack<int> s1(&ll);
  Stack<int> s2(&arr);

  //cout << arr << endl;
  //cout << ll << endl;

  for(int i = 1; i < 10; i+= 2) {
    try { 
      s1.insert(i);
      s2.insert(i*i);
    } catch (char const * e) { cout << e << endl;}
  }

  cout << "LinkedList stack: " << *(s1.getImplementation()) << endl;
  cout << "DynamicArray stack: " << *(s2.getImplementation()) << endl;
 
  cout << "LinkedList stack - next: " << s1.next() << endl;
  cout << "DynamicArray stack - next: " << s2.next() << endl;
 	
  cout << "In reverse function\n";
  s1.reverse();
  s2.reverse();
  
  cout << "Reversed: " << endl;
  cout <<  *(s1.getImplementation()) << endl;
  cout <<  *(s2.getImplementation()) << endl;
  
  cout << "Empty the linkedList stack: " << endl;
  while(!s1.isEmpty()) {
    cout << s1.remove() << endl;    
    cout <<  *(s1.getImplementation()) << endl;
  }

  cout << "Empty the dynamicArray stack: " << endl;
  while(!s2.isEmpty()) {
    cout << s2.remove() << endl;    
    cout <<  *(s2.getImplementation()) << endl;
  }

  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  cout << "own testing\n";
  s1.insert(1);
  s1.insert(2);
  s1.insert(3);
  s1.insert(4);
  s1.insert(5);

  cout << "S1: " <<  *(s1.getImplementation()) << endl;

  Stack<int> s3(s1);
  cout << "S3: copy " << *(s3.getImplementation()) << endl;

  while(!s1.isEmpty()) {
    cout << s1.remove() << endl;    
    cout <<  *(s1.getImplementation()) << endl;
  }
  cout << "S3: copy " << *(s3.getImplementation()) << endl;

  s3.reverse();
  cout << "reverse: " << *(s3.getImplementation()) << endl;

  Stack<int> s4 = s3;

  cout << "S4: " <<  *(s4.getImplementation()) << endl;
  while(!s3.isEmpty()) {
    s3.remove();    
  }
  cout << "S3: " <<  *(s3.getImplementation()) << endl;
  cout << "S4: " <<  *(s4.getImplementation()) << endl;

  cout << "S4 next: ";
  for(int i = 0; i < 5; i++)
    cout << s4.next() << endl;

  s4.insert(6);
  cout << "S4: " <<  *(s4.getImplementation()) << endl;
  cout << s4.next() << endl;
 
  //////////////////////////////////////////////////////////////

  cout << "\n..::[ Queue Testing ]::..\n" << endl;
  
  Queue<int> q1(&ll);
  Queue<int> q2(&arr);

  for(int i = 1; i < 10; i+= 2) {
    q1.insert(i);
    q2.insert(i*i);
  }

  cout << "LinkedList queue: " << *(q1.getImplementation()) << endl;
  cout << "DynamicArray queue: " << *(q2.getImplementation()) << endl;
  
  cout << "LinkedList queue - next: " << q1.next() << endl;
  cout << "DynamicArray queue - next: " << q2.next() << endl;
  
  q1.reverse();
  q2.reverse();
  
  cout << "Reversed: " << endl;
  cout <<  *(q1.getImplementation()) << endl;
  cout <<  *(q2.getImplementation()) << endl;

  cout << "Empty the linkedList queue: " << endl;
  while(!q1.isEmpty()) {
    cout << q1.remove() << endl;    
    cout <<  *(q1.getImplementation()) << endl;
  }
  cout << "Empty the dynamicArray queue: " << endl;
  while(!q2.isEmpty()) {
    cout << q2.remove() << endl;    
    cout <<  *(q2.getImplementation()) << endl;
  }
  
  //////////////////////////////////////////////////////////////

  cout << "\n..::[ Priority Queue Testing ]::..\n" << endl;
  

  PriorityQueue<int> pq1(&ll);
  PriorityQueue<int> pq2(&arr);

  pq1.insert(9);
  pq1.insert(19);
  pq1.insert(3);
  pq1.insert(6);
  pq1.insert(8);
  pq1.insert(2);
  pq1.insert(5);

  cout << "LinkedList priority queue: " << *(pq1.getImplementation()) << endl;

  pq2.insert(9);
  pq2.insert(19);
  pq2.insert(3);
  pq2.insert(6);
  pq2.insert(8);
  pq2.insert(2);
  pq2.insert(5);

  cout << "DynamicArray priority queue: " << *(pq2.getImplementation()) << endl;
  
  cout << "LinkedList priority queue - next: " << pq1.next() << endl;
  cout << "DynamicArray priority queue - next: " << pq2.next() << endl;
  
  pq1.reverse();
  pq2.reverse();
  
  cout << "Reversed: " << endl;
  cout << "LinkedList priority queue - next: " << pq1.next() << endl;
  cout << "DynamicArray priority queue - next: " << pq2.next() << endl;
  
  cout <<  *(pq1.getImplementation()) << endl;
  cout <<  *(pq2.getImplementation()) << endl;

  pq1.insert(99);
  pq1.insert(1);

  pq2.insert(99);
  pq2.insert(1);

  cout << "whut\n";
  
  cout << "LinkedList priority queue - next: " << pq1.next() << endl;
  cout << "DynamicArray priority queue - next: " << pq2.next() << endl;
  pq1.reverse();
  pq2.reverse();
  
  cout << "Reversed: " << endl;
  cout << "LinkedList priority queue - next: " << pq1.next() << endl;
  cout << "DynamicArray priority queue - next: " << pq2.next() << endl;

  cout << "Empty the linkedList priority queue: " << endl;
  while(!pq1.isEmpty()) {
    cout << pq1.remove() << endl;    
    cout <<  *(pq1.getImplementation()) << endl;
  }
  cout << "Empty the dynamicArray priority queue: " << endl;
  while(!pq2.isEmpty()) {
    cout << pq2.remove() << endl;    
    cout <<  *(pq2.getImplementation()) << endl;
  }
 
  return 0;
}