// VIUBinarySearchTreeNodeImplementation.h
// Nikita Malhotra
// CSCI 260: Data Structures and Algorithms
// Purpose: to implement the VIUBinarySearchTreeNode class


//constructor
template <class Type>
VIUBinarySearchTreeNode<Type>::VIUBinarySearchTreeNode()
{
  m_Left = NULL;
  m_Right = NULL;
  m_Parent = NULL;
  m_Data = 0;
}

template <class Type>
VIUBinarySearchTreeNode<Type>::VIUBinarySearchTreeNode( Type Data )
{
  m_Data = Data;
}

//copy constructor
template <class Type>
VIUBinarySearchTreeNode<Type>::VIUBinarySearchTreeNode( const VIUBinarySearchTreeNode &O )
{
  m_Left = O.m_Left;
  m_Right = O.m_Right;
  m_Parent = O.m_Parent;
  m_Data = O.m_Data;
}

//destructor
template <class Type>
VIUBinarySearchTreeNode<Type>::~VIUBinarySearchTreeNode()
{
    delete m_Left;
    delete m_Right;
}

//parent
template <class Type>
class VIUBinarySearchTreeNode<Type>*
VIUBinarySearchTreeNode<Type>::Parent()
{
  return m_Parent;
}

//parent const 
template <class Type>
const class VIUBinarySearchTreeNode<Type>*
VIUBinarySearchTreeNode<Type>::Parent() const
{
  return m_Parent;
}

//parentNode
template <class Type>
void VIUBinarySearchTreeNode<Type>::Parent( class VIUBinarySearchTreeNode *ParentNode )
{
  m_Parent = ParentNode;
}

//left
template <class Type>
class VIUBinarySearchTreeNode<Type>*
VIUBinarySearchTreeNode<Type>::Left()
{
  return m_Left;
}

//left const 
template <class Type>
const class VIUBinarySearchTreeNode<Type>*
VIUBinarySearchTreeNode<Type>::Left() const
{
  return m_Left;
}

//leftNode
template <class Type>
void VIUBinarySearchTreeNode<Type>::Left( class VIUBinarySearchTreeNode *LeftNode )
{
  m_Left = LeftNode;
}

//right
template <class Type>
class VIUBinarySearchTreeNode<Type>*
VIUBinarySearchTreeNode<Type>::Right()
{
  return m_Right;
}

//right const 
template <class Type>   
const class VIUBinarySearchTreeNode<Type>*
VIUBinarySearchTreeNode<Type>::Right() const
{
  return m_Right;
}

//rightNode
template <class Type>
void VIUBinarySearchTreeNode<Type>::Right( class VIUBinarySearchTreeNode *RightNode )
{
  m_Right = RightNode;
}

//data 
template <class Type>
Type& VIUBinarySearchTreeNode<Type>::Data()
{
  return m_Data;
}

//data const 
template <class Type>
const Type& VIUBinarySearchTreeNode<Type>::Data() const
{
  return m_Data;
}

//Data
template <class Type>
void VIUBinarySearchTreeNode<Type>::Data( const Type& Data )
{
  m_Data = Data;
}

//largestchild 
template <class Type>
class VIUBinarySearchTreeNode<Type>*
VIUBinarySearchTreeNode<Type>::LargestChild()
{
  VIUBinarySearchTreeNode<Type> *current;
  if (NULL != m_Right) 
  {
    current = m_Right;
    while (NULL != current->m_Right) 
    {
      current = current->m_Right;
    } 
    return current;
  } else 
  {
    return this;
  }
}

//largestchild const 
template <class Type>
const class VIUBinarySearchTreeNode<Type>*
VIUBinarySearchTreeNode<Type>::LargestChild() const
{
  VIUBinarySearchTreeNode<Type> *current;
  if (NULL != m_Right) 
  {
    current = m_Right;
    while (NULL != current->m_Right)  
    {
      current = current->m_Right;
    }
    return current;
  } else 
  {
    return this;
  }
}

//smallestchild 
template <class Type>
class VIUBinarySearchTreeNode<Type>*
VIUBinarySearchTreeNode<Type>::SmallestChild()
{
  VIUBinarySearchTreeNode<Type> *current;
  if (NULL != m_Left) 
  {
    current = m_Left;
    while (NULL != current->m_Left) 
    {
      current = current->m_Left;
    }
    return current;
  } else 
  {
    return this;
  }
}

//smallestchild const 
template <class Type>   
const class VIUBinarySearchTreeNode<Type>*
VIUBinarySearchTreeNode<Type>::SmallestChild() const
{
  VIUBinarySearchTreeNode<Type> *current;
  if (NULL != m_Left)  
  {
    current = m_Left;
    while (NULL != current->m_Left)  
    {
      current = current->m_Left;
    }
    return current;
  } else 
  {
    return this;
  }
}
