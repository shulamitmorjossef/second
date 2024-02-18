//
// Created by Student on 8/28/2023.
//
#include <iostream>
#include "Course.h"
#define ZERO 0
#ifndef SECHW_STUDENT_H
#define SECHW_STUDENT_H
using namespace std;

class Student {
private:
    class Node{                       // Start Node class
    private:
        Course* course;                                          // Statement of Node department members
        Node* next;
    public:
        explicit Node(Course* course):course(course){
            //This function is constructor ith parameters
            next = nullptr;
        }
        ~Node(){
            //This function is n destructor
            delete course;
            next = nullptr;
        }
        void setNext(Node* nextNode){
            //This function setter the next node in the lined list
            this->next = nextNode;                                 //Declaration of members of the Node class
        }
        Course* getCourse() const{
            //This return course in node
            return course;
        }
        Node* getNext() const{
            //This function return the next node in the linked list
            return next;
        }

    };                                 // close Node class

    char* name;
    Node* head;                                       // Statement of Student department members
public:
    Student();
    Student(const Student&);
    ~Student();
    Student& operator=(const Student& student);
    void setName(char* );
    char* getName();
    bool checkIfCourse(char*);                                   // Statement of Student department functions
    Student& operator+=(const Course& course);
    friend ostream& operator<<(ostream &, Student&);
    bool operator<(const Student&);
    operator float();



};


#endif //SECHW_STUDENT_H
