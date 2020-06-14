/*	LinkedList.h
// SENG1120: Assignment 1, Nathan Gervasoni: c3339961
// Header file and class definition of LinkedList.
// Private and public variables, and function prototypes will be defined. 
// Pre and post conditions will be given for each method. 
// Remove a node  
// Count how many nodes of certain type example 'black' 
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "Node.h"


class LinkedList
{
	public:
	
		typedef Node::valueType valueType;
			// Assigns a Type definition of 'string' to 'valueType' for consistency throughout program.
		
// Constructors and Destructor.

		LinkedList(); 
			//Default constructor.
			
		LinkedList(const valueType& strWord);
			//Default constructor with valueType input. 
		
		~LinkedList();
			//Destructor for LinkedList class.
		
// Public Memeber Functions
	
		void add(const valueType inputWord); //Adds word from input and then sends to addToTail
			// Pre-condition: Input must be of valueType string. 
			// Post-condition: Sorts input into individual words and sends to addToTail() to store into Nodes.
			
		void addToHead(const valueType& strWord);
			// Pre-condition: LinkedList are initilised and have Nodes stored within.
			// Post-condition: Nodes will be added to the head, each node will add a new word. 
		
		void addToTail(const valueType& strWord);
			// Pre-condition: LinkedLists are initilised and have Nodes stored within.
			// Post-condition: Nodes will be added to the tail, each node will add a new word to form
			// a sentence in the correct order.
		
		
		void remove(const valueType inputWord); 
			// Pre-condition: Input must be of valueType(string). If multiple words are input, they must be removed together. 
			// Post-condition: If input is matched with LinkedList string word data, then it is removed. 
			
		void removeFromHead();
			// Pre-condition: LinkedList and head node must exist.
			// Post-condition: Removes head node from the list. 
		
		void removeFromTail();
			// Pre-condition: LinkedList and tail node must exist. 
			// Post-condition: Removes tail node from the list.
		
		void removeFromCurrent();
			// Pre-condition: A node that is neither the head, nor tail node must exist.
			// Post-condition: Removes the node from the list.
			
		void moveCurrent();
			// Pre-condition: LinkedList exists and the currentNode is not NULL. 
			// Post-condition: Iterates through list until set to stop. 
		
		void moveCurrentToHead();
			// Pre-condition: LinkedList must exist. 
			// Post-condition: CurrentNode is placed at top of the LinkedList.
		
		void moveCurrentToTail();
			// Pre-condition: LinkedList must exist.
			// Post-condition: CurrentNode is placed at tail of the LinkedList.
		
		Node* getCurrentNode();
			// Pre-condition: LinkedList exists.
			// Post-condition: Returns currentNode.
		
		int count(const valueType& strWord);
			// Pre-condition: LinkedList exists and contains data.
			// Post-condition: If the input matches LinkedList data then it is counted. 
			
		LinkedList& operator += (LinkedList& inputList);
			// Pre-condition: None.
			// Post-condition: Two linkedLists will be combined. 
			//Concatenates two LinkedList type objects together 
		
// Private Member Variables

	private:
		Node* currentNode; // Current pointer.
		Node* headNode;	   // Head pointer.
		Node* tailNode;	   // tail pointer.
		int listSize;	  // counts list. 
	
};

	std::ostream& operator << (std::ostream& out, LinkedList& inputList);
			// Pre-condition: None.
			// Post-condition: Overloads the cout operator. 
#endif