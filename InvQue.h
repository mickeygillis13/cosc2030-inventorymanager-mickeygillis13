#ifndef INVQUE_H
#define INVQUE_H
#include <iostream>
using namespace std;

template <class T>
class InvQue {
    private:
		struct QueueNode{
            T data;
            QueueNode* next;
        };
        QueueNode* front;
        QueueNode* rear;
    public:
    	InvQue()
		    { front = rear = nullptr; }
		~InvQue();
        void enqueue(T);
		void dequeue(T &);
		bool isEmpty();
        void display();
};

template <class T>
void InvQue<T>::enqueue(T num)
{
	QueueNode *newNode = nullptr;

	// Allocate a new node & store the item
	newNode = new QueueNode;
	newNode->data = num;
	newNode->next = nullptr;
	// If there are no nodes in the queue
	// make newNode the first node
	if (isEmpty())
	{
		front = rear = newNode;
		
	}
	else		// Otherwise, insert newNode at the end
	{
		rear->next = newNode;
		rear = newNode;
	}
}

template <class T>
void InvQue<T>::dequeue(T &num)
{
	if (isEmpty())
	{
		cerr << "Queue is empty. Cannot dequeue." << endl;
		return;
	}
	QueueNode *temp = front;
	num = front->data;
	front = front->next;
	delete temp;
	if (front == nullptr)
		rear = nullptr;
}
template <class T>
bool InvQue<T> :: isEmpty(){
	return front == nullptr;
}
template <class T>
void InvQue<T>::display() {
    QueueNode* current = front;
	int count = 1;
    while (current != nullptr) {
        cout << "\tItem " << count << ":" << endl;
        cout << "\t\tSerial number: " << current->data.getSerialNum() << endl;
        cout << "\t\tManufacture date: " << current->data.getManufactDate() << endl;
        current = current->next;
		count++;
    }
    cout << endl;
}

template <class T>
InvQue<T>::~InvQue() {
	T temp;
	while (!isEmpty()) {
		dequeue(temp);
	}
}

#endif 