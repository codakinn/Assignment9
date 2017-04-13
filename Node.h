#ifndef NODE_H
#define NODE_H

class Node
{
 private:
  Node* left;
  Node* right;
  string key;
  int data;
  
 public:
  Node(string key)
    {
      key = key;
    }
}

#endif NODE_H
