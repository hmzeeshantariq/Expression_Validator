#ifndef STACK_CPP
#define STACK_CPP
#include "Stack.h"
#include <iostream>

template <class T>
void Stack<T>::reSize(int size) {
	T* arr = new T[size];
	for(int i = 0; i < top; i++)
		arr[i] = data[i];

	delete[] data;
	data = arr;
	arr = nullptr;
}


template <class T>
Stack<T>::Stack() {
	capacity = 1;
	data = new T[capacity];
	top = 0;
}

template <class T>
Stack<T>::Stack(const Stack<T>& ref) {
	if (!(this->isEmpty())) {
		this->~Stack();
	}
	this->capacity = ref.capacity;
	this->data = new T[capacity];
	this->top = ref.top;
	for (int i = 0; i < ref.top; i++) {
		this->data[i] = ref.data[i];
	}
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& ref) {
	if (!(this->isEmpty())) {
		this->~Stack();
	}
	this->capacity = ref.capacity;
	this->data = new T[this->capacity];
	this->top = ref.top;
	for (int i = 0; i < ref.top; i++) {
		this->data[i] = ref.data[i];
	}
	return *this;
}

template <class T>
Stack<T>::~Stack() {
	if (!data)
		return;
	delete[]data;
	data = nullptr;
}

template <class T>
bool Stack<T>::isEmpty(){
	return top == 0;
}

template <class T>
bool Stack<T>::isFull() {
	return top == capacity;
}

template <class T>
const int Stack<T>::getNumberOfElements() {
	return top;
}

template <class T>
void Stack<T>::push(T val) {
	if (isFull()) {
		capacity*=2;
		reSize(capacity);
	}
	this->data[top++] = val;
}

template <class T>
T Stack<T>::pop() {
	if (top <= capacity / 2 && top > 1){
		capacity /=2;
		reSize(capacity);
	}
	try {
		return data[--top];
	}
	catch(std::exception &exc){
		std::cerr << exc.what();
	}
}

template <class T>
T Stack<T>::stackTop() {
	try {
		return data[top - 1];
	}
	catch (std::exception &exc) {
		std::cerr << exc.what();
	}
}

#endif
