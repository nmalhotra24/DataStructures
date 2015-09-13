//Name: VIUBinarySearchTreeIteratorImplementation.h
//Author: Nikita Malhotra
//Purpose: to implement the VIUBinarySearchTreeIterator class


template <class Type>
VIUBinarySearchTreeIterator<Type>::VIUBinarySearchTreeIterator()
{
  m_CurrentNode = NULL;
  m_IteratorMode = IteratorMode_InOrder;
}


template <class Type>
VIUBinarySearchTreeIterator<Type>::VIUBinarySearchTreeIterator(VIUBinarySearchTreeNode<Type> *Node, IteratorMode Mode)				 
{
  m_CurrentNode = Node;
  m_IteratorMode = Mode;
}


template <class Type>
VIUBinarySearchTreeIterator<Type>::VIUBinarySearchTreeIterator( IteratorMode Mode )
{
  m_IteratorMode = Mode;
  m_CurrentNode = NULL;
}


template <class Type>
VIUBinarySearchTreeIterator<Type>::~VIUBinarySearchTreeIterator()
{
}


template <class Type>
VIUBinarySearchTreeIterator<Type>& VIUBinarySearchTreeIterator<Type>::operator=( const VIUBinarySearchTreeIterator &RHS )
{
  if (this != &RHS)
  {
    m_CurrentNode = RHS.m_CurrentNode;
  }
  return *this;
}


template <class Type>
VIUBinarySearchTreeIterator<Type>& VIUBinarySearchTreeIterator<Type>::operator++ ()
{  
  if (NULL == m_CurrentNode)
  {
    return *this;
  }
  VIUBinarySearchTreeNode<Type>* root = m_CurrentNode;
  VIUBinarySearchTreeNode<Type>* current = m_CurrentNode;
  VIUBinarySearchTreeNode<Type>* parent = m_CurrentNode->Parent();

  while (NULL != root && root->Parent())
  {
    root = root->Parent();
  }

  if (NULL == root)
  {
    return *this;
  }

  switch (m_IteratorMode) 
  {
  case IteratorMode_PreOrder: 
  {
    //Largest Node in the tree has no Pre-order Successor
    if (m_CurrentNode == root->LargestChild())
    {
      m_CurrentNode = NULL;
    } else if (NULL != m_CurrentNode->Left())
    { //If current node has left child, return left child      
      m_CurrentNode = m_CurrentNode->Left(); 
    } else if (NULL != m_CurrentNode->Right())
    { //If current node has right child, return right child      
      m_CurrentNode = m_CurrentNode->Right();  
    } else 
    {
      //current node is a leaf node
      //If current node is left child of its parent, return nearest parent's right child 
      //If current node is right child of its parent, move until current is parent's left child 
      while (parent && current == parent->Right())
      {
	current = parent;
	parent = parent->Parent();
      }
          
      while (parent && (parent->Right() == NULL || current == parent->Right()))
      {
	current = parent;
	parent = parent->Parent();    
      }    
          
      if (NULL !=parent)
      {
	m_CurrentNode = parent->Right();
      } else
      { 
	m_CurrentNode = NULL;    
      }
    }    
  }
  break;
  
  case IteratorMode_InOrder:
  {
    //Largest Node in the tree has no In-order Successor
    if (m_CurrentNode == root->LargestChild())
    {
      m_CurrentNode = NULL;
    } else if (NULL != m_CurrentNode->Right())
    { //If current node has right child, return Smallest child of its right
      m_CurrentNode = m_CurrentNode->Right()->SmallestChild();    
    } else 
    {
      while (parent && current == parent->Right())
      {
	current = parent;
	parent = parent->Parent();
      }
      m_CurrentNode = parent;
    }
  }
  break;  
      
  case IteratorMode_PostOrder:
  {
    //Root Node in the tree has no Post-order Successor
    if (m_CurrentNode == root)
    {
      m_CurrentNode = NULL;
    } else if (parent && current == parent->Right())
    { //If current node is right child of its parent, return parent
      m_CurrentNode = parent;
    } else
    { 
      //If parent has a right child, return the Smallest child of parent->Right()
      //If parent has a no right child, return parent
      if (parent && parent->Right())
      {
	m_CurrentNode = parent->Right()->SmallestChild();
      } else if (parent && parent->Right() == NULL)
      {
	m_CurrentNode = parent;
      }
    }           
  }
  break;
  

  case IteratorMode_DepthFirst:
  {
    m_IterState.AddHead(root);
    while (!m_IterState.Empty()) 
    {
      current = m_IterState.Head();
      if (current->Left())
      {
	m_IterState.AddTail(current->Left());
      } 
      if (current->Right())
      {
	m_IterState.AddTail(current->Right());  
      } 
      if (current == m_CurrentNode)
      {
	m_IterState.RemoveHead();
	break;          
      } else 
      {
	m_IterState.RemoveHead();
      }  
    }
            
    if (!m_IterState.Empty())
    {
      m_CurrentNode = m_IterState.Head();  
    } else
    { 
      m_CurrentNode = NULL;
    }

    while(!m_IterState.Empty())
     {
       m_IterState.RemoveHead();
     }
    break;
  }
  }
  return *this;
}


template <class Type>
VIUBinarySearchTreeIterator<Type> VIUBinarySearchTreeIterator<Type>::operator++(int)
{
  VIUBinarySearchTreeIterator<Type> before = m_CurrentNode;
  ++(*this);
  return before;
}


template <class Type>
bool VIUBinarySearchTreeIterator<Type>::operator==( const VIUBinarySearchTreeIterator &Other ) const
{
  return Other.m_CurrentNode == m_CurrentNode;
}


template <class Type>
bool VIUBinarySearchTreeIterator<Type>::operator!=( const VIUBinarySearchTreeIterator &Other ) const
{
  return Other.m_CurrentNode != m_CurrentNode;
}

 
template <class Type>
Type& VIUBinarySearchTreeIterator<Type>::operator*()
{
  return m_CurrentNode->Data();
}

 
template <class Type>
const Type& VIUBinarySearchTreeIterator<Type>::operator*() const
{
  return m_CurrentNode.Data();
}

