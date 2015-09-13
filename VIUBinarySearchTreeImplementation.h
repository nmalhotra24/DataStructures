//Name: VIUBinarySearchTreeImplementation.h
//Author: Nikita Malhotra
//Purpose: to implement the VIUBinarySearchTree class



//constructor
template <class Type, class Iterator>
VIUBinarySearchTree<Type, Iterator>::VIUBinarySearchTree()
{
  m_RootNode = NULL;
}

//destructor
template <class Type, class Iterator>
VIUBinarySearchTree<Type, Iterator>::~VIUBinarySearchTree()
{
    delete m_RootNode;
    m_RootNode = NULL;
}


 //adding a node
template <class Type, class Iterator>
void VIUBinarySearchTree<Type, Iterator>::Add( const Type &NewData )
{
  VIUBinarySearchTreeNode<Type>* temp = CreateNode(NewData);
  if (NULL == temp)
  {
    return; //could not create the node
  }

  if (NULL == m_RootNode)
  {
    m_RootNode = temp;
    return;
  }

  VIUBinarySearchTreeNode<Type>* current = m_RootNode;
  VIUBinarySearchTreeNode<Type>* prev = NULL;
  
  //find the parent node
  while (NULL != current) 
  {
    if (NewData == current->Data())
    {
      return; //no duplicates                                                
    } else if (NewData < current->Data())
    { //belongs in the left subtree  
      prev = current;
      current = current->Left();
    } else 
    { //belongs in the right subtree
      prev = current;
      current = current->Right(); 
    }
  }  
  
  if (prev && NewData < prev->Data())
  {
      prev->Left(temp);
      temp->Parent(prev);
  } else if (prev && NewData > prev->Data()) 
  {
      prev->Right(temp);
      temp->Parent(prev);
  }                
  return;
}
                                                                        
//removing a node
template <class Type, class Iterator>
void VIUBinarySearchTree<Type, Iterator>::Remove( const Type &RemoveData )
{
  bool node_found = false;
  VIUBinarySearchTreeNode<Type>* current = NULL;
  VIUBinarySearchTreeNode<Type>* parent = NULL;
  current = m_RootNode;
  
  //finding the node with RemoveData
  while (NULL != current)
  {
    if (RemoveData == current->Data())
    { //found the node
      node_found = true;
      break;  
    } else
    {
      if (RemoveData < current->Data())
      {
    parent = current; 
    current = current->Left();
      } else 
      { 
    parent = current;
    current = current->Right();
      }   
    }
  }
  
  //return if node with RemoveData not found
  if (node_found == false) return;
  
  //case1 & 2: current has no children or current have just one child
  if (NULL == current->Left())
  { //replace current with current->Right() which might be NULL, but that would mean
    //current has no children
    if (parent == NULL) 
    { //current is the root of the tree
      m_RootNode = current->Right();
              
    } else if (current == parent->Left())
    {
      parent->Left(current->Right());
    } else 
    {
      parent->Right(current->Right());    
    }
    if (NULL != current->Right()) 
        current->Right()->Parent(parent);
  } else if (NULL == current->Right())   
  { //Case2: replace current with current->Left() which is not NULL, hence meaning 
    //current have just one child
    if (parent == NULL) 
    { //current is the root of the tree
      m_RootNode = current->Left();        
    } else if (current == parent->Left())
    {
      parent->Left(current->Left());
    } else 
    {
      parent->Right(current->Left());    
    }
    if (NULL != current->Left()) 
        current->Left()->Parent(parent);

  } else 
  { //case3:current has two children; current->Left() and current->Right() 
    // are both not NULL
    VIUBinarySearchTreeNode<Type>* min = current->Right();  
    VIUBinarySearchTreeNode<Type>* parent_min = current;  
    while (min && min->Left()) 
    {
      parent_min = min;
      min = min->Left();
    }
        
    if (min != current->Right())
    {
      parent_min->Left(min->Right()); 
      if (NULL != min->Right()) 
          min->Right()->Parent(parent_min);
 
      min->Right(current->Right());
      min->Right()->Parent(min);  
    }
    
    if (parent == NULL) 
    { //current is the root of the tree
      m_RootNode = min;        
    } else if (current == parent->Left())
    {
      parent->Left(min);
    } else 
    {
      parent->Right(min);    
    }
    min->Parent(parent);
    
    min->Left(current->Left());
    min->Left()->Parent(min);
  }
  
  delete current;
  current = NULL;
  return;
}


template <class Type, class Iterator>
  Iterator VIUBinarySearchTree<Type, Iterator>::Begin() const
{
  return iterator(m_RootNode);
}


template <class Type, class Iterator>
Iterator VIUBinarySearchTree<Type, Iterator>::Begin( typename VIUBinarySearchTreeIterator<Type>::IteratorMode Mode ) const
{  
  return iterator(m_RootNode, Mode); 
}


template <class Type, class Iterator>
  Iterator VIUBinarySearchTree<Type, Iterator>::End() const
{
  return iterator(NULL);
}


template <class Type, class Iterator>
VIUBinarySearchTreeNode<Type>*
VIUBinarySearchTree<Type,Iterator>::CreateNode( const Type &NewNodeData )
{
  VIUBinarySearchTreeNode<Type>* t = new VIUBinarySearchTreeNode<Type>;
  t->Data(NewNodeData);
  t->Left(NULL);
  t->Right(NULL);
  t->Parent(NULL);

  return t;
}


template <class Type, class Iterator>
VIUBinarySearchTreeNode<Type>*
VIUBinarySearchTree<Type,Iterator>::Find( const Type &FindData )
{
  VIUBinarySearchTree<Type>* current = m_RootNode;
  while ((NULL != current) && (current->Data() != FindData)) 
  {
    if (current->Data() > FindData) 
    {
      current = current->Left();
    } else 
    {
      current = current->Right();
    }
  }
   
  return current;   
}
