#include <iostream>
using namespace std;

//The following codes are for HW1 Question #1 -- creating 2D array and count the frequency of each number .
// Created by Wei Ye. 
// Copyright by Wei. No replicates allowed.
// Date: 09/13/2022

void CountFrequency(int arr[3][4]){
    int count[9]={0};
    for (int i =0; i<3; i++){
        for (int j = 0; j < 4; j++){
            if(arr[i][j]==1){
                count[0]++;
            }else if (arr[i][j]==2){
                count[1]++;
            }else if (arr[i][j]==3){
                count[2]++;
            }else if (arr[i][j]==4){
                count[3]++;
            }else if (arr[i][j]==5){
                count[4]++;
            }else if (arr[i][j]==6){
                count[5]++;
            }else if (arr[i][j]==7){
                count[6]++;
            }else if (arr[i][j]==8){
                count[7]++;
            }else{
                count[8]++;
            }
        }
    }
    cout << "The frequency between 1 and 9 are: "<< endl;
    for (int i =0; i<9;i++){
        cout << count[i] << endl;
    }
}


int main(){
    int fordham[3][4] = {{1,2,3,4},{5,6,7,8},{9,1,2,3}};
    CountFrequency(fordham);
    return 0;
}

