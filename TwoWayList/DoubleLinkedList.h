#include <iostream>
#pragma once

struct Data {
public:
	std::string Name;
	std::string Surname;
	int Age;
	Data(std::string n = "BRAK", std::string s = "BRAK", int a = -1) : Name(n), Surname(s), Age(a) {};
};

struct Node {
	Data data;
	Node* next;
	Node* prev;
};


class DoubleLinkedList {
private:
	Node* head;
	Node* tail;
	int size;
public:
	DoubleLinkedList();
	DoubleLinkedList(Data data);
	DoubleLinkedList(const DoubleLinkedList& rhs);
	~DoubleLinkedList();
	void printList()const;
	void pushBack(Data data);
	void pushFront(Data data);
	void popFront();
	void popBack();
	void insert(int index, Data data);
	Data nthElement(int);
	int Size() const;
	friend std::ostream& operator<<(std::ostream& out, const DoubleLinkedList& rhs);
	DoubleLinkedList& operator=(const DoubleLinkedList& rhs);
};