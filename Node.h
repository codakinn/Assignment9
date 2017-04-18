#ifndef NODE_H
#define NODE_H

using namespace std;

class Node
{
  public:
    Node(string key){
      this->key == key;
      data = 0;
      right = NULL;
      left = NULL;
    }
    void setData(int num){
      data = num;
    }
    int Data(){
      return data;
    }
    void setKey(string key){
      this->key == key;
    }
    string Key(){
      return key;
    }
    void setLeft(Node* current){
      left = current;
    }
    Node* Left(){
      return left; 
    }
    void setRight(Node* current){
      right = current;
    }
    Node* Right(){
      return right; 
    }
    
  private:
    Node* left;
    Node* right;
    string key;
    int data;
};

#endif
