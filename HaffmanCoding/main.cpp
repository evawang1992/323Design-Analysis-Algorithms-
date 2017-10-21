#include <iostream>
#include <fstream>
using namespace std;
class listBinTreeNode{
public:
    string chStr;
    int prob;
    listBinTreeNode *next;
    listBinTreeNode *left;
    listBinTreeNode *right;
    listBinTreeNode(string c, int p){
        chStr = c;
        prob = p;
        next=NULL;
        right =NULL;
        left =NULL;
    }
    listBinTreeNode(){
        next=NULL;
        right =NULL;
        left =NULL;
        
    }
    void printNode(listBinTreeNode *node,ofstream &outfile5){// given a node, T, print T’s chStr, T’s prob, T’s next chStr,
          
          outfile5<<"("<<node->chStr<<","<<node->prob<<")"; //T’s left’s chStr, T ‘s right’s chStr
          if(node->next!=NULL){
              outfile5<<"("<<"next: "<<node->next->chStr<<")";
          }
          if(node->left!=NULL){
              outfile5<<"("<<"left: "<<node->left->chStr<<")";
          }
          if(node->right!=NULL){
              outfile5<<"("<<"right: "<<node->right->chStr<<")";
          }
        outfile5<<"\n";
        
    }
    
};
    class HuffmanLinkedList{
    public:
        listBinTreeNode *listHead;
        listBinTreeNode *newListHead;
        HuffmanLinkedList (){
            listHead= new listBinTreeNode("dummy",0);
            listHead->next=NULL;
        }
        
        void constructHuffmanLList(ifstream &inf, HuffmanLinkedList *l,ofstream &of){
            string ch;
            int pr;
                while( inf>> ch>> pr){
                    listBinTreeNode *nnode = new listBinTreeNode(ch,pr);
                    l->listInsert(findSpot(pr),nnode);
                    l->printList(of);
                }
        }
        
        listBinTreeNode *findSpot(int p){
             listBinTreeNode *walker;
             listBinTreeNode *spot;
         
            if(isEmpty()){
                spot = NULL;
            }
            else {
                walker = listHead;
                while(walker->next!=NULL && walker->next->prob < p){
                walker = walker->next;
                }
             spot = walker;
            }
            return spot;
        }
        
       void  listInsert(listBinTreeNode *spot, listBinTreeNode *NNode){
           if(spot==NULL)
           {
               listHead = NNode;
               listHead->next = NULL;
           }
           if(spot->next!=NULL)
           {
               NNode->next = spot->next;
               spot->next = NNode;
           }
           else
           {
               spot->next = NNode;
               NNode -> next = NULL;
           }
        }
       
        bool isEmpty(){
            if(listHead== NULL)
                return true;
            else return false;
        }
        
        void printList(ofstream &outfile5){
            listBinTreeNode *cursor;
           if(listHead->prob==0){
                cursor = listHead;
                  outfile5<<"listHead-->";
                while(cursor->next!=NULL){
                    outfile5<<"("<<cursor->chStr<<","<<cursor->prob<<","<<cursor->next->chStr<<")->";
                    cursor=cursor->next;
                }
                outfile5<<"("<<cursor->chStr<<","<<cursor->prob<<","<<"NULL)"<<endl;
            }
            
           else {cursor = listHead->next;
                outfile5<<"listHead-->";
                while(cursor->next!=NULL){
                    outfile5<<"("<<cursor->chStr<<","<<cursor->prob<<","<<cursor->next->chStr<<")->";
                    cursor=cursor->next;
                }
                outfile5<<"("<<cursor->chStr<<","<<cursor->prob<<","<<"NULL)"<<endl;
            }
        }
    };

    class HuffmanBinaryTree{
    public:
        listBinTreeNode *root;
        listBinTreeNode *newListHead;
        HuffmanBinaryTree(){//constructors
            root = NULL;
        }
        void constructHuffmanBinTree(HuffmanLinkedList *list,ofstream &of){
            string sumchar;
            int sum;
            listBinTreeNode *newListHead = new listBinTreeNode("dummy",0);
            newListHead->next=list->listHead->next;
            listBinTreeNode *NewNode = new listBinTreeNode();
            while(newListHead->next->next!=NULL){
                listBinTreeNode *NNode = new listBinTreeNode();
                sumchar =newListHead->next->chStr + newListHead->next->next->chStr;
                sum =newListHead->next->prob + newListHead->next->next->prob;
                NNode->chStr = sumchar;
                NNode->prob = sum;
                NNode->left =newListHead->next;
                NNode->right = newListHead->next->next;
                //list->listHead = list->listHead->next->next;
                newListHead = newListHead->next->next;
                NNode->printNode(NNode,of);
                list->listInsert(list->findSpot(sum), NNode);
                list->printList(of);
                NewNode = NNode;
                
            }
            root=NewNode;
        }
        
        void preOrderTraveral(listBinTreeNode *n,ofstream &of){
            if(n==NULL) return;
            else{
                n->printNode(n, of);
                preOrderTraveral(n->left, of);
                preOrderTraveral(n->right,of);
            }
        }
        
        void inOrderTraveral(listBinTreeNode *m, ofstream &of) {
            if (m==NULL) return;
            else{
                inOrderTraveral(m->left,of);
                m->printNode(m, of);
                inOrderTraveral(m->right,of);
            }
            
        }
        
        void postOrderTraveral(listBinTreeNode *rt,ofstream &of){
            if(rt==NULL) return;
            else{
                
                preOrderTraveral(rt->left,of);
                preOrderTraveral(rt->right,of);
                rt->printNode(rt, of);
            }
   
            
        }
        
        bool isLeaf(listBinTreeNode *node){
            if( node->left== NULL && node->right == NULL)
                return true;
            return false;
        }
      
        void constructCharCode(listBinTreeNode *nod,ofstream &of, string c){
            
            if(nod==NULL){
                cout<<"This is an empty tree "<<endl;//
                exit(1);
            }
            else {
                if (isLeaf(nod)){
                    of<<"<"<<nod->chStr<<" ";

                    of<<c<<">"<<endl;
                }
                else {
                    constructCharCode(nod->left, of, c+"0");
                    constructCharCode(nod->right, of, c+"1");
                }
            }
        }
       void printTreeNode(listBinTreeNode *node){
            cout<<node->chStr<<endl;
        }
   

    };
    
int main(int argc, char **argv){
    
    ifstream infile(argv[1]);
    ofstream outfile1(argv[2]);
    ofstream outfile2(argv[3]);
    ofstream outfile3(argv[4]);
    ofstream outfile4(argv[5]);
    ofstream outfile5(argv[6]);
    if(!infile.is_open())
        cout<<"the file is not open"<<endl;
    else{
        
        HuffmanLinkedList *list = new HuffmanLinkedList();
        HuffmanBinaryTree *tree = new HuffmanBinaryTree();
        list->constructHuffmanLList(infile,list,outfile5);
        tree->constructHuffmanBinTree(list, outfile5);
        tree->preOrderTraveral(tree->root,outfile2);
        tree->inOrderTraveral(tree->root,outfile3);
        tree->postOrderTraveral(tree->root,outfile4);
        tree->constructCharCode(tree->root,outfile1,"");
       
    }
    
}

