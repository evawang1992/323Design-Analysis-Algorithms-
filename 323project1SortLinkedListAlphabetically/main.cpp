//
//  main.cpp
//  project1
//
//  Created by xiaochen wang on 8/31/17.

//
#include<iostream>
#include<fstream>

using namespace std;

class linkedList{
public:   int size=0;
    int count = 0;
    class listNode{
    public:
        string data;
        listNode *next;
        listNode(string value) {
            data = value;
            next = NULL;

        }
        listNode(){
            data = "dummy";
            next = NULL;
        }
        
    };

    listNode *walker;
    listNode *listHead;
    linkedList(){
       listHead = new listNode();
        
        
    }
    
    
    bool isEmpty(){
        if (size==0)
            return true;
        return false;
        
    }
    void listInsert (string inp){
        
        listNode *n = new listNode(inp);
      
            
            walker = listHead;
            
            while(walker->next!=NULL  && inp > walker->next->data ){
                
                        walker = walker->next;
                
        }
            if(walker->next==NULL){
                walker->next = n;
                n->next=NULL;
                size++;
            }
            else{
                n->next = walker->next;
                walker->next=n;
                size++;
            }
        
        count ++;
    
        
    
    }
    
    
    void listDelete (string d){
        if(isEmpty())
            cout<<"The list is empty"<<endl;
        else {
            walker = listHead;
            if(walker->next->data==d){
                listNode *temp = new listNode();
                walker= walker->next;
                delete temp;
            }
            
            walker=walker->next;
            size --;
        }
        
    }
    
    void printList(ofstream &of){
        if(isEmpty())
            of<<"listHead --> (dummy,null)"<<endl;
        else{
            if(count<=15){
            listNode *cursor;
            cursor = listHead;
            of<< "listHead --> (";
            while(cursor->next!=NULL){
                of<<cursor->data+","+cursor->next->data+")-->(";
                cursor=cursor->next;
            
            }
            of<<cursor->data+",null)"<< endl;
            }
        }
        }
};


int main(int argc, char **argv){
    string inp;
    linkedList l;
  
    if (argc <2){
        cout << ("file not extist");
        return -1;
    }
    else {ifstream ifs(argv[1]);
        ofstream ofs(argv[2]);
      
        while(ifs>>inp/*!ifs.eof()*/){
            //ifs>>inp;
            l.listInsert(inp);
            l.printList(ofs);
            }
        
    }
    
    return 0;
}
