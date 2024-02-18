#include <iostream>
#include "MyMatrix.h"
#include "Student.h"
#include "Course.h"
#define FIFTEEN 15
using namespace std;

void testMyMatrix();
void testStudent();

float MyMatrix::sum = ZERO;

int main() {

    testStudent();                                                      //The main of Student

    testMyMatrix();                                                     //The main of MyMatrix

    return 0;
}

void testStudent() {

    char name[FIFTEEN];
    int numOfGrade, grade;
    Student student1, student2, student3;

    cout << "Enter name of student 1:\n";
    cin >> name;
    student1.setName(name);
    cout << "Enter sum of grade:\n";
    cin >> numOfGrade;
    for (int i = 1; i <= numOfGrade; ++i) {                                          //Reception and initialization of student1 details
        cout << "Enter course " << i << " name's:\n";
        cin >> name;
        cout << "Enter grade in " << name << " :\n";
        cin >> grade;
        Course course(name, grade);
        student1 += course;
    }
    cout << "Enter name of student 2:\n";
    cin >> name;
    student2.setName(name);
    cout << "Enter sum of grade:\n";
    cin >> numOfGrade;
    for (int i = 1; i <= numOfGrade; ++i) {
        cout << "Enter course " << i << " name's:\n";
        cin >> name;
        cout << "Enter grade in " << name << " :\n";                                  //Reception and initialization of student2 details
        cin >> grade;
        Course course(name, grade);
        student2 += course;
    }
    cout << "Enter name of student 3:\n";
    cin >> name;
    student3.setName(name);
    cout << "Enter sum of grade:\n";
    cin >> numOfGrade;
    for (int i = 1; i <= numOfGrade; ++i) {                                              //Reception and initialization of student3 details
        cout << "Enter course " << i << " name's:\n";
        cin >> name;
        cout << "Enter grade in " << name << " :\n";
        cin >> grade;
        Course course(name, grade);
        student3 += course;
    }
    cout << "-------------------------------------------\n";
    cout<<student1;
    cout<<student1.getName()<< "'s average is: \n" << student1.operator float()<<endl;
    cout << "-------------------------------------------\n";
    cout<<student2;
    cout<<student2.getName()<< "'s average is: \n" << student2.operator float()<<endl;              //Print the students details and their average
    cout << "-------------------------------------------\n";
    cout<<student3;
    cout<<student3.getName()<< "'s average is: \n" << student3.operator float()<<endl;
    cout << "-------------------------------------------\n";

    //    Course math("math", 90), bio("bio", 78), bio2("bio", 98);
//    student1.setName("shulamit");
//    student1 += math;
//    student1 += bio;
//    student1 += bio2;
//    if (student1.checkIfCourse(bio2.getNameOfCourse())) {                               //Test to all Student function
//        cout << "exist\n";
//    } else
//        cout << "unexist\n";
//    student2 = student1;
//    cout<< student1;
//    cout<<student2;
//    if (student1<student2) {
//        cout << "true\n";
//    } else
//        cout << "false\n";
//    cout << student1.operator float()<< endl;
}

    void testMyMatrix() {
        float num1, num2, num3, num4;
        cout << "Enter first matrix:\n";
        cin >> num1 >> num2 >> num3 >> num4;             // Creates and initializes matrix A
        MyMatrix A(num1, num2, num3, num4);


        cout << "Enter second matrix:\n";
        cin >> num1 >> num2 >> num3 >> num4;             // Creates and initializes matrix B
        MyMatrix B(num1, num2, num3, num4);

        cout << "Enter third matrix:\n";
        cin >> num1 >> num2 >> num3 >> num4;              // Creates and initializes matrix C
        MyMatrix C(num1, num2, num3, num4);


        cout << "-------------------------------------------\n";

        if (A == B)
            cout << "The matrices A and B is equal\n";
        else
            cout << "The matrices A and B is not equal\n";

        if (A == C)
            cout << "The matrices A and C is equal\n";
        else                                                                         // Check and print if the matrices is equal
            cout << "The matrices A and C is not equal\n";

        if (B == C)
            cout << "The matrices B and C is equal\n";
        else
            cout << "The matrices B and C is not equal\n";
        cout << "-------------------------------------------\n";


        cout << "The determinant of the A matrix is " << A.det() << endl;
        cout << "-------------------------------------------\n";

        cout << "The determinant of the B matrix is " << B.det() << endl;                 // Print determinants of the matrices
        cout << "-------------------------------------------\n";

        cout << "The determinant of the C matrix is " << C.det() << endl;
        cout << "-------------------------------------------\n";

        MyMatrix D;
        D = A * B + C;

        cout<< "The matrix D (A*B+C) is: \n"<<D<< endl;                                        // Calculates and prints the matrix D and her determinant
        cout<< "The determinant of D matrix is: \n"<< D.det()<<endl ;

        cout << "-------------------------------------------\n";

        cout<<"The sum of all the matrices is: \n";                                      // Print the sum of all the matrices
        cout << MyMatrix::sum << endl;

        cout << "-------------------------------------------\n";

        cout << "Enter second matrix again:\n";
        cin >> num1 >> num2 >> num3 >> num4;                                       // Updates matrix B values
        B.set(num1, num2, num3, num4);

        cout << "-------------------------------------------\n";

        D = A * B + C;
        cout << "The new matrix D (A*B+C) is: \n"<< D<<endl;              // Calculates and prints the new matrix D and her determinant
        cout<< "The determinant of D matrix is: \n"<< D.det()<<endl ;

        cout << "-------------------------------------------\n";

        cout<<"The sum of all the matrices is: \n";                         // Print the sum of all the matrices
        cout << MyMatrix::sum << endl;
        cout << "-------------------------------------------\n";
    }
