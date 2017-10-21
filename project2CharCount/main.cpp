//
//  main.cpp
//  project2
//
//  Created by Eva on 9/8/17.
//  Copyright © 2017 Eva. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;
int main (int argc, char **argv){
    char input;
    int table[256];
    int index;
    ifstream is(argv[1]);
    ofstream outfile(argv[2]);
    if (argc <3){
        cout << ("file not extist");
        return -1;
    }
    else {
        for(int i= 0; i<=256; i++){
            table [i]=0;
        }
        while(is.get(input)){
            if(input != ' '&& input != '\n' && input != '\t'&& input!='\r'){
                index = (int) input;
                table[index]++;
                
            }
        }
        for(int i=0; i<=256; i++){
            if(table[i]>0){
                if(outfile.is_open()){
                    outfile <<(char)i<<" "<<table[i]<<endl;
                }
                
            }
        }
        
        
    }

}

