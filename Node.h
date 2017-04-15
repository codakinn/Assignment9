#ifndef NODE_H
#define NODE_H

using namespace std;

class Node
{
  public:
    Node(string key){
      this->key == key;
    }
    Node* &operator=(Node* copy){
      this->left = copy->left;
      this->right = copy->right;
      this->key = copy->key;
      this->data = copy->data;
    }
    void setData(int num){
      data = num;
    }
    int getData(){
      return data;
    }
    void setKey(string key){
      this->key == key;
    }
    string getKey(){
      return key;
    }
    void setLeft(Node* current){
      left = current;
    }
    
    void setRight(Node* current){
      right = current;
    }
    
  private:
    Node* left;
    Node* right;
    string key;
    int data;
}

#endif NODE_H
