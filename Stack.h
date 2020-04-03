#ifndef STACK_H
#define STACK_H

template <class T>
class Stack 
{
	private:
		T* data;
		int capacity;
		int top;
		void reSize(int size);
	public:
		Stack();
		Stack(const Stack<T> &);
		Stack &operator=(const Stack<T> &);
		~Stack();

		bool isEmpty();
		bool isFull();
		const int getNumberOfElements();
		void push(T);
		T pop();
		T stackTop();
};
#include "Stack.cpp"
#endif
