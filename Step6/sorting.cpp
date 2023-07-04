#include "bits/stdc++.h"
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void sorted(Node** head){
    Node* temp = *head;
    while(temp->next!=NULL){

        Node* temp2 = temp->next;
        Node* smallest = temp2;
        while(temp2->next!=NULL){
            if(temp2->next->data < smallest->next->data){
                smallest = temp2;
            }
            temp2 = temp2->next;
        }
        if(smallest->next and smallest->next->data < temp->next->data){
            Node* next = temp->next;
            temp->next = smallest->next;
            if(smallest->next->next){
                smallest->next = smallest->next->next;
            }
            else{
                smallest->next = NULL;
            }
            temp->next->next = next;
        }

        temp = temp->next;
    }

    temp = *head;
    if(temp->next->data < temp->data){
        int data = temp->next->data;
        temp->next->data = temp->data;
        temp->data = data;
    }
    return;
}

signed main(){
    Node* head = new Node(6);
    head->next = new Node(5);
    head->next->next = new Node(4);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);
    // head->next->next->next->next->next = new Node(1);

    sorted(&head);
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    return 0;
}