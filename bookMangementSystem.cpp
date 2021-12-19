#include<stdio.h>
#include<conio.h>
#include<string>
#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int id;
        string Name;
        Node* next; 
};

Node* head = new Node();

bool check(int x){
    if(head == NULL)
        return false;

    Node* t = new Node;
    t = head;

    while(t != NULL){
        if (t->id == x)
            return true;
        t = t->next;
    }
    return false;
}

void Insert_Record(int id, string name){
    if(check(id)){
        cout<< "Book Already Exist..\n";
        return;
    }

    Node* t =new Node();
    t->id = id;
    t->Name = name;

    //Insert At Begining
    if(head == NULL || (head->id >= t->id)){
        t->next = head;
        head = t;
    }
    //Insert At Middle or End
    else{
        Node* c = head;
        while(c->next != NULL && c->next->id < t->id){
            c = c->next;
        }
        t->next = c->next;
        c->next = t;
    }
    cout<<"Record Inserted Successfully..";
}

void Search_Record(int id){
    if(!head){
        cout<< "No such Record Available\n";
        return;
    }
    else{
        Node* p = head;
        while(p){
            if(p->id == id){
                cout << "Book id\t"<< p->id << endl;
                cout << "Name\t\t"<< p->Name << endl;
                return;
            }
            p = p->next;
        }
        if(p == NULL)
            cout<<"No such Record Available..\n";
    }
}
int Delete_Record(int id)
{
    Node* t = head;
    Node* p = NULL;
 
    // Deletion at Begin //If found at start then head will be shifted at nxt node
    if (t != NULL && t->id == id) {
        head = t->next;
        delete t;
 
        cout << "Record Deleted Successfully\n";
        return 0;
    }
 
    // Deletion Other than Begin
    else{
    	
		while (t != NULL && t->id != id) {
	        p = t;
	        t = t->next;
	    }
	    if (t == NULL) {
	        cout << "Record does not Exist\n";
	        return -1;
	    }
	        p->next = t->next;
	 
	        delete t;
	        cout << "Record Deleted "
	             << "Successfully\n";
	 
	        return 0;
	    
	}
    
}
void Show_Record()
{
    Node* p = head;
    if (p == NULL) {
        cout << "No Record "
             << "Available\n";
    }
    else {
        cout << "\t ID\tName\n";
 
        // Until p is not NULL
        while (p != NULL) {
            cout <<"\t"<<p->id << "\t"
                 << p->Name << "\t \n";
            p = p->next;
        }
    }
}
int main()
{
    head = NULL;
    string Name;
    int id;
 
    // Menu-driven program
    while (true) {
        cout << "\n\t\tWelcome to Book "
                "Management System\n\n\tPress\n\t1 to "
                "create a new Record\n\t2 to delete a "
                "Book record\n\t3 to Search a Book "
                "Record\n\t4 to view all Books "
                "record\n\t5 to Exit\n";
        cout << "\nEnter your Choice\n";
        int Choice;
 
        // Enter Choice
        cin >> Choice;
        if (Choice == 1) {
            cout << "Enter Book Id\n";
            cin >> id;
            cout << "Enter Book Name\n";
            cin >> Name;
            Insert_Record(id, Name);
        }
        else if (Choice == 2) {
            cout << "Enter Book id to Delete Record\n";
            cin >> id;
            Delete_Record(id);
        }
        else if (Choice == 3) {
            cout << "Enter Book id to Search Book\n";
            cin >> id;
            Search_Record(id);
        }
        else if (Choice == 4) {
            Show_Record();
        }
        else if (Choice == 5) {
            exit(0);
        }
        else {
            cout << "Invalid Choice "
                 << "Try Again\n";
        }
    }
    return 0;
}
