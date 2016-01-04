#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <vector>
using namespace std;

void die() {
	cout << "BAD INPUT\n";
	exit(EXIT_FAILURE);
}	

//template <class T>
class Stack {
	private:
		vector <int> vec;
	public:

		void push(int data){
			vec.push_back(data);
		}
		void pop(){
			vec.pop_back();
		}
		int top(){
			return vec.back();
		}
		int size(){
			return vec.size();
		}
		bool empty(){
			if (vec.empty()) return true;
			else return false;
		}
};

int main() {
	int operand;
	char operat;
	bool seen_an_e = false;
	Stack my_stack;
	while (cin) {
		cin >> ws; //Eat whitespace
		int c = cin.peek(); //Peek at next letter to read
		if (c == EOF) break; 
		if (!isdigit(c)) { //Should be +,-,*,/,%,^,E
			cin >> operat;
			//YOU: Code this section
			int first = 0, second = 0, tmp = 0;
			
		if(operat != 'E' && my_stack.size() < 2) die();	
			switch(operat){
				case '+': {
					first = my_stack.top();
						my_stack.pop();
					second = my_stack.top();
						my_stack.pop();
					tmp = second + first;
					my_stack.push(tmp);
					break;
				}
				case '-': {
					first = my_stack.top();
						my_stack.pop();
					second = my_stack.top();
						my_stack.pop();
					tmp = second - first;
					my_stack.push(tmp);
					break;
				}
				case '*': {
					first = my_stack.top();
						my_stack.pop();
					second = my_stack.top();
						my_stack.pop();
					tmp = second * first;
					my_stack.push(tmp);
					break;
				}
				case '/': {
					first = my_stack.top();
						my_stack.pop();
					if(first == 0) die();
					second = my_stack.top();
						my_stack.pop();
					tmp = second / first;
					my_stack.push(tmp);
					break;
				}
				case '%': {
					first = my_stack.top();
						my_stack.pop();
					if(first == 0) die();
					second = my_stack.top();
						my_stack.pop();
					tmp = second % first;
					my_stack.push(tmp);
					break;
				}
				case '^': {
					first = my_stack.top();
						my_stack.pop();
					second = my_stack.top();
						my_stack.pop();
					tmp = pow(second,first);
					my_stack.push(tmp);
					break;
				}
				case 'E': {
					if(my_stack.size() == 1){
						cout << my_stack.top() << endl;
						my_stack.pop();
						seen_an_e = true;
					}
					else die();
				}
			}


		} else { //isdigit(c)
			cin >> operand;
			//YOU: Code this section
			my_stack.push(operand);
		}
	}
	//Once we get here, we're at the end of the file
	//Do some final checks
	//YOU: Code this section
	if(!seen_an_e) die();
	else exit(EXIT_SUCCESS);
}
