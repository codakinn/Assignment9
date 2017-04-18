#include <iostream>
#include "binary_search_tree.h"
#include <iomanip>

using namespace std;

int main()
{
  BinarySearchTree myTree;
  cout << "Welcome to BST File Manager!" << endl;
  int userChoice = 0;
  while(userChoice != -1){
    cout << "What would you like to do?" << endl;
    cout << "1. Add instance of word to list" << endl;
    cout << "2. Search for word" << endl;
    cout << "3. Print first word (alphabetical)" << endl;
    cout << "4. Print last word (alphabetical)" << endl;
    cout << "5. Print entire list of data" << endl;
    cout << "6. Delete word" << endl;
    cout << "7. Save data to new file" << endl;
    cout << "8. Load file" << endl;
    cin >> userChoice;
    
    if(userChoice == 1){
      string word;
      cout << "Please enter the word to add: " << endl;
      cin >> word;
      myTree.set(word, myTree.find(word));
      cout << "Done!" << endl;
      cout << endl;
    }
    else if(userChoice == 2){
      string word;
      cout << "Please enter the word to search: " << endl;
      cin >> word;
      cout << endl;
      cout << word << " - " << myTree.find(word) << " times" << endl;
      cout << endl;
    }
    else if(userChoice == 3){
      cout << "The smallest (alphebetical) word in the list is..." << endl;
      cout << myTree.min() << " - " << myTree.find(myTree.min()) << " times" << endl;
      cout << endl;
    }
    else if(userChoice == 4){
      cout << "The largest (alphabetical) word in the list is..." << endl;
      cout << myTree.max() << " - " << myTree.find(myTree.max()) << " times" << endl;
      cout << endl;
    }
    else if(userChoice == 5){
      cout << "--------LIST OF DATA--------" << endl;
      cout << "WORDS        ||        TIMES" << endl;
      myTree.print();
      cout << "--------END OF DATA --------" << endl;
      cout << endl;
    }
    else if(userChoice == 6){
      string word;
      cout << "Please enter the word you wish to delete: " << endl;
      cin >> word;
      if(myTree.delete(word))
        cout << "Deleted!" << endl;
      cout << endl;
    }
    else if(userChoice == 7){
      string fName;
      cout << "Please enter the name of the file to write to: " << endl;
      cin >> fName;
      if(myTree.save_to_file(fName))
        cout << "File saved!" << endl;
    }
    else if(userChoice == 8){
      cout << "Please enter a data file for analysis: ";
      string fileName;
      cin >> fileName;
      if(myTree.load_from_file(fileName))
        cout << "File loaded" << endl; 
    }
  }
}
