#include <bits/stdc++.h>
     using namespace std;
     struct node{
     int data;
     node* next;
    };
       node* newnode(int x)
     {
     node* temp=new node();
     temp->data=x;
     temp->next=NULL;
     return temp;
     }
     int main()
    {
    int t;cin>>t;
     while(t--)
    {
    int n,k;cin>>n>>k;
    int x;cin>>x;
    node* head=newnode(x);
    node* headlist=head;
    for(int i=1;i<n;i++)
    {
     int y;cin>>y;
     head->next=newnode(y);
     head=head->next;
    }
    node* prev=NULL,*current=headlist;
    for(int i=1;i<k;i++)
    {
     prev=current;
     current=current->next;
    }
    if(prev==NULL)
    {
     headlist=current->next;
     delete(current);
    }
    else
    {
     node* nxt=current->next;
     prev->next=nxt;
     delete(current);
    }
     while(headlist!=NULL)
    {
     cout<<headlist->data<<" ";
      headlist=headlist->next;
    }
    cout<<"\n";
    }
    return 0;
    }