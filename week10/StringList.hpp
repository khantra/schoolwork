/*********************************************************************
** Author: Khandakar Shadid	
** Date:3/8/17
** Description: Declares node and list as well as their functions
*********************************************************************/
#include <iostream>
#include <string> 
#include <vector>
using namespace std; 

class StringList
{
protected:
    // Declare a class for the list node
    class ListNode
    {
    public:
       string value;
       ListNode *next;
       ListNode()
       {
          value = " ";
          next = NULL;
       }       
       ListNode(string value1, ListNode *next1 = NULL)
       {
          value = value1;
          next = next1;

       }
       	string getValue() const { return value; }
	    ListNode *getNext() const { return next; }
    	void setNext(ListNode *newNext) { next = newNext;  }
    	void setValue(string newValue)  {  value=newValue; }

    };
    
    
    int listSize;
    ListNode *tail;
public:
    StringList();
    ~StringList();                    // Destructor
    StringList(const StringList& obj);
     void add(string newValue);
    ListNode * copyList(ListNode *tailPtr);
    StringList& operator=(StringList newObj);
    void removeList(ListNode *aList);
    int positionOf (string);
    bool setNodeVal(int, string); 
    vector<string> getAsVector();
    
    void displayList() const;
};

