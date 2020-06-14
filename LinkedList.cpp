/*	LinkedList.cpp

//SENG1120: Assignment 1, Nathan Gervasoni: c3339961
//Implementation file for 'LinkedList.h'.

*/
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "LinkedList.h"
#include "Node.h"


	//Remove a node
	//Delete a node
	LinkedList::LinkedList()
	{
		headNode = NULL;
		tailNode = NULL;
		currentNode = NULL;
		listSize = 0;
	}

	LinkedList::LinkedList(const valueType& strWord)
	{
		headNode = new Node(strWord);
		tailNode = headNode;
		currentNode = tailNode;
		listSize = 1;
	}

	LinkedList::~LinkedList()
	{
		while(headNode != NULL)
		{
			Node* deleteNode = headNode;
			if(headNode == tailNode)
			{
				headNode = NULL; // Setting head to NULL.
				tailNode = NULL; // Setting tail to NULL.
				delete deleteNode; // delete the last Node.
			}
			else
			{
				headNode = headNode->getNext(); // Head node is moved to the next node in list.
				headNode->setPrevious(NULL);	// previous pointer is set to NULL.
				deleteNode->setNext(NULL);		// sets next pointer to NULL.
				delete deleteNode;				// deletes node.
				currentNode = NULL;				// currentNode = NULL;
			}
		}
		listSize = 0;
	}


	void LinkedList::add(const valueType inputWord)
	{
		std::istringstream inputStream(inputWord);
		while(inputStream)
		{
			valueType str;
			inputStream >> str;
			addToTail(str);
		}

	}

	void LinkedList::addToHead(const valueType& strWord)
	{
		if(headNode == NULL)
		{
			headNode = new Node(strWord);
			tailNode = headNode;
			currentNode = headNode;
			listSize = 1;
		}
		else
		{
			Node* tempNode = new Node(strWord);
			headNode->setPrevious(tempNode);
			tempNode->setNext(headNode);
			headNode = tempNode;
			tempNode = NULL;
			listSize++;
		}
	}

	void LinkedList::addToTail(const valueType& strWord)
	{
		if(headNode == NULL) // If head is NULL.
		{
			headNode = new Node(strWord); // Head pointer is set to new node.
			tailNode = headNode;		// Tail pointer set to new node.
			currentNode = headNode;		// Current pointer is set to new node. 
			listSize = 1;				// List size +1.
		}
		else
		{
			Node* tempNode = new Node(strWord); // Creates a temporary node with data.
			tailNode->setNext(tempNode);		// Tail node -> next on the temp node.
			tempNode->setPrevious(tailNode);	// sets previous of temp node. 
			tailNode = tempNode; 				// Tail pointer to the new tail of the list.
			tempNode = NULL;					// Temp is set to NULL.

		}
	}

 void LinkedList::remove(const valueType inputWord)
    {
        std::istringstream inputStream(inputWord); // Puts into into a stringStream.
        std::vector<valueType> matchInput; // Declares a vector of valueType. 

        while(inputStream)
        {

            valueType strWord;
            inputStream >> strWord;
            matchInput.push_back(strWord);
        }

        // Starting at head, iterate through nodes until NULL
        for(moveCurrentToHead(); currentNode != NULL; moveCurrent()) {

            if (currentNode->getStrWord() == matchInput.at(0)) {
                if (currentNode == headNode) {
                    removeFromHead();
                }
                else if (currentNode == tailNode){
                    removeFromTail();
                }
                else {
                    removeFromCurrent();
                }
            }
        }
    }

	/*
	// My code attempt at the extension question. Could not get it to run correctly. Segementation dump :(
if(matchInput.size() > 1)
{
    for (moveCurrentToHead(); currentNode != NULL; moveCurrent())
    {
        //Sets value of
        Node *temp = getCurrentNode();
        //Starting at head, iterate through nodes until NULL
        //Iterate through every input string, if the input
        if (currentNode->getStrWord() == matchInput.at(0))
        {
            startPoint = currentNode;
            moveCurrent();
            for (int i = 1; i < (int)matchInput.size(); i++)
            {
                if (currentNode->getStrWord() == matchInput.at(i) && i == (int)matchInput.size() - 1)
                {
                    endPoint = currentNode;
                }
                else if (currentNode->getStrWord() == matchInput.at(i) && i != (int)matchInput.size() - 1)
                {
                    moveCurrent();
                }
                else
                {
                    break;
                }
            }
        }
        currentNode = temp;
    }
    if (endPoint != NULL)
    {
        currentNode = startPoint;
        while (currentNode != endPoint->getNext())
        {
            if (currentNode == headNode)
            {
                removeFromHead();
            }
            else if (currentNode == tailNode)
            {
                removeFromTail();
            }
            else
            {
                removeFromCurrent();
            }
        }
    }

	*/


	void LinkedList::removeFromHead()
	{
		if(listSize == 0)
		{
			return;
		}

		else if(listSize == 1)
		{
			delete headNode;
			headNode = NULL;
			tailNode = NULL;
			currentNode = NULL;
			listSize--;
			return;
		}

		else
		{
			currentNode = headNode;
			headNode = headNode->getNext();
			delete currentNode;
			if(headNode != NULL)
				headNode->setPrevious(NULL);
			currentNode = headNode;
		}
	}

	void LinkedList::removeFromTail()
	{
		if(listSize == 0)
		{
			return;
		}

		else if(listSize == 1)
		{
			delete headNode;
			headNode = NULL;
			tailNode = NULL;
			currentNode = NULL;
			listSize--;
			return;
		}

		else
		{
			tailNode = tailNode->getPrevious();
			tailNode->setNext(NULL);
			delete tailNode->getNext();
			listSize--;
			currentNode = tailNode;
		}
	}

	void LinkedList::removeFromCurrent()
	{
		Node* tempNode = currentNode->getNext();
		currentNode->getPrevious()->setNext(currentNode->getNext());
		currentNode->getNext()->setPrevious(currentNode->getPrevious());
		delete currentNode;
		currentNode = tempNode;
		tempNode = NULL;
		listSize--;
	}

	void LinkedList::moveCurrent()
	{
		currentNode = currentNode->getNext();
	}


	void LinkedList::moveCurrentToHead()
	{
		currentNode = headNode;
	}

	void LinkedList::moveCurrentToTail()
	{
		currentNode = tailNode;
	}

	Node* LinkedList::getCurrentNode()
	{
		return currentNode;
	}

	int LinkedList::count(const valueType& strWord)
	{
		int count = 0;
		moveCurrentToHead();
		while(currentNode !=NULL)
		{
			if(strWord == currentNode->getStrWord())
			{
				count++;
			}
			moveCurrent();
		}
		return count;
	}

	LinkedList& LinkedList::operator += (LinkedList& inputList)
	{
		inputList.moveCurrentToHead();
		while(inputList.getCurrentNode() != NULL)
		{
			this->addToTail(inputList.getCurrentNode()->getStrWord());
			inputList.moveCurrent();
		}
		return *this;
	}


	std::ostream& operator << (std::ostream& output, LinkedList& inputList)
	{
		inputList.moveCurrentToHead();
		;
		while(inputList.getCurrentNode() != NULL)
		{
			output << inputList.getCurrentNode()->getStrWord() << " ";
			inputList.moveCurrent();
		}
		return output;
	}

