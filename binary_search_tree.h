#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string>
using namespace std;

class Node{
 private:
  Node *left;
  Node *right;
  string key;
  int data;
  
 public:
  Node(string search, int value){
    key = search;
    data = value;
  }
};

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
  void delete(string key);
  
 private:
  Node *root;
  void insertHelper(Node *current, string key, int value);
  void deleteHelper(string key);
  void printHelper(Node *current);
  void destructorHelper(Node *current);
  int findHelper(Node* current, string key);

};

#endif
