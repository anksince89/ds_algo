#include <iostream>
#include "singly_list.h"

int main()
{
  LinkedList *list = new LinkedList(new SinglyNode(3));
  list->printList();
  list->addNode(new SinglyNode(5),0);
  list->addNode(new SinglyNode(7),1);
  list->addNode(new SinglyNode(9),3);
  list->printList();
  std::cout << list->lengthOfList() << std::endl;
  list->deleteNode(0);
  list->printList();
  
  return 0;  
}