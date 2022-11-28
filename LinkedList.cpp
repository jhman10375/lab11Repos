// LinkedList.cpp : Defines the exported functions for the DLL application.
//

#include "LinkedList.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

ILinkedList::ILinkedList() : m_count(0)
{

}

/** Returns true  if list is empty, otherwise true */
bool ILinkedList::isEmpty() const
{
	//TODO - hint use m_count

	return false;
	
}

Node::Node() : m_value(-1), m_next(nullptr)
{

}
Node::Node(int val) : m_value(val), m_next(nullptr)
{

}
Node::Node(int val, Node * nextNode) : m_value(val), m_next(nextNode)
{

}
void Node::setItem(const int& val)
{
	m_value = val;
}
void Node::setNext(Node* nextNodePtr)
{
	m_next = nextNodePtr;
}
int Node::getItem() const
{
	return m_value;
}
Node * Node::getNext() const
{
	return m_next;
}
Node::~Node()
{
	std::cout << "Deleting node with value " << m_value << std::endl;
	delete m_next;
	// you can recursively handle this which would require some code
	// Otherwise you need to delete each node individuall in the owner of the Nodes (i.e. the LinkedList)
}

PointerBasedLinkedList::PointerBasedLinkedList() : ILinkedList(), m_head(nullptr)
{

}

/** Adds a value to the LinkedList.  Return true if able to, otherwise false */
bool PointerBasedLinkedList::add(int val)
{
	return false;
	//TODO
}
/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
Will only remove one entry if there are multiple entries with the same value */
bool PointerBasedLinkedList::remove(int val)
{
	//TODO
	return false;
}

/** Remove  all elements from LinkedList */
void PointerBasedLinkedList::clear()
{
	 
    //TODO
}
PointerBasedLinkedList::~PointerBasedLinkedList()
{
	//TODO - maybe not depending on how you implement Node::~Node
	delete m_head;
}

std::string PointerBasedLinkedList::toString() const
{
	string str = "";


    //TODO
	return str;
}

ArrayBasedLinkedList::ArrayBasedLinkedList() : ILinkedList()
{
    m_count = 0;
	// you got it for free :)
}

bool ArrayBasedLinkedList::add(int val)
{
	ArrayBasedLinkedList();

	while(m_count < 10)
	{
		if(m_values[m_count] == 0) {
			m_values[m_count] = val;
			return true;
		}

		m_count++;
	}
	return false;
}
bool ArrayBasedLinkedList::remove(int val)
{
	ArrayBasedLinkedList();
	int dubVal = 0;

	while(m_count < 10)
	{
		if(m_values[m_count] == val)
		{
			dubVal++;
			if(dubVal >= 2)
			{
				m_values[m_count] = 0;
				return true;
			}
		}

		m_count++;
	}
	return false;
}
void ArrayBasedLinkedList::clear()
{
	for (int i : m_values) {
        i = 0;
    }
}
ArrayBasedLinkedList::~ArrayBasedLinkedList()
{

}

std::string ArrayBasedLinkedList::toString() const
{
	string str = "";
	int i = 0;
	for (int i : m_values) {
        if(i != m_values[10])
		{
			str += to_string(i) + " ";
		}
		else
		{
			str += to_string(i);
		}
    }

	

	return str;
}
