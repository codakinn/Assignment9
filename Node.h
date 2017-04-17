#ifndef NODE_H
#define NODE_H

using namespace std;

class Node
{
  public:
    Node(string key){
      this->key == key;
      data = 0;
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
    void Left(){
      return left; 
    }
    void setRight(Node* current){
      right = current;
    }
    void Right(){
      return right; 
    }
    
  private:
    Node* left;
    Node* right;
    string key;
    int data;
}

#endif NODE_H
