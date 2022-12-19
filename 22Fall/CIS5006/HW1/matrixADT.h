#ifndef MATRIXADT_H
#define MATRIXADT_H


class MatrixADT
{
public:
    MatrixADT();
    MatrixADT(int new_row,int new_col);
    void MatrixFilling();
    float MatrixAddition(const Matrix &mat1, const Matrix &mat2);
    float matrixMult(const Matrix &mat1, const Matrix &mat2 );
    float GetMatrix() const;
    float getrow() const;
    float getcolumn() const;
    float **constructmatrix (int rows, int cols);


private:
    int row;
    int col;
    float  **Matrix; // pointer to pointer idea referred to Xirong.

};

#endif;