//
//  main.cpp
//  rotateMatrix
//
//  Created by Alby Thomas on 6/26/17.
//  Copyright © 2017 Alby Thomas. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &matrix){
    int m = int(matrix.size());
    
    //Go layer by layer
    for(int layer=0; layer<m/2; ++layer){
        
        //As you into a deeper layer, the first and last values get closer together
        int first = layer;
        int last = m-1-layer;
        
        //You need this for loop to account for the shifts in each of the layers
        for(int i=first; i<last; ++i){
            int offset = i-first;
            
            //Save the top left element
            int top = matrix[first][i];
            
            //set the top left element equal to the bottom left element of the layer
            matrix[first][i] = matrix[last-offset][first];
            
            //bottom left = bottom right
            matrix[last-offset][first] = matrix[last][last-offset];
            
            //bottom right = top right
            matrix[last][last-offset] = matrix[first+offset][last];
            
            //top right = the top left element we saved on line 28
            matrix[first+offset][last] = top;
        }
    }
    
}

int main() {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    rotate(matrix);
    
    for(int row=0; row<matrix.size(); ++row){
        for(int col=0; col<matrix[0].size(); ++col){
            cout<<matrix[row][col]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
