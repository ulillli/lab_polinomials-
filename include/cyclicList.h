#pragma once
template<class T>
class cyclicList {
	struct Node {
		Node* next;
		T value;
		Node(Node* n, T data) {
			next = n;
			value = data;
		}
	};
	Node* first = nullptr;
	cyclicList(size_t n = 0) {
		if (n < 0) {
			throw "Incorrect size of list\n";
		}
		else {
			Node* tmp = new Node(first, 0); //a pointer to the first created Node
			first = tmp;
			n--;
			while (n) {
				Node* newNode = new Node(first, 0);
				first = newNode;
				n--;
			}
			tmp->next = first; //the first created Node point to the head 
		}
	}
	cyclicList(const cyclicList& other) {
		Node* curr2 = other.first;
		if (curr2 != nullptr) {
			Node* curr1 = new Node(this->first, curr2.value);
			Node* tmpOther = curr2;  //the head of the other list
			Node* tmpThis = curr1; //the head of this list
			curr2 = curr2->next;
			while (curr2 != tmpOther) {
				Node* nextNode = new Node(nullptr, curr2.value);
				curr1->next = nextNode;
				curr1 = nextNode;
				curr2 = curr2->next;
			}
			curr1->next = tmpThis; //the end of the new list points to the head 
		}
	}
};
