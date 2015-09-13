//VIULinkedListIteratorImplementation.h
//NIkita Malhotra
//CSCI 260: Data Structures and Algorithms
//Purpose: to implement the VIULinkedListIterator class

//constructor
template <class Type>  
VIULinkedListIterator<Type>::VIULinkedListIterator()
{
  m_IterNode = NULL;
}

//constructor
template <class Type>
VIULinkedListIterator<Type>::VIULinkedListIterator( VIULinkedListNode<Type> *Node )
{
  m_IterNode = Node;
}


//destructor
template <class Type>
VIULinkedListIterator<Type>::~VIULinkedListIterator()
{
  delete m_IterNode;
}


//assignment operator 
template <class Type>
VIULinkedListIterator<Type>& VIULinkedListIterator<Type>::operator=( const VIULinkedListIterator &RHS )
{
  if (this != &RHS) 
  {
    m_IterNode = RHS.m_IterNode;
  }
  return *this;
 
}

//preincrement operator  
template <class Type>
VIULinkedListIterator<Type>& VIULinkedListIterator<Type>::operator++ ()
{
  m_IterNode = m_IterNode->Next();
  return *this;
}


//postincrement operator
template <class Type>
VIULinkedListIterator<Type> VIULinkedListIterator<Type>::operator++(int)
{
  VIULinkedListNode<Type> *prev = NULL;
  m_IterNode = m_IterNode->Next();
  return prev;
} 



//!= operator
template <class Type>
bool VIULinkedListIterator<Type>::operator!=( const VIULinkedListIterator &Other ) const
{
  return (m_IterNode != Other.m_IterNode);
}



//dereferincing operator 
template <class Type>
Type& VIULinkedListIterator<Type>::operator*()
{
  return (m_IterNode->Data());
}


//derefrencing operator const 
template <class Type>
const Type& VIULinkedListIterator<Type>::operator*() const
{
  return (m_IterNode);
}

 
