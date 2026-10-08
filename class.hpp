
#pragma once
#include<iostream>
#include<cassert>
#include<cstdlib>

template <class T>
class Node {

public:

	Node(int capa);
	Node(const Node<T>& arry);
	Node<T>& operator=(const Node<T>& arry);
	T& operator[](int index);
	void push_back(const T& value);
	void pop_back();
	int getCapacity();
	int getSize();
	~Node();


private:


	T * arr;
	int size;
	int capacity;

};


//构造
template<class T>
Node<T>::Node(int capa) {
	std::cout << "构造函数" << std::endl;
	this->size = 0;
	this->capacity =capa;
	this->arr = new T[capacity];
}

//析构
template<class T>
Node<T>::~Node() {
	std::cout << "析构函数" << std::endl;
	delete[] arr;
	this->arr = nullptr;
	this->size = 0;
	this->capacity = 0;
}

//拷贝构造
template<class T>
Node<T>::Node(const Node<T>& arry) {
	std::cout << "拷贝构造" << std::endl;
	this->size = arry.size;
	this->capacity = arry.capacity;
	this->arr = new T[arry.capacity];

	assert(this->size <= this->capacity);

	for (size_t i = 0; i <this-> size; i++) {
		this->arr[i] = arry.arr[i];
	}
}

//重载赋值运算符
template<class T>
Node<T>& Node<T>::operator=(const Node<T>& arry) {
	if (this == &arry) {
		return *this;
	}
	delete[] this->arr;
	this->arr = nullptr;
	this->size = arry.size;
	this->capacity = arry.capacity;
	this->arr = new T[capacity]; 

	assert(this->size <= this->capacity);

	for (size_t i = 0; i < this->size; i++) {
		this->arr[i] = arry.arr[i];
	}
	return *this;
}

//尾插
template<class T>
void Node<T>::push_back(const T& value) {

	if (size>=capacity)
	{
		std::cout << "容量已满，无法插入" << std::endl;
		return;
	}

	this->arr[this->size] = value;

	size++;

}

//尾删
template<class T>
void Node<T>::pop_back() {
	if (size == 0) {
		std::cout << "数组为空，无法删除" << std::endl;
		return;
	}
	this->arr[this->size - 1].~T();
	size--;
}

//重载中括号
template <class T>
T& Node<T>::operator[](int index){

	return this->arr[index];

}

//容量
template <class T>
int Node<T>::getCapacity() {
	std::cout << "容量" <<this->capacity<< std::endl;
	return this->capacity;
}

//大小
template <class T>
int Node<T>::getSize() {
	std::cout << "大小" <<this->size<< std::endl;
	return this->size;

}
