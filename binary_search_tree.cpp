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
    root = new Node(key);
    
  }
  else
    insertHelper(root, key, value);
}
