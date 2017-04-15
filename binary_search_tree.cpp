#include <iostream>
#include <string>
#include "binary_search_tree.h"

using namespace std;

BinarySearchTree::BinarySearchTree()
{
  root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
  destructorHelper(root);
}

void BinarySearchTree::destructorHelper(Node *current)
{
  if(current != NULL) {
    destructorHelper(current->left);
    destructorHelper(current->right);
    delete current;
  }
}

void BinarySearchTree::set(string key, int value)
{
  if(root == NULL){
    root = new Node(key, value);    
  }
  else
    insertHelper(root, key, value);
}

void BinarySearchTree::insertHelper(Node* current, string key, int value)
{
   if(value < current -> data) //Insert Left
   {
       if(current -> left == NULL)
         current -> left = new Node(key, value);
       else
         insertHelper(current -> left, key, value);
   }
   else //Insert Right
   {
     if(current -> right == NULL)
       current -> right == new Node(key, value)
     else
       insertHelper(current -> right, key, value);
   }
}

int BinarySearchTree::find(string key)
{
  findHelper(root, key);
}

int BinarySearchTree::findHelper(Node *current, string key)
{
  if(current -> key == key)
    return current -> data;
  else if(current -> key < key)
    findHelper(current -> right, key);
  else if(current -> key > key)
    findHelper(current -> left, key);
}
