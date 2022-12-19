#include <iostream>
#include "matrixADT.h"

// HW1 Question3
// Created by Wei Ye
// Date: 09/13/2022, modified: 9/21/2022 -- add constructmatrix function and modify constructor. 

using namespace std;


float ** MatrixADT::constructmatrix(int rows, int cols){
    float ** temp0 = new float *[rows]; // allocate heap space w.r.t rows
    for (int i = 0; i < rows; i++){
        temp0[i] = new float[col]; // in column space
    }
    return temp0;
}
/*Note: for this funciton, I credited to Xirong. Because I didn't know how to 
return the private data member matrix in cosntructor. So he told me to use dynamic array. 
But I write this function on my own. 
*/


MatrixADT::MatrixADT():row(0),col(0){
    constructmatrix(0,0);
}//default constructor;

MatrixADT::MatrixADT(int new_row, int new_col){
    row=new_row;
    col=new_col;
    Matrix = constructmatrix(row, col);// Return the prive data member Matrix.
}// 
float MatrixADT::getcolumn() const{
    return col;
}

float MatrixADT::getrow() const{
    return row;
}

void MatrixADT::MatrixFilling(){
    int base = 0;
    for (int i=0;i<row;i++){
        for (int j = 0; j < col; j++){
            Matrix[i][j] = base; 
            base++;
        }
    }
}// filling the matrix automatically.

float MatrixADT :: GetMatrix(){
    for (int i = 0; i< row; i++){
        for (int j= 0; j < col; j++){
            cout << Matrix[i][j] << " ";//leave space between numbers.
        }
        cout << endl;// For each row, when enumerate all the columns, start a new line. 
    }
}

float MatrixADT :: MatrixAddition(const MatrixADT &mat1,const  MatrixADT &mat2){
    if ((mat1.getcolumn()!=mat2.getcolumn()) && (mat1.getrow() != mat2.getrow()){
        cout << "Redefine your matrix, They are not same dimension." << endl;
        return 1;
    }
    else {
        Matrix temp1(mat1.row, mat2.row);

        for (int i = 0; i < row; i++){
            for (int j = 0; j< col; j++){
                temp[i][j] = Mat1[i][j] + Mat2[i][j];
            }
        }
        return temp1;
    }
}

float MatrixADT :: MatrixMul(const MatrixADT & mat1, const MatrixADT &mat2){
    if (mat1.getcolumn() != mat2.getrow()){
        cout << "They can not be multiplied. Please reinput the matrix."
        return 1;
    }else{
        temp2=(mat1.getrow(),mat2.getcolumn())
        for (int i = 0; i < row; i++){
            for (int j = 0; j <col; j++){
                temp2[i][j]=Mat1[i][j] * Mat2[j][i];
            }
        }
        return temp2;
    }
}


//test case;
int main(){
    int mat1r, mat2r;
    int mat1c, mat2c;
    cout << "input row of fist matrix:" << endl;
    cin >> mat1r;
    cout << "input row of second matrix: " << endl;
    cin >> mat2r;
    cout << "input col of first matrix:"<< endl;
    cin >> mat1c;
    cout << "input col of second matrix:"<< endl;
    cin >> mat2c;
    MatrixADT mat1(mat1r,mat1c), mat2(mat2r,mat2c);
    mat1.MatrixFilling();
    mat2.MatrixFilling();
    mat1.GetMatrix();
    mat2.GetMatrix();
    MatrixADT::matrixMult(&mat1, &mat2);
    MatrixADT:: MatrixAddition(&mat1,&mat2);
    return 0;
}