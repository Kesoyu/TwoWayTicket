#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}

DoubleLinkedList::DoubleLinkedList(Data data) {
	Node* temp = new Node;
	temp->data = data;
	temp->next = nullptr;
	temp->prev = nullptr;
	head = temp;
	tail = temp;
	size = 1;
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& copy) {
	if (copy.head == nullptr) {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	else {
		head = nullptr;
		tail = nullptr;
		size = 0;
		Node* temp = new Node;
		Node* copyNode = copy.head;
		head = temp;
		head->data = copyNode->data;
		head->next = nullptr;
		head->prev = nullptr;
		tail = head;
		copyNode = copyNode->next;
		size = 1;
		while (copyNode != nullptr) {
			pushBack(copyNode->data);
			copyNode = copyNode->next;
		}
	}
}

DoubleLinkedList::~DoubleLinkedList() {
	if (head == nullptr)
		return;
	Node* temp;
	while (head != nullptr) {
		temp = head;
		head = head->next;
		delete temp;
		temp = nullptr;
	}
	head = nullptr;
	size = 0;
}

void DoubleLinkedList::printList() const {
	Node* walk = head;
	if (size == 1)
		std::cout << walk->data.Name << " " << walk->data.Surname << " " << walk->data.Age;
	else if (size == 0)
		std::cout << "Empty List";
	else
		while (walk != nullptr) {
			std::cout << walk->data.Name << " " << walk->data.Surname << " " << walk->data.Age;
			walk = walk->next;
		}
	std::cout << '\n';
}

void DoubleLinkedList::pushBack(Data data) {
	if (size == 0) {
		Node* temp = new Node;
		temp->data = data;
		temp->next = nullptr;
		temp->prev = nullptr;
		head = temp;
		tail = temp;
		size++;
	}
	else {
		Node* last = new Node;
		last->data = data;
		last->next = nullptr;
		last->prev = tail;
		tail->next = last;
		tail = last;
		size++;
	}
}

void DoubleLinkedList::pushFront(Data data) {
	if (size == 0){
		Node* temp = new Node;
		temp->data = data;
		temp->next = nullptr;
		temp->prev = nullptr;
		head = temp;
		tail = temp;
		size++;
	}
	else {
		Node* first = new Node;
		first->data = data;
		first->next = head;
		first->prev = nullptr;
		head->prev = first;
		head = first;
		size++;
	}
}

void DoubleLinkedList::popFront() {
	if (head == nullptr || size == 0) {
		return;
	}
	if (size == 1) {
		delete head;
		head = nullptr;
		tail = nullptr;
		size--;
	}
	else {
		Node* first = head;
		head = head->next;
		head->prev = nullptr;
		delete first;
		first = nullptr;
		size--;
	}
}

void DoubleLinkedList::popBack() {
	if (tail == nullptr) {
		return;
	}
	if (size == 1) {
		delete tail;
		tail = nullptr;
		head = nullptr;
		size--;
	}
	else {
		Node* last = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete last;
		last = nullptr;
		size--;
	}
}

void DoubleLinkedList::insert(int index, Data data) {
	Node* current = head;
	Node* newnode = new Node;
	Node* after;
	newnode->data = data;
	int counter = 0;
	if (index == 0) {
		pushFront(data);
		std::cout << "Value inserted in front" << '\n';
	}
	else if (index > size - 1) {
		pushBack(data);
		std::cout << "Value inserted at the back" << '\n';
	}
	else {
		while (counter != index) {
			counter++;
			if (counter == index) {
				newnode->next = current->next;
				after = newnode->next;
				after->prev = newnode;
				current->next = newnode;
				newnode->prev = current;
				size++;
			}
			else
				current = current->next;
		}
		std::cout << "Value inserted at desired position" << '\n';
	}
}

Data DoubleLinkedList::nthElement(int n) {
	if (n < 0 || n >= size) {
		std::cout << "Invalid value of n" << '\n';
		return Data::Data();
	}

	Node* temp = head;
	for (int i = 0; i < n; ++i)
		temp = temp->next;
	return temp->data;
}

std::ostream& operator<<(std::ostream& out, const DoubleLinkedList& rhs) {
	rhs.printList();
	return out;
}

DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList& copy) {
	if (copy.head == nullptr) {
		Node* temp;
		while (head != nullptr) {
			temp = head;
			head = head->next;
			delete temp;
			temp = nullptr;
		}
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	else {
		Node* temp = new Node;
		while (head != nullptr) {
			temp = head;
			head = head->next;
			delete temp;
			temp = nullptr;
		}
		head = nullptr;
		tail = nullptr;
		size = 0;
		Node* copyNode = copy.head;
		temp = new Node;
		head = temp;
		head->data = copyNode->data;
		head->next = nullptr;
		head->prev = nullptr;
		tail = head;
		copyNode = copyNode->next;
		size = 1;

		while (copyNode != nullptr) {
			pushBack(copyNode->data);
			copyNode = copyNode->next;
		}
	}
	return *this;
}

int DoubleLinkedList::Size() const {
	return size;
}