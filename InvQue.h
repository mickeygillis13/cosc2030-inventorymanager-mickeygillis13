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
};

#endif 