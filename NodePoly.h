#ifndef NodePoly_h
#define NodePoly_h
/*
 node.h
 */
#include <iostream>

using namespace std;

template <typename T>
struct node
{
  T _item; //crate
  node<T>* _next; //lable
  node(const T& item=T(), node<T>* next = nullptr): _item(item), _next(next){}

    friend ostream& operator<<(ostream& outs, const node<T> n)
    {
        outs<<  n._item ;
        return outs;
    }

};

template <typename T>
void PrintList(node<T>* head)
{
    cout << "head-> ";
    node<T>* print = head;

    while( print != nullptr )
    {
        cout << " [";
        cout << *print;
        cout << "]";
        cout << "->";
        print = print-> _next;
    }

       cout << "|||";
}


template <typename T>
void PrintList_backwards(node<T> *head)
{
    cout << "back-> ";
    node<T>* print = head;
    node<T>*beforeThis = PreviousNode_(head, beforeThis);

    if( print != nullptr )
    {
        while( print != nullptr )
        {
        //        //want to see whats in box
        //        cout << *print;
        //        cout << "";
        //        //walker++
            print = print-> _next;
        }
        while( print != nullptr )
        {
            cout << *print;
            cout << "";
            print = print-> beforeThis ;
        }

           cout << "|||";
    }

}
template <class T>
void PrintCursor(node<T>* head, node<T>* cursor )
{
    
    //if  list empty
    if( cursor == nullptr )
        cursor = head ;
    
    cout << "head-> ";
    node<T>* walker = head ;
    
    while(walker != nullptr)
    {
        //print different
        if( walker == cursor)
            cout << "{{" << *walker << "}}";
        //print regular
        else
            cout << " " << *walker << " ";
        
        walker = walker -> _next;
    }
    cout << "|||";
}


//same as print
template <typename T>
node<T>* SearchList(node<T>* head, const T& key)
{
    node<T>* temp = head;
    
    //want to keep going in not at end !=null
   
    //if we havent found item yet
    while ( temp-> _item != key && temp->_next != nullptr)
    {
       temp = temp->_next;
    }

    //found key
    if (temp-> _item == key)
       return temp;
    else
       return nullptr;
}

template <typename T>
node<T>* InsertHead(node<T>*& head, T insertThis)
{
    //make new create that has the thing want intersted
    node<T>* temp = new node<T>(insertThis);
    temp-> _next = head;
    head = temp;
    //need to change head so return it
    return head;
}

template <typename T>
node<T>* InsertAfter(node<T>*& head, node<T>* afterThis,T insertThis)
{
    //_need label =
    node<T>* temp = new node<T>(insertThis);
      // temp-> _item = insertThis;

    //if its head we need to use head fxn
    if (afterThis == nullptr)
    {
        return InsertHead(head, insertThis);
    }

    //if last pos ( null )
    if (afterThis->_next == nullptr)
    {
       temp->_next = nullptr;
       afterThis->_next = temp;
    }
    //
    else
    {
       // need next node (dont lose chain)
       temp-> _next = afterThis-> _next;

       // point to temp
       afterThis-> _next = temp;
    }
    return temp;

}



template <typename T>
node<T>* InsertBefore(node<T>*& head, node<T>* beforeThis, T insertThis)
{
    //need node to make changes to
    //need node to this before current
    node<T>* current  = new node<T>;
    beforeThis = PreviousNode(head, beforeThis);
    
    //only probelm is when the perrious = head (seconf possition in array)
    if (beforeThis != head)
    {
        //do return after but give prevous possition so really returns to before position
        return InsertAfter(head, beforeThis, insertThis);
    }
    //second possition when previous = head
    else
    {
        //need to move over so use a walker
        node<T>* walker = head;
        //feed of item into current
        current-> _item = insertThis ;
        //walk the walker
        current-> _next = walker-> _next;
        walker-> _next = current;
    }
    return current; //actually one before actuall postion
}

template <typename T>
node<T>* PreviousNode(node<T>* head, node<T>* prevToThis)
{
    //1. before head
    //2. somewhere in middle(good points)
    //3. next = null
    
    //inserse not before head (problem1)
    if (prevToThis == head)
        return nullptr;
    
    //prob 2 and 3
    else
    {
        //start previos at head
        node<T> *previous = head;

        // previos is head but (previous-> _next) = next
        while(previous-> _next != NULL && previous-> _next != prevToThis)
        {
            previous = previous-> _next;
        }

        return previous;
    }
}
template <typename T>
T DeleteNode(node<T>*& head, node<T>* deleteThis)
{
    //check is node here (search) and is their a list to check
    // is it head
    node<T>* walker = head;
    T item ;

    if(head == nullptr)
    {
        cout << "list is empty" << endl;
    }

    else if( (walker != nullptr) && (deleteThis == head) )
    {
        walker = walker-> _next;
        //return *deleteThis ;
        return item;
    }
    else
    {
        while( ( walker-> _next != deleteThis ) && ( walker-> _next != nullptr))
        {
            walker = walker-> _next;
        }
        walker-> _next = deleteThis-> _next; // makes the one beofre this point to the one after => deleteThis
    }
    deleteThis-> _next = nullptr;
    //return *deleteThis;
     return item;
}
template <typename T>
void ClearList(node<T>*& head)
{
    node<T>* erase ;
    
    while ( head != nullptr)
    {
        DeleteNode(head, erase);
    }
}

template <typename T>
node<T>* CopyList(node<T>* head) //duplicate the list
{
    //T _item; //crate
    //node<T>* _next; //lable
    node<T>* walker = head-> _next;

    if (head-> _next == nullptr)
    {
        return head;
    }
    
    node<T>* duplicate = new node<T>( head-> _item);
    node<T>* dupWalker = duplicate;
    
    while (walker != nullptr)
    {
        InsertAfter(duplicate, dupWalker, walker->_item);
        //insert_after(duplicate, dupWalker, walker->_item); //head_ptr, item
        walker = walker->_next;
        dupWalker = dupWalker->_next;
    }
    
    return duplicate;
}



template <typename T>
T& At(node<T>* head, int pos)//_item at this position
{
    node<T>* itemPointer = SearchList(head, pos);
    return itemPointer;
}

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template <typename T>
node<T>* WhereThisGoes(node<T>* head, T item, bool ascending=true)
{
    node<T>* Previous = head;             //walker for head need this so we have the prevous location to walker next
                                        //so can insert item in the previous node to head
    node<T>* walkerNext = head-> _next; //walker for next location
    
    //check items and relationship 2 head
    //case1: head is empty, case2: item and head are same, case3: item greater then heads item
    if ( head == nullptr) //list is empty
        return head;
    else if( item > head->_item )
    {
       // cout << "Using this one" <<endl;
        //InsertHead(head, item);
        return head ;
    }
    else if(item == head-> _item)
        return head;
        
    
    while (walkerNext != nullptr)
    {
        //want to know if item is bigger then item in next location
        //if it is we want the previous location
        if (item > walkerNext-> _item)
            return Previous;
        
        //if not keep walking both walkers to next location
        Previous = Previous->_next;
        walkerNext = walkerNext-> _next;
    }
    return Previous; //once walkerNext is at the end return previos location
}



template <typename T>
node<T>* InsertSorted(node<T>* &head, T item, bool ascending)
{
    node<T>* insert = WhereThisGoes(head, item);

    if (insert == nullptr)
    {
        return InsertHead(head, item);
    }
    
    if ( item > head->_item)
         return InsertHead(head, item);
    
    return InsertAfter(head, insert, item);
}

template <typename T>
node<T>* InsertSorted_and_add(node<T>* &head, T item, bool ascending)
{

    node<T>* insert = WhereThisGoes(head, item, ascending);
    
    item = item + insert-> _item;
    return head;
}

template <typename T>
node<T>* LastNode(node<T>* head)
{
    node<T>* endNode ;
    if (head == nullptr)
    {
        return head;
    }
    
    while ( head != nullptr)
    {
        endNode = head;
        head = head-> _next ;
    }
    return endNode;
}



#endif /* NodePoly_h */
