/*	Node.cpp

//SENG1120: Assignment 1, Nathan Gervasoni: c3339961
//Implementation file for 'Node.h'.

// This file will illustrate how member variables and functions of- 
// 'Node.h' will interact with the class 'LinkedList.h', and 'LinkedListDemo.cpp'.

*/

#include "Node.h"
	
	Node::Node()
	{
		strWord = valueType();
		next = NULL;
		previous = NULL;
	}
	
	Node::Node(const valueType& initialString = valueType())
	{
		strWord = initialString;
		next = NULL;
		previous = NULL;
	}
	
	Node::Node(const valueType& initialString, Node* initialNext, Node* initialPrevious)
	{
		strWord = initialString;
		next = initialNext;
		previous = initialPrevious;
	}
	
	Node::~Node() //It is deleted once out of scope as it's not dynamic.  
	{
		next = NULL;
		previous = NULL;
	}
	
	void Node::setString(const valueType& initialString) 	
	{
		strWord = initialString;
	}
	
	void Node::setNext(Node* nextNode)
	{
		next = nextNode;
	}
	
	void Node::setPrevious(Node* previousNode)
	{
		previous = previousNode;
	}
	
	Node::valueType Node::getStrWord() const
	{
			return strWord;		
	}
	
	Node* Node::getNext() const
	{
		return next;
	}
	
	Node* Node::getNext()
	{
		return next;
	}
	
	Node* Node::getPrevious() const
	{
		return previous;
	}
	
	Node* Node::getPrevious()
	{
		return previous; 
	}

