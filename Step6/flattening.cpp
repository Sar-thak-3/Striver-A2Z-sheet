#include "bits/stdc++.h"
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* bottom;
    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node* flatten(Node* head){
    Node* start = head;
    vector<Node*> arr{head};
    Node* ans = NULL;
    Node* ansloop = ans;
    while(!arr.empty()){
        Node* smallest = NULL;
        int smaleest = INT_MAX;
        for(int i=0;i<arr.size();i++){
            if(arr[i]->data < smaleest){
                smaleest = arr[i]->data;
                smallest = arr[i];
            }
        }

        vector<Node*>::iterator it=arr.begin();
        while(it!=arr.end()){
            if(*it==smallest){
                it = arr.erase(it);
            }
            else{
                it++;
            }
        }

        if(ans==NULL){
            ans = new Node(smaleest);
            ansloop = ans;
        }
        else{
            ansloop->next = new Node(smaleest);
            ansloop = ansloop->next;
        }
        if(smallest->next){
            arr.push_back(smallest->next);
        }
        if(smallest->bottom){
            arr.push_back(smallest->bottom);
        }
    }
    return ans;
}

signed main(){
    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);
    head->next = new Node(10);
    head->next->bottom = new Node(20);
    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);
    head->next->next->next = new Node(28);

    Node* ans = flatten(head);
    while(ans!=NULL){
        cout<<ans->data<<" ";
        ans = ans->next;
    }
    return 0;
}