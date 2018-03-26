//
//  main.cpp
//  abhi
//
//  Created by Abhishek Raj on 24/03/18.
//  Copyright © 2018 Abhishek Raj. All rights reserved.
//
#include <iostream>
using namespace std;
struct node{
    int data;
    node*parent;
    node*left;
    node*right;
    node(){
        parent = NULL;
        left = NULL;
        right = NULL;
    }
};
class binarytree{
public:
    node*root;
    binarytree(){
        root = NULL;
    }
    void insert(int val){
        node*temp = new node;
        node*store = new node;
        temp->data = val;
        temp->parent = NULL;
        temp->right=NULL;
        temp->left=NULL;
        if(root==NULL){
            root = temp;
        }
        else{
            store = root;
            while(store->left!=NULL&&store->right!=NULL){
                if(temp->data<store->data){
                    store= store->left;
                }
                if(temp->data>store->data){
                    store = store->right;
                }
            }
            temp->parent = store;
            if(val<store->data){
                store->left = temp;
            }
            else{
                store->right = temp;
            }
        }
        
        
    }
    
    void display(node *temp)
    {
        node* curr=temp;
        if(curr)
        {
            display(curr->left);
            cout<<curr->data<<" "<<endl;
            display(curr->right);
        }
    }
    void search(int key){
        node*temp = new node;
        temp=root;
        bool find = false;
        while(find!=true && temp!=NULL){
            if(key == temp->data){
                cout<<"The key is found\n";
                find = true;
            }
            if(key<temp->data){
                temp=temp->left;
            }
            if(key>temp->data){
                temp=temp->right;
            }
            
        }
        if(find==false){
            cout<<"not found!\n";
        }
        
    }
    void deletenode(int key){
        node*temp = new node;
        node*store1 = new node;
        node*store2 = new node;
        node*store3 = new node;
        temp = root;
        bool find = false;
        while(find!=true&&temp!=NULL){
            if(key==temp->data){
                find = true;
            }
            if(key<temp->data){
                temp=temp->left;
            }
            if(key>temp->data){
                temp=temp->right;
            }
        }
        if(find==true){
            if(temp->right==NULL && temp->left==NULL){
                delete temp;
            }
            if(temp->right==NULL && temp->left!=NULL){
                store1 = temp->left;
                store2 = temp->parent;
                store1->parent = store2;
                store2->left = store1;
                delete temp;
            }
            if(temp->right!=NULL&&temp->left==NULL){
                store1 = temp->right;
                store2 = temp->parent;
                store1->parent = store2;
                store2->right = store1;
                delete temp;
            }
            if(temp->right!=NULL && temp->left!=NULL){
                store1 = temp->left;
                store2 = temp->parent;
                store3 = temp->right;
                store1->parent = store2;
                store2->left = store1;
                store1->right = store3;
                delete temp;
            }
        }
        else
            cout<<"not found\n";
    }
};
int main(){
    binarytree ob;
    ob.insert(10);
    ob.insert(8);
    ob.insert(17);
    ob.insert(2);
    ob.insert(12);
    node*temp = ob.root;
    ob.display(temp);
    ob.search(10);
    ob.deletenode(17);
    ob.display(temp);
}
