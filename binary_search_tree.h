#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "Node.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class BinarySearchTree{

 public:
  BinarySearchTree();
  ~BinarySearchTree();
  void set(string key, int value);
  int find(string key);
  void print();
  string min();
  string max();
  void save_file(string fName);
  void load_from_file(string fName);
  void Delete(string key);
  
 private:
  Node *root;
  void insertHelper(Node *current, string key, int value);
  void deleteHelper(Node* parent, string key);
  void printHelper(Node *current);
  void destructorHelper(Node *current);
  void saveHelper(Node* current, ofstream& outFile);
  int findHelper(Node* current, string key);

};

#endif
