//
// Created by Student on 8/27/2023.
//

#ifndef SECHW_MYMATRIX_H
#define SECHW_MYMATRIX_H
#include <iostream>
#define ZERO 0
using namespace std;


class MyMatrix {
public:
    MyMatrix();
    MyMatrix(float, float, float, float);
    MyMatrix(const MyMatrix& mat);
    ~MyMatrix();
    void set(float, float, float, float);
    friend ostream& operator<<(ostream&, MyMatrix&);
    float det();                                                 // Statement of MyMatrix Department Functions
    MyMatrix& operator=(const MyMatrix &);
    MyMatrix operator+(const MyMatrix &);
    MyMatrix operator*(const MyMatrix &);
    bool operator==(const MyMatrix &);

    static float sum;
    static void updateSum(const MyMatrix& matrix, char sign);



private:
    float mat[2][2];                                              // Statement of MyMatrix Department members


};


#endif //SECHW_MYMATRIX_H
