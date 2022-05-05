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
      delete head;
    }

    // Print linked list
    void printList()
    {
      SinglyNode* tNode = head;
      while(tNode != NULL)
      {
        std::cout << tNode->data << " ";
        tNode = tNode->next;
      }
      std::cout << std::endl;
    }

    // Add a new node at a position pos in the list
    void addNode(SinglyNode* node, int pos)
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
};

int main()
{
  LinkedList *list = new LinkedList(new SinglyNode(3));
  list->printList();
  list->addNode(new SinglyNode(5),0);
  list->addNode(new SinglyNode(7),1);
  list->addNode(new SinglyNode(9),3);
  list->printList();
  return 0;  
}