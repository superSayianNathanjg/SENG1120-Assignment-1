/*	Node.h

// SENG1120: Assignment 1, Nathan Gervasoni: c3339961
// Header file and class definition of Node.
// Private and public variables, and function prototypes will be defined.
// Pre and post conditions will be given for each method.
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstdlib>

class Node
{

	public:
		typedef std::string valueType;
			//Assigns a Type definition of 'string' to 'valueType' for consistency throughout program.
			
// Constructors and Destructor.

		Node();
			// Default constructor.
		Node(const valueType& initialString);
			// Default constructor with one input.
		Node(const valueType& initialString, Node* initialNext, Node* initialPrevious);
		    // Default Constructor with multiple inputs.
		~Node();
		    // Destructor for Node class.


// Public Memeber Functions


		void setString(const valueType& tempString);
			// Pre-condition: User input of string type is required for tempString.
		    // Post-condition: String input is stored in tempString and then copied to variable 'strWord'.
			// Variable 'strWord' is then updated.

		void setNext(Node* nextNode);
			// Pre-condition: Pointer 'next' must be existing, and either NULL, or pointing to another Node.
			// Post-condition: Pointer 'next' is set to desired Node.

		void setPrevious(Node* previousNode);
			// Pre-condition: Pointer 'previous' must be existing, and either NULL, or pointing to another Node.
			// Post-condition: Pointer 'previous' is set to desired Node.

// Constant Member Functions.

		valueType getStrWord() const;
			// Pre-condition: Variable 'tempString' must contain a valid string input.
			// Post-condition: The string value in variable 'tempString' is returned.

		Node* getNext() const;
		Node* getNext();
			// Pre-condition: Pointer 'nextNode' must be existing, and either NULL, or pointing to another Node.
			// Post-condition: The value of 'nextNode' is returned.

		Node* getPrevious() const;
		Node* getPrevious();
			// Pre-condition: Pointer 'previousNode' must be existing, and either Null, or pointing to another Node.
			// Post-condition: The value of 'previousNode is returned.


// Private Member Variables
	
	private:
		valueType strWord;
			// Private variable 'strWord', stands for String Word. Holds a string type as definied in typeDef
		Node *next;
			// Private pointer variable 'next'
		Node *previous;
			// Private pointer variable 'previous'
};


#endif