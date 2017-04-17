#include <iostream>
#include <string>
#include <fstream>
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

void BinarySearchTree::insertHelper(Node* current, string key, int value)
{
   if(key < current -> key) //Insert Left
   {
       if(current -> left == NULL)
         current -> left = new Node(key);
       else
         insertHelper(current -> left, key, value);
   }
   else if(key > current -> key) //Insert Right
   {
     if(current -> right == NULL)
       current -> right == new Node(key)
     else
       insertHelper(current -> right, key, value);
   }
   else if(key == current -> key)
   {
     current.setData(value);
   }
}

int BinarySearchTree::find(string key)
{
  return findHelper(root, key);
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

void BinarySearchTree::print()
{
  printHelper(root); 
}

void BinarySearchTree::printHelper(Node* current)
{
  printHelper(current -> left);
  cout << current -> key << " - " << current -> data;
  printHelper(current -> right);
}

string BinarySearchTree::min()
{
  Node* current = root;
  while(current -> left != NULL)
    current = current -> left;
  return current -> key; 
}

string BinarySearchTree::max()
{
  Node* current = root;
  while(current -> right != NULL)
    current = current -> right;
  return current -> key;
}

void BinarySearchTree::save_file(string fName)
{
  ofstream outFile;
  outFile.open(fName.c_str());
  while(outFile.fail())
  {
    string fileName; 
    cout << "File unavailable for writing. Please enter another." << endl;
    cin >> fileName;
    outFile.open(fileName.c_str());
  }
  saveHelper(root, outFile);
  outFile.close();
}

void BinarySearchTree::saveHelper(Node* current, ofstream outFile)
{
  saveHelper(current -> left, outFile);
  outFile << current -> key << " - " << current -> data;
  saveHelper(current -> right, outFile);
}

void BinarySearchTree::delete(string key)
{
  deleteHelper(root, key);
}

void BinarySearchTree::deleteHelper(Node* &current, string key)
{
  if(current == NULL)
    return;
  
  while(current -> left -> key != key && current -> right -> key != key)
  {
    if(key < current -> key) //Go Left
      deleteHelper(current -> left);
    if(key > current -> key) //Go Right
      deleteHelper(current -> right);
  }
  
  if(current -> right -> key == key) //Key Found right
  {
    if(current -> right -> right == NULL && current -> left == NULL) //Node is Leaf
    {
      
    }
    else if(current -> right == NULL && current -> left != NULL) //Left Tree exists
    {
      
    }
    else if(current -> right != NULL && current -> left == NULL) //Right tree exists
    {
      
    }
    else //Both Trees exist
    {
      Node* temp = current -> left; 
      while(temp -> right != NULL)
        temp = temp -> right; 
      
    }
  } 
 if(current -> left -> key == key) //Key found left
 {
    if(current -> left -> left == NULL && current -> left -> right == NULL) //Node is leaf
    {
    }
    else if(current -> left -> left == NULL && current -> left -> right != NULL) //Right Tree exists
    {
    }
    else if(current -> left -> left != NULL && current -> left -> right == NULL) //Left Tree exists
    {
    }
    else //Both Trees Exist
    {
      Node* temp == current -> left -> left;
      while(temp -> right != NULL)
        temp = temp -> right; 
      current = temp;
      delete temp;
    }
 }
}
