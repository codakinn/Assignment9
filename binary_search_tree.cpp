#include <iostream>
#include <string>
#include <fstream>
#include "binary_search_tree.h"
#include "Node.h"

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
    destructorHelper(current->Left());
    destructorHelper(current->Right());
    delete current;
  }
}

void BinarySearchTree::set(string key, int value)
{
  if(root == NULL){
    root = new Node(key);
    root->setData(value);
  }
  else
    insertHelper(root, key, value);
}

void BinarySearchTree::insertHelper(Node* current, string key, int value)
{
   if(key == current->Key())
   {
     current->setData(value);
   }
   else if(key < current->Key()) //Insert Left
   {
       if(current->Left() == NULL){
         current->setLeft(new Node(key));
         current->Left()->setData(value);
       }
       else
         insertHelper(current->Left(), key, value);
   }
   else if(key > current->Key) //Insert Right
   {
     if(current->Right() == NULL)
       current->setRight(new Node(key));
     else
       insertHelper(current->Right(), key, value);
   }

}

int BinarySearchTree::find(string key)
{
  return findHelper(root, key);
}

int BinarySearchTree::findHelper(Node *current, string key)
{
  while(current != NULL){
   if(current->Key() == key)
      return current->Data();
    else if(current -> Key() < key)
      findHelper(current -> Right(), key);
    else if(current -> Key() > key)
      findHelper(current -> Left(), key);
  }
  return 0;
}

void BinarySearchTree::print()
{
  printHelper(root); 
}

void BinarySearchTree::printHelper(Node* current)
{
  printHelper(current -> Left());
  cout << current -> Key() << " - " << current -> Data();
  printHelper(current -> Right());
}

string BinarySearchTree::min()
{
  Node* current = root;
  while(current -> Left() != NULL)
    current = current -> Left();
  return current -> Key(); 
}

string BinarySearchTree::max()
{
  Node* current = root;
  while(current -> Right() != NULL)
    current = current -> Right();
  return current -> Key();
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
  saveHelper(current -> Left(), outFile);
  outFile << current -> Key() << " - " << current -> Data();
  saveHelper(current -> Right(), outFile);
}

void BinarySearchTree::delete(string key)
{
  deleteHelper(root, key);
}

void BinarySearchTree::deleteHelper(Node* &parent, string key)
{
  if(parent == NULL)
    return;
  
  while(parent -> Left() -> Key() != key && parent -> Right() -> Key() != key)
  {
    if(key < parent -> Key()) //Go Left
      deleteHelper(parent -> Left(), key);
    if(key > parent -> key) //Go Right
      deleteHelper(parent -> Right(), key);
  }
  
  if(parent -> Right() -> Key() == key) //Key Found right
  {
    Node* c1 = parent -> Right();
    if(c1 -> Right() == NULL && c1 -> Left() == NULL) //Node is Leaf
    {
      parent -> setRight(NULL);
      delete c1;
    }
    else if(c1 -> Right() == NULL && c1 -> Left() != NULL) //Left Tree exists
    {
      parent -> setRight(c1 -> Left());
      delete c1;
    }
    else if(c1 -> Right() != NULL && c1 -> Left() == NULL) //Right tree exists
    {
      parent -> setRight(c1 -> Right());
      delete c1;
    }
    else //Both Trees exist
    {
      Node* child = c1 -> Left();
      while(child->Key() < child->Right->Key() && child->Right() != NULL)
        child = child->Right();
      c1 -> setKey(child->Key());
      c1 -> setData(child->Data());
      delete child;
    }
  } 
 else if(parent -> Left() -> Key() == key) //Key found left
 {
    Node* c1 = parent -> Left();
    if(c1 -> Right() == NULL && c1 -> Left() == NULL) //Node is Leaf
    {
      parent -> setLeft(NULL);
      delete c1;
    }
    else if(c1 -> Right() == NULL && c1 -> Left() != NULL) //Left Tree exists
    {
      parent -> setLeft(c1 -> Left());
      delete c1;
    }
    else if(c1 -> Right() != NULL && c1 -> Left() == NULL) //Right tree exists
    {
      parent -> setLeft(c1 -> Right());
      delete c1;
    }
    else //Both Trees exist
    {
      Node* child = c1 -> Left();
      while(child->Key() < child->Right->Key() && child->Right() != NULL)
        child = child->Right();
      c1 -> setKey(child->Key());
      c1 -> setData(child->Data());
      delete child;
    }
 }
}

void BinarySearchTree::load_from_file(string fName)
{
  ifstream inFile;
  inFile.open(fName.c_str());
  while(inFile.fail()){
    cout << "File not found. Please enter another." << endl;
    cin >> fName;
    inFile.open(fName.c_str());
  }
  while(true){
    string word;
    char x;
    if(!inFile >> x) break;
    while((x >= 65; && x =< 90 || x >= 97 && x <= 122){
      if(x > 97)
        x = x - 32;
      word += x;
      inFile >> x;
    }
    int count = find(word);
    set(key, count);
  }
  inFile.close();
}
