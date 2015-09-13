//Filename: VIULinkedListNodeImplementation.h
//Author: Nikita Malhotra 
//Purpose: Implementation of Linked List Node class


//constructor
template <class Type>
VIULinkedListNode<Type>::VIULinkedListNode()
{
  m_Next = NULL;
  m_Data = 0;
}

//constructor
template <class Type>
VIULinkedListNode<Type>::VIULinkedListNode( Type Data )
{
  m_Data = Data;
}

//copy constructor (deep copy)
template <class Type>
VIULinkedListNode<Type>::VIULinkedListNode( const VIULinkedListNode &O )
{
  m_Next = O.m_Next;
  m_Data = O.m_Data;
}


//destructor
template <class Type>
VIULinkedListNode<Type>::~VIULinkedListNode()
{
  //  delete m_Next;
}


//next
template <class Type>
class VIULinkedListNode<Type>*
VIULinkedListNode<Type>::Next()
{
  return m_Next;
}

//const next 
template <class Type>
const class VIULinkedListNode<Type>*
VIULinkedListNode<Type>::Next() const
{
  return m_Next;
}

//nextNode
template <class Type>
void VIULinkedListNode<Type>::Next( class VIULinkedListNode *nextNode )
{
  m_Next = nextNode;
}

//data
template <class Type>
Type& VIULinkedListNode<Type>::Data()
{
  return m_Data;
}

//data const
template <class Type>
const Type& VIULinkedListNode<Type>::Data() const
{
  return m_Data;
}

//data
template <class Type>
void VIULinkedListNode<Type>::Data( const Type& Data )
{
  m_Data = Data;
};
