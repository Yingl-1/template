#include"class.hpp"

void text01();

int main() {

	text01();

	system("pause");
	return 0;
}

void text01() {

	Node<int> aa(10);
	Node <int>bb = aa;

	for (size_t i = 0; i < 10; i++)
	{
		aa.push_back(i);
	}

	aa.pop_back();

	aa.getCapacity();
	aa.getSize();

	bb.getCapacity();
	bb.getSize();

	bb = aa;

	bb.getCapacity();
	bb.getSize(); 
}