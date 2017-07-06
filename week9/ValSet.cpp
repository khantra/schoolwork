/*********************************************************************
** Author: Khandakar Shadid
** Date: 3/1/2017
** Description: Function definitions for a template class called ValSet 
*********************************************************************/
#include "ValSet.hpp"
template <class T>
ValSet<T>::ValSet(){ 
    
    arraySize = 10;
    aptr = new T[arraySize*sizeof(T)];
    numberOfValues=0;
   //cout << "constructor. " <<numberOfValues << " "<<&(this->aptr)<< endl;

} 

template <class T>
const ValSet<T>& ValSet<T>::operator = (const ValSet<T> & newObject){
 
	if (newObject.size() == 0){
            numberOfValues = 0; 
            arraySize = 10;
            aptr=new T[arraySize*sizeof(T)];
		
		}
 
	numberOfValues=newObject.size();
 
    aptr=new T[sizeof(T)*newObject.numberOfValues];
    aptr=newObject.aptr;
     
    return *this;
}

template <class T>
ValSet<T>::ValSet(const ValSet &newObject){
    //cout << "Copy constructor allocating ptr. " <<newObject.arraySize<< endl;
    aptr=new T[newObject.arraySize];
    if (!aptr) 
		return;
		
    
  for ( int i = 0; i < newObject.numberOfValues; i++ ) {
            aptr[i]=newObject.aptr[i];

    }    
    arraySize = newObject.arraySize;
    numberOfValues = newObject.numberOfValues;
  /*  for ( int i = 0; i < newObject.numberOfValues; i++ ) {
        cout << "*(aptr + " << i << ") : ";
        cout << *(aptr + i) << endl;
		
    }*/

}

template <class T >
bool ValSet<T>::isEmpty(){
    bool isArrEmpty=false;
        if (numberOfValues==0){ 
			isArrEmpty=true;
		}
    return isArrEmpty;
}

template <class T >
bool ValSet<T>::contains(T value){
bool valueExists=false;
  for ( int i = 0; i < numberOfValues; i++ ) {
           if( aptr[i]==value){
                valueExists= true;
            }
    }
return valueExists;
}

template <class T>
void ValSet<T>::add(T value ){
    if(contains(value)==false){
    numberOfValues++;
    arraySize++;
    if (numberOfValues > arraySize){
		arraySize *= 2;
		if (!aptr) 
			return;
			
		aptr = new T[arraySize*sizeof(T)];
    }

    aptr[numberOfValues-1] = value;
  //  cout<<aptr[numberOfValues-1]<<endl;
    }
}

template <class T>
void  ValSet<T>:: remove(T value ){
    //cout<<"Remove_containsA( "<< value<<" ): " <<contains(value)<< " and " <<numberOfValues<< " values"<<endl;
    if(contains(value) ){
        if(numberOfValues==1 ){
            numberOfValues = 0; 
            arraySize = 10;
            aptr=new T[arraySize*sizeof(T)];
            //cout<<"Remove_contains_OneElement( "<< value<<" ): " <<contains(value)<< " and " << numberOfValues<< " values"<<endl;
        }
        else{
            //cout<<"Remove_contains2( "<< value<<" ) : " <<contains(value)<< " and " <<numberOfValues<< " values"<<endl;
            for ( int i = 0; i < numberOfValues; i++ ) {
                if( aptr[i]==value){
                    //cout<<"Remove_contains2b aptr["<< i<<" ] : " <<aptr[i]<< " at position: " <<i<<endl;
                    for ( int x = i; x < numberOfValues; x++ )
                        aptr[x] = aptr[x+1];
                    numberOfValues--;    
                  //  valueExists= true;
                }

            }
        }
    }
            //cout<<"Remove_containsA( "<< value<<" ): " <<contains(value)<< " and " <<numberOfValues<< " values"<<endl;
}

template <class T>
void ValSet<T>::print() const{
   for( int i = 0; i <  numberOfValues; ++i )      
    cout<< aptr[i]<<endl;     
}; 

template <class T>
ValSet<T>::~ValSet(){
//cout<< "Deleted: "<< &(this->aptr) <<endl;
    delete[] aptr;
}

template class ValSet<int>;
template class ValSet<char>;
template class ValSet<std::string>;