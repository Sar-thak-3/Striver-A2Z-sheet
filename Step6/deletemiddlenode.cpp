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

Node* middleDelete(Node* head){
    Node* temp = head;
    Node* middle = NULL;
    int count = 0;
    while(temp!=NULL){
        if(count%2==0 and count>0){
            if(!middle){
                middle = head;
            }
            else{
                middle = middle->next;
            }
        }
        count++;
        temp = temp->next;
    }
    if(count%2==0){
        middle->next->next = middle->next->next->next;
        return head;
    }
    middle->next = middle->next->next;
    return head;
}

signed main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    Node* ans = middleDelete(head);
    while(ans!=NULL){
        cout<<ans->data<<" ";
        ans = ans->next;
    }
    return 0;
}