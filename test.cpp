#include <iostream>
#include "time.h"
using namespace std;

struct node {
    node *left;
    node *right;
    int value;
    node(){
        left = NULL;
        right = NULL;
        value = -1;
    }
};

int count = -1;

void dfs(node *current){
    if(current != NULL){
        dfs(current->left);
        ::count++;
        if (::count % 10 == 0)
            cout << endl;
        cout << current->value << " ";
        dfs(current->right);
    }
    return;
}

int main(int argc, char *argv[]){

    int array[100];
    int arrayLength = sizeof(array) / sizeof(array[0]);
    srand(time(NULL));
    for(int i = 0; i < arrayLength; i++){
        array[i] = rand() % 500;
    }


    node *root = new node;
    root->value = array[0];
    
    for(int i = 1; i < arrayLength; i++){
        // Prepare new node to be added
        node *newnode = new node;
        newnode->value = array[i];
        newnode->left = NULL;
        newnode->right = NULL;

        // Start current at the root
        node *current = root;
        node *prev;

        // Find the correct place in the tree for array[i]
        while(current != NULL){
            if(newnode->value >= current->value){
                prev = current;
                current = current->right; 
            }
            else if(newnode->value < current->value){
                prev = current;
                current = current->left;
            }
        }

        if(prev->value < newnode->value){
            prev->right = newnode;
        }
        else{
            prev->left = newnode;
        }
    }

    dfs(root);

    return 0;
}
