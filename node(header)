#pragma once

//This Node class is fully functional
class Node {
	int data; //Holds the data we're keeping track of
	Node *next;
	Node *prev;
	public:
	Node() {
		data = 0;
		next = NULL;
		prev = NULL;
	}
	Node(int new_data, Node *new_next, Node *new_prev) {
		data = new_data;
		next = new_next;
		prev = new_prev;
	}
	int get_data() const { return data; }
	Node *get_next() const { return next; }
	Node *get_prev() const { return prev; }
	void set_next(Node *new_next) { next = new_next; }
	void set_prev(Node *new_prev) { prev = new_prev; }
};
