#include <iostream>
#include "singly_list.h"

int main()
{
  LinkedList *list = new LinkedList(new SinglyNode(3));
  list->addNode(new SinglyNode(5),0);
  list->addNode(new SinglyNode(5),0);
  list->addNode(new SinglyNode(7),2);
  list->addNode(new SinglyNode(9),3);
  list->addNode(new SinglyNode(5),4);
  list->addNode(new SinglyNode(5),4);
  list->addNode(new SinglyNode(5),2);
  list->addNode(new SinglyNode(5),8);
  list->printList();
  list->deleteNodeKey(5);
  list->printList();
  list->deleteList();
  list->printList();
  return 0;  
}