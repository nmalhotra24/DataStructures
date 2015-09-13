//VIULinkedListImplementation.h
//Nikita Malhotra
//CSCI 260: Data Structures
//Purpose: to implement the VIULinkedList class stated in the VIULinkedList.h file

//constructor
template <class Type, class Iterator>
VIULinkedList<Type, Iterator>::VIULinkedList()
{ 
  m_HeadNode = NULL;
  m_TailNode = NULL;
  m_Count = 0;
}

//copy constructor 
template <class Type, class Iterator>
VIULinkedList<Type, Iterator>::VIULinkedList( const VIULinkedList &Other )
{
  m_HeadNode = Other.m_HeadNode;
  m_TailNode = Other.m_TailNode;
  m_Count = Other.m_Count;
}

//destructor
template <class Type, class Iterator>
VIULinkedList<Type, Iterator>::~VIULinkedList()
{
  VIULinkedListNode<Type>* current = NULL;
  while (NULL != m_HeadNode)
  {
    current = m_HeadNode;
    m_HeadNode = m_HeadNode->Next();
    delete current;
  }
}

//empty
template <class Type, class Iterator>
bool VIULinkedList<Type, Iterator>::Empty()
{
  if (NULL == m_HeadNode)
  { //this means that the linked list is empty
    return true;
  } else 
  {
    return false;
  }
} 

//add
template <class Type, class Iterator>
void VIULinkedList<Type, Iterator>::Add(const Type& NewData)
{
  //case1: the linked list is empty so just add
  if (NULL == m_HeadNode) 
  {
    m_HeadNode = new VIULinkedListNode<Type>(NewData);
    m_HeadNode->Next(NULL);
  } else
  {
    //case2: the data is less that data stored in m_HeadNode
    VIULinkedListNode<Type>* temp;
    temp = new VIULinkedListNode<Type>(NewData);
    if (temp->Data() < m_HeadNode->Data())
    {
      temp->Next(m_HeadNode);
      m_HeadNode = temp;
    } else
    { 
      VIULinkedListNode<Type>* current = m_HeadNode;
      VIULinkedListNode<Type>* prev = NULL;
      //case3: the data is greater that data stored in m_HeadNode
      while (current && (temp->Data() > current->Data()))
      {
	prev = current;
	current = current->Next();
      }
      prev->Next(temp);
      temp->Next(current);
    }
  }
}


//remove
template <class Type, class Iterator>
void VIULinkedList<Type, Iterator>::Remove( const Type& RemoveData )
{
  if (NULL == m_HeadNode) 
  {
    return;
  } 
  VIULinkedListNode<Type> *prev = NULL;
  if (RemoveData == m_HeadNode->Data())
  {
    prev = m_HeadNode;
    m_HeadNode= m_HeadNode->Next();
    delete prev;
    return;
  } else
  {
    VIULinkedListNode<Type> *current;
    current = m_HeadNode;
    while (NULL != current)
    {
      prev= current;
      current = current->Next();
      if (current && (RemoveData == current->Data())) 
      {
	prev->Next(current->Next());
	delete current;
	return;
      }
    }
  }
}

//addHead
template <class Type, class Iterator>
void VIULinkedList<Type, Iterator>::AddHead( const Type& NewData )
{
  VIULinkedListNode<Type> *NewNode;
  NewNode = new VIULinkedListNode<Type>(NewData);
  if (NULL == m_HeadNode)
  {
    m_HeadNode = NewNode;
    m_TailNode = NewNode;
  } else
  {
    NewNode->Next(m_HeadNode);
    m_HeadNode = NewNode;
  }
  ++m_Count;
}


//removeHead
template <class Type, class Iterator>
void VIULinkedList<Type, Iterator>::RemoveHead()
{
  if (NULL == m_HeadNode) 
  {
    return; //empty list, nothing to remove
  } else 
  {
    VIULinkedListNode<Type>* victim;
    victim = m_HeadNode;
    if (m_TailNode == m_HeadNode) 
    {
      m_HeadNode = NULL;
      m_TailNode = NULL;
    } else 
    {
      m_HeadNode = m_HeadNode->Next();
    }
    delete victim;
  }
}

//typeHead
template <class Type, class Iterator>
const Type& VIULinkedList<Type, Iterator>::Head()
{
  return m_HeadNode->Data();
}

//addTail
template <class Type, class Iterator>
void VIULinkedList<Type, Iterator>::AddTail( const Type& NewData )
{
  VIULinkedListNode<Type>* AddTail = new VIULinkedListNode<Type>;
  AddTail->Data(NewData);
  if (NULL == m_TailNode) 
  {
    AddTail->Next(NULL);
  } else 
  {
    m_TailNode->Next(AddTail);
  } 
  m_TailNode = AddTail;
}

//removeTail
template <class Type, class Iterator>
void VIULinkedList<Type, Iterator>::RemoveTail()
{
  if (NULL == m_TailNode) 
  {
    return; 
  } else 
  {
    VIULinkedList<Type>* victim;
    victim = m_TailNode;
    if (m_TailNode == m_HeadNode) 
    {
      m_HeadNode = NULL;
      m_TailNode = NULL;
    } else 
    {
      VIULinkedList<Type>* prev;
      prev = m_HeadNode;
      while (m_TailNode != prev->Next()) 
      {
	prev = prev->Next();
      }
      m_TailNode = prev;
      m_TailNode->Next() = NULL;
    }
    delete victim;
  }
}

//typeTail
template <class Type, class Iterator>
const Type& VIULinkedList<Type, Iterator>::Tail()
{
  if (NULL == m_TailNode) 
  {
    return;
  } else 
  {
    return m_TailNode->Data();
  }
}

//begin
template <class Type, class Iterator>
Iterator VIULinkedList<Type, Iterator>::Begin() const
{
  return Iterator(m_HeadNode);
}

//end
template <class Type, class Iterator>
Iterator VIULinkedList<Type, Iterator>::End() const
{
  return Iterator(NULL);
}

//equality operator
template <class Type, class Iterator>
 bool VIULinkedList<Type, Iterator>::operator==( const VIULinkedList &Other ) const
{
  VIULinkedListNode<Type>* l1 = m_HeadNode;
  VIULinkedListNode<Type>* l2 = Other.m_HeadNode;
  
  //case 1: the data in the two lists are not the same
  while ((NULL != l1) && (NULL != l2)) 
  { 
    if (l2->Data() != l1->Data())
    {
      return false; //the data is not the same in the lists.
    } else 
    {
      //iterator to the next item in the list
      l1=l1->Next();
      l2=l2->Next();
    }
  }
  //case 2: one of the lists could be longer than the other
  if ((NULL != l1) || (NULL != l2)) 
  {
    return false; //the list lengths are not equal.
  }

  return true; //passed all the checks for the list. The two lists are the same 
}

//assignment operator
template <class Type, class Iterator>
VIULinkedList<Type, Iterator>& VIULinkedList<Type, Iterator>::operator=( const VIULinkedList &RHS )
{
  VIULinkedListNode<Type> *current = RHS.m_HeadNode;
  while (NULL != current) 
  {
    VIULinkedListNode<Type> *current;
    current = current->Next();
  }
  return *this;
}
  
