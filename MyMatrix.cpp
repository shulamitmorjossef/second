//
// Created by Student on 8/27/2023.
//
#include <iostream>
#include "MyMatrix.h"
using namespace std;
MyMatrix::MyMatrix(){
    //This function is an empty constructor - initialize the matrix to 0
    mat[0][0] = ZERO;
    mat[0][1] = ZERO;
    mat[1][0] = ZERO;
    mat[1][1] = ZERO;
}
MyMatrix::MyMatrix(float num1, float num2, float num3, float num4){
    //This function is a constructor, accepts 4 float numbers and initialize the matrix accordingly
    mat[0][0] = num1;
    mat[0][1] = num2;
    mat[1][0] = num3;
    mat[1][1] = num4;
    updateSum(*this, '+');
}
MyMatrix::MyMatrix(const MyMatrix& matrix){
    //This function is a copy constructor
    set(matrix.mat[0][0], matrix.mat[0][1],matrix.mat[1][0],matrix.mat[1][1]);
}
MyMatrix::~MyMatrix() {
    //This function is an empty destructor
    }
void MyMatrix::set(float num1, float num2, float num3, float num4) {
    //This function accepts 4 float numbers and initialize the matrix accordingly and update sum
    updateSum(*this, '-');
    mat[0][0] = num1;
    mat[0][1] = num2;
    mat[1][0] = num3;
    mat[1][1] = num4;
    updateSum(*this, '+');
}
float MyMatrix::det(){
    // This function calculate the determinant of the matrix
    float one, two;
    one = mat[0][0]*mat[1][1];
    two = mat[0][1]*mat[1][0];
    return (one - two) ;
}
MyMatrix& MyMatrix::operator=(const MyMatrix & matrix){
    //This function is an assignment operator, accepts as parameter a matrix and updates this with the parameter values
    //The function update sum also
    updateSum(*this, '-');
    this->mat[0][0] = matrix.mat[0][0];
    this->mat[0][1] = matrix.mat[0][1];
    this->mat[1][0] = matrix.mat[1][0];
    this->mat[1][1] = matrix.mat[1][1];
    updateSum(*this, '+');
    return *this;
}
MyMatrix MyMatrix::operator+(const MyMatrix& matrix){
    //This function is an operator+, it does not change the matrix
    MyMatrix new_matrix;
    new_matrix.mat[0][0] = this->mat[0][0] + matrix.mat[0][0];
    new_matrix.mat[0][1] = this->mat[0][1] + matrix.mat[0][1];
    new_matrix.mat[1][0] = this->mat[1][0] + matrix.mat[1][0];
    new_matrix.mat[1][1] = this->mat[1][1] + matrix.mat[1][1];
    return new_matrix;
}
MyMatrix MyMatrix::operator*(const MyMatrix& matrix){
    //This function is an operator*, it does not change the matrix
    MyMatrix new_matrix;
    new_matrix.mat[0][0] = this->mat[0][0] * matrix.mat[0][0] + this->mat[0][1] * matrix.mat[1][0];
    new_matrix.mat[0][1] = this->mat[0][0] * matrix.mat[0][1] + this->mat[0][1] * matrix.mat[1][1];
    new_matrix.mat[1][0] = this->mat[1][0] * matrix.mat[0][0] + this->mat[1][1] * matrix.mat[1][0];
    new_matrix.mat[1][1] = this->mat[0][1] * matrix.mat[1][0] + this->mat[1][1] * matrix.mat[1][1];
    return new_matrix;
}
bool MyMatrix::operator==(const MyMatrix& matrix){
    //This function is an operator==, it return true if the matrices is equal and false if they didn't
    if(this->mat[0][0] == matrix.mat[0][0]&&
        this->mat[0][1] == matrix.mat[0][1] &&
        this->mat[1][0] == matrix.mat[1][0]&&
        this->mat[1][1] == matrix.mat[1][1]){
        return true;
    }
    return false;
}
ostream& operator<<(ostream & os, MyMatrix& matrix){
    //This function is a print operator - print the matrix
    os << matrix.mat[0][0]<< " " << matrix.mat[0][1]<< "\n"<<
    matrix.mat[1][0]<< " " << matrix.mat[1][1]<< "\n";
    return os;
}
void MyMatrix::updateSum(const MyMatrix& matrix, char sign){
    //This function is a static function = update som(static variable);
    if(sign == '+') {
        sum = MyMatrix::sum + matrix.mat[0][0] + matrix.mat[0][1] + matrix.mat[1][0] + matrix.mat[1][1];
    } else
        sum = MyMatrix::sum - matrix.mat[0][0] - matrix.mat[0][1] - matrix.mat[1][0] - matrix.mat[1][1];
}
