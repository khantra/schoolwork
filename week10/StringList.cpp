/*********************************************************************
** Author: Khandakar Shadid	
** Date:3/8/17
** Description: Defines node and list as well as their functions
*********************************************************************/
#include "StringList.hpp" 

StringList::StringList() { 
    tail=NULL; listSize=0;
    
    
}    // Constructor
    
StringList::StringList(const StringList& aList){
    
    tail = copyList(aList.tail);
       
}

StringList::ListNode * StringList::copyList(ListNode *tailPtr){
    if (tailPtr == NULL){
        return NULL;
    }
    else{
        //nodePtr->next = new ListNode(newValue);
        ListNode *tailCopy = copyList(tailPtr->next);
        return new ListNode(tailPtr->value, tailCopy);
    }
    
}

void StringList::removeList(ListNode *aList)
{
   if (aList != NULL)
   {
      ListNode *tail = aList->next;
      delete aList;
      removeList(tail);
   }
}

StringList&
StringList::operator=(StringList newObject)
{
    removeList(tail);
    tail = copyList(newObject.tail);
}

    
void StringList::add(string newValue)
{
   if (tail == NULL){
      tail = new ListNode(newValue);
      listSize++;
   }
   else
     {
       ListNode *nodePtr = tail;
       while (nodePtr->next != NULL)
          nodePtr = nodePtr->next;
       nodePtr->next = new ListNode(newValue);
       listSize++;

     }
}

/*
The positionOf() function returns the (zero-based) 
position in the list for the first occurrence of the 
parameter in the list, or -1 if that value is not in the
list
*/

int StringList::positionOf (string newValue )
{   int position=0;
    ListNode *searchnode=tail;
 

    while(searchnode!=NULL){
        if(newValue==searchnode->value){
            return position;

        }
        searchnode=searchnode->next;
        position++;
    }
    return -1;
  
}



bool StringList::setNodeVal (int newPosition , string newValue)
{  
    if(newPosition >listSize-1)
            return false;
    if(newPosition==0){        
    ListNode *searchnode=tail;
    searchnode->setValue( newValue);
    return true;
    }
    ListNode *searchnode=tail;    
    int position=0;
 
    cout<<endl;
    while(position!=newPosition){
        searchnode=searchnode->next;
        position++;
    }
    searchnode->setValue( newValue);
    return true;

}

vector<string> StringList::getAsVector() 
{
    int position=0;
vector<string> newVector;
   ListNode *nodePtr = tail;   // Start at head of list
   while (nodePtr)
   {
       newVector.push_back (nodePtr->value);
       nodePtr = nodePtr->next;
       position++;
   }
return newVector;
}



void StringList::displayList() const
{
    int position=0;
   ListNode *nodePtr = tail;   // Start at head of list
   while (nodePtr)
   {
	         cout << nodePtr->value << "    ";
      nodePtr = nodePtr->next;
      position++;
   }
}


StringList::~StringList()
{
  ListNode *nodePtr = tail;  // Start at head of list
      cout<<endl;  
  while (nodePtr != NULL)
  {
      ListNode *garbage = nodePtr;
      nodePtr = nodePtr->next;
      delete garbage;
  }
}
