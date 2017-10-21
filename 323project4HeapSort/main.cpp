#include <fstream>
#include <iostream>
using namespace std;
class HeapSort{
public:
    int rootIndex,fatherIndex,minKidIndex;
    int *heapAry;
    int leftKidIndex;
   int rightKidIndex;
   
    HeapSort(int count){
        heapAry= new int[count+1];
        heapAry[0]=0;
    }
    void buildHeap( ifstream &inf,ofstream &of){
        int data;
        
        while(inf>>data){
            rootIndex = 1;
            insertOneDataItem(data);
       
            bubbleUp(heapAry[0]);
            printHeap(of);
        }
           }
    void deleteHeap(ofstream &of1,ofstream &of2){
        of1<<getRoot()<<endl;
        deleteRoot();
        fatherIndex = rootIndex;
        bubbleDown(fatherIndex);
        printHeap(of2);
    }
    void insertOneDataItem(int data){
        heapAry[0]++;
        heapAry[heapAry[0]]=data;
    }
    int getRoot(){
        return heapAry[1];
    }
    void deleteRoot(){
        heapAry[1] = heapAry[heapAry[0]];
        heapAry[0]--;
       
    }
    void bubbleUp(int kidindex){
        if(isRoot(kidindex)||kidindex==0){
            return;}
        else{
            int temp;
            fatherIndex = kidindex/2;
            if(heapAry[kidindex]<heapAry[fatherIndex]){
                temp=heapAry[fatherIndex];
                heapAry[fatherIndex]=heapAry[kidindex];
                heapAry[kidindex]=temp;
                bubbleUp(fatherIndex);
            }
        }
    }
    void bubbleDown(int fatherIndex){
        if(isLeaf(fatherIndex))
        return;
        
           else{
        leftKidIndex =fatherIndex*2;
        rightKidIndex = fatherIndex*2+1;
        int temp;
        findMinKidIndex(fatherIndex);
        if(heapAry[minKidIndex]<heapAry[fatherIndex]){
                       temp=heapAry[minKidIndex];
                       heapAry[minKidIndex]=heapAry[fatherIndex];
                       heapAry[fatherIndex]=temp;
                       bubbleDown(minKidIndex);
        }
           
           }
           }
    
    
    bool isLeaf(int index){
        if(index*2 >heapAry[0] && index*2+1 >heapAry[0]){
            return true;
        }
        return false;
    }
    bool isRoot(int index){
        if(index == 1)
            return true;
        return false;
    }
    void findMinKidIndex (int fatherIndex){
        leftKidIndex =fatherIndex*2;
        rightKidIndex = fatherIndex*2+1;
        if(leftKidIndex<=heapAry[0]&&rightKidIndex<=heapAry[0]){
            if(heapAry[leftKidIndex]<heapAry[rightKidIndex]){
            minKidIndex= leftKidIndex;}
            else minKidIndex = rightKidIndex;
        }
        else if(leftKidIndex<=heapAry[0]){
            minKidIndex=leftKidIndex;}
        else if(rightKidIndex<=heapAry[0]){
            minKidIndex=rightKidIndex;
        }
    }
    
        
        
    
    bool isHeapEmpty(){
        if( heapAry[0] == 0)
            return true;
        else return false;
    }
   
    void printHeap(ofstream &of){
        for(int i=0; i<=heapAry[0];i++){
            of<<heapAry[i]<<" ";
            
        }
        of<<endl;
    }
};
int main(int argc,  char * argv[]) {
   ifstream infile(argv[1]);
    ifstream infile2(argv[2]);
    ofstream outfile1(argv[3]);
    ofstream outfile2(argv[4]);
    if(!infile.is_open()){
        cout<<"The file is not open";
    }
    else {
        int count;
        int data;
        while(infile>>data){
            count++;
        }
    HeapSort *heap =  new HeapSort(count);
    heap->buildHeap(infile2,outfile1);
        while(!heap->isHeapEmpty()){
    heap->deleteHeap(outfile2,outfile1);
        }
    }
    outfile1.close();
    outfile2.close();
}
