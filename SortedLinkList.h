#ifndef SortedLinkList_h
#define SortedLinkList_h

/*
 Make sure to check all return types are iterators
 */

#include "NodePoly.h"

using namespace std;

/*
 Make sure to check all return types are iterators
 */

template <class T>
class List
{
public:
    class Iterator
    {
    public:
        friend class List;// give access to list to access _ptr

        Iterator next()
        {
            return  _ptr-> _next  ;
        } // return an iterator to the next location in the list
        node<T>* operator->()
        {
            assert(_ptr);
            return _ptr ;
            //or
            //return &(current->next->value);
        }//member access operator

        const node<T>* operator->() const
        {
            assert(_ptr);
            return  _ptr ;
        }

        Iterator()
        {
            _ptr = nullptr;
        }  //default ctor
        
        Iterator(node<T>* p)
        {
            _ptr = p;
        }//Point Iterator to where p is pointing to
        
        T& operator *()
        {
            assert(_ptr);
            //return Iterator( _ptr-> _item );
            return   _ptr-> _item ;
        }//dereference operator
        
        operator bool()
        {
            if( _ptr == nullptr)
            {
                return true ;
            }
            return false ;
        }  //casting operator: true if _ptr not NULL
           //      this turned out to be a pain!
        
        bool is_null()
        {
            if(_ptr == nullptr)
                   return true;
               else
                   return false;
        }//true if _ptr is NULL
        
        //prefix
        Iterator& operator++ ()
        {
            _ptr = _ptr-> _next;
            return  Iterator(*this) ;

        }//member operator: ++it; or ++it = new_value
    

        //postfix
        friend Iterator operator++( Iterator& it, int unused)
        {
            //node<T>* _ptr;
            Iterator hold;
            hold = it;
            it._ptr = it._ptr-> _next;
            return Iterator( hold );
        }//friend operator: it++
        
        
        friend bool operator != (const Iterator& left, const Iterator& right)
        {
            return left._ptr != right._ptr;
        }//true if left != right

        friend bool operator == (const Iterator& left, const Iterator& right)
        {
           return left._ptr == right._ptr;
        }//true if left == right


    private:
        node<T>* _ptr;                          //pointer being encapsulated
    }; //end of iterator class
    
    List(bool order=true, bool unique=false);                   //CTOR with default args
                                                            //BIG 3:
    List(const List<T> &copyThis);
    List& operator = (const List& RHS);
    ~List();

    Iterator InsertAndAdd(const T& i);
    Iterator Insert(const T& i);    //Insert i in a sorted manner

    T Delete(List<T>::Iterator iMarker);  //delete node pointed to by marker
    void Print() const;
    void PrintC(List<T>::Iterator cursor) const;
    Iterator Search(const T &key) const; //return Iterator to node [key]
    Iterator Prev(Iterator iMarker);     //previous node to marker

    const T& operator[](int index) const;   //const version of the operator [ ]
    T& operator[](int index);   //return item at position index
    Iterator Begin() const; //Iterator to the head node
    Iterator End() const; //Iterator to NULL
    
    template <class U>
    friend ostream& operator <<(ostream& outs, const List<U>& l)
    {
        outs << "Head->";
        node<U>* walker = l._head_ptr;
        
        while (walker != nullptr)
        {
            outs << " [" << *walker << "] " ;
            outs << "->";
            walker = walker->_next;
        }
            outs << "|||" << endl;

            return outs;
    }
    
    Iterator Insert_Head(const T& item);
    Iterator Insert_Before(const T& item, Iterator iMarker);
    Iterator Insert_After(const T& item, Iterator iMarker);
    void PrintSortedCursor(List<T>::Iterator head, List<T>::Iterator cursor) const ;
    
private:
    node<T>* _head_ptr;
    bool _ascending;
    bool _unique;

}; //end of list class


template<typename T>
List<T>::List(bool order, bool unique): _ascending(order), _unique(unique)
{
    _head_ptr = nullptr;
    _unique = true;
    _ascending = false;
}

// ====================================== Big 3 ====================================== \\

template<typename T>
List<T>::List(const List<T> &copyThis)
{
    return Iterator( CopyList(_head_ptr) );
}

template<typename T>
List<T>& List<T>::operator = (const List& RHS)
{
    
   // return CopyList(_head_ptr) ;
  return Iterator( CopyList(_head_ptr) );
}

template<typename T>
List<T>::~List()
{
    ClearList(_head_ptr) ;
}
// ================================== End of big 3 ==================================== \\


//not done
template<typename T>
typename List<T>::Iterator List<T>::Insert(const T& i)
{
    return Iterator( InsertSorted( _head_ptr, i, _ascending = false) );
}

//is this the function header idk it is the only one not giving me a declaration error
template<typename T>
T List<T>::Delete(List<T>::Iterator iMarker)
{
    return Iterator( DeleteNode(_head_ptr, iMarker._ptr) ) ;
    
}


template<typename T>
void List<T>::Print() const
{
   // return Iterator( PrintList(_head_ptr);
    return Iterator( PrintList(_head_ptr) );
}
template<typename T>
void List<T>::PrintC(List<T>::Iterator cursor) const
{
    return Iterator( PrintSortedCursor(_head_ptr, cursor) );

}


//(typename List<T>::Iterator)  => return type which is an iterator
template<typename T>
typename List<T>::Iterator List<T>::Search(const T &key) const
{
    return Iterator( SearchList(_head_ptr,key) );
}

template<typename T>
typename List<T>::Iterator List<T>::Prev(List<T>::Iterator iMarker)
{
     return Iterator( PreviousNode(_head_ptr, iMarker) );
}

template<typename T>
const T& List<T>::operator[](int index) const
{
    return Iterator( At(_head_ptr, index));
}
//const version of the operator [ ]

template<typename T>
T& List<T>::operator[](int index)
{
      return Iterator( At(_head_ptr, index));
}

template<typename T>
typename List<T>::Iterator List<T>::Begin() const
{
    return Iterator(_head_ptr);
}

template<typename T>
typename List<T>::Iterator List<T>::End() const
{
    return Iterator( LastNode(_head_ptr) );
}

template<typename T>
typename List<T>::Iterator List<T>::InsertAndAdd(const T& i)
{
    return Iterator( InsertSorted( _head_ptr, i, _ascending = false) );
}

// =============================== Print fxn defined above =========================== \\
// =================================================================================== \\

// ==================================  OLD STUFF  ==================================== \\

//template<typename T>
//typename List<T>::Iterator List<T>::Insert_Head(const T& item)
//{
//    return Iterator( InsertHead(_head_ptr, item) );
//}
//
//template <class T>
//typename List<T>::Iterator List<T>::Insert_Before(const T& item, List<T>::Iterator iMarker)
//{
//    return Iterator( InsertBefore(_head_ptr, iMarker._ptr, item) ) ;
//}
//
//template<typename T>
//typename List<T>::Iterator List<T>::Insert_After(const T& item, List<T>::Iterator iMarker)
//{
//     return Iterator( InsertAfter(_head_ptr, iMarker._ptr, item) ) ;
//}

#endif /* SortedLinkList_h */
