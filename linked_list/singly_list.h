#include <iostream>

class SinglyNode
{
  public:
    int data;
    SinglyNode* next;
    SinglyNode(int d) : data{d} {}
    SinglyNode(){};
};

class LinkedList
{
  private:
    SinglyNode* head;
  
  public:
    LinkedList(SinglyNode* node)
    {
      head = new SinglyNode();
      head->data = node->data;
      head->next = NULL;
    }

    ~LinkedList()
    {
        deleteList();
    }
    // Print linked list
    void printList();

    // Add a new node at a position pos in the list
    void addNode(SinglyNode* node, int pos);

    // Calculate length of the list
    const uint16_t lengthOfList();

    // Delete the linked list
    void deleteList();

    // Delete node at position pos
    void deleteNode(int pos);

    // Delete all the occurence of given key
    void deleteNodeKey(int key);
};

void LinkedList::printList()
{
    SinglyNode* tNode = head;
    while(tNode != NULL)
    {
        std::cout << tNode->data << " ";
        tNode = tNode->next;
    }
    std::cout << std::endl;
}

void LinkedList::addNode(SinglyNode* node, int pos)
{
    SinglyNode* tNode = head;
    
    if (pos == 0) // Head position
    {
        node->next = tNode;
        head = node;
    }
    else // Positions at the end or in the middle
    {
    for (int i = 0; i < pos - 1; i++)
    {
        tNode = tNode->next;
    }
    SinglyNode* nextNode = tNode->next;
    tNode->next = node;
    node->next = nextNode;
    } 
}

const uint16_t LinkedList::lengthOfList()
{
    uint16_t length = 1;
    SinglyNode* tNode = head;
    while(tNode->next != NULL)
    {
    length++;
    tNode = tNode->next;
    }
    return length;
}

void LinkedList::deleteList()
{
    SinglyNode* tNode = head;
    while(head != NULL)
    {
        tNode = head->next;
        delete head;
        head = tNode;
    }
}

void LinkedList::deleteNode(int pos)
{
    SinglyNode* tNode = head;
    if(pos == 0)
    {
        tNode = head->next;
        head = tNode;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            tNode = tNode->next;
        }
        if(tNode->next != NULL)
        {
            tNode->next = tNode->next->next;
        }
        else
        {
            tNode->next = NULL;
        } 
    }
}

void LinkedList::deleteNodeKey(int key)
{
    SinglyNode* tNode = head;
    SinglyNode* prev = NULL;

    while(tNode)
    {
        if(!prev && tNode->data == key)
        {
            head = tNode->next;
            tNode = head;
        }
        else
        {
            if(tNode->data == key)
            {
                prev->next = tNode->next;
            }
            else
            {
                prev = tNode;
            }
            tNode = tNode->next;
        }
        
    }
}