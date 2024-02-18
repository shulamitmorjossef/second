//
// Created by Student on 8/28/2023.
//
#include <cstring>
#include "Student.h"

Student::Student(){
    //This function is an empty constructor
    name = nullptr;
    head = nullptr;
}
Student::Student(const Student& student):name(nullptr), head(nullptr){
    // This function is a copy constructor
    *this = student;
}
Student::~Student(){
//This function is a destructor
    delete [] name;
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->getNext();
        delete temp;
    }
}
Student& Student::operator=(const Student& student) {
//    //This function is an assignment operator, accepts as parameter a Student and updates this with the parameter values
    if (this->name == student.name)
        return *this;                                               // Check that the student is not same
    else {
        setName(student.name);                                         //update the name
        while ((head)){
            Node* current(this->head);
            head = head->getNext();
            delete current->getCourse();                              //Delete the current linked list
            delete current;
        }
        Node* current(student.head);
        while (current) {
            *this += *(current->getCourse());                           //Update the linked list
            current = current->getNext();
        }
    }
}
void Student::setName(char* name){
    //This function setter the name of student
    delete [] this->name;
    this->name = new char [strlen(name)+1];
    for (int i = 0; i< strlen(name)+1 ; ++i)
        this->name[i] = name[i];
}
bool Student::checkIfCourse(char* course){
    //This function check if course exist in linked list, it return true if the course is exist and false if it didn't
    Node* current = head;
    while (current){
        if(strcmp(current->getCourse()->getNameOfCourse(), course)==ZERO){
            return true;
        } else
            current = current->getNext();
    }
    return false;
}
Student& Student::operator+=(const Course& course) {
    //This function is an operator +=, it accepts course as parameter and add the parameter to the linked list, if the course exist already, it just update the grade
    Course *new_course = new Course(course.getNameOfCourse(), course.getGrade());
    Node *newNode = new Node(new_course);
    if (!head){                                        // Check if the linked list is empty
        head = newNode;
        return *this;
    }
    Node* current = head;
    while (current) {
        if (strcmp(current->getCourse()->getNameOfCourse(), course.getNameOfCourse()) == ZERO) {
            current->getCourse()->setGrade(course.getGrade());
            return *this;                                                // Check if the course exist in list and update the grade
        }
        current = current->getNext();
    }
    Node* add = new Node(new_course);
    add->setNext(head);                                         //Add the course to the linked list
    head = add;
    return *this;
}
ostream& operator<<(ostream & os, Student& student){
    //This function is a print operator, it print student details
     os << student.name << ":" << endl;                                   // Prints the name of student
     Student::Node* current(student.head);
     while (current){                                                     //Print the courses details of student
         os<< "   " <<current->getCourse()->getNameOfCourse()<< ": " << current->getCourse()->getGrade()<<"\n";
         current = current->getNext();
     }
    return os;
}
bool Student::operator<(const Student& student){
    // This function is an operator < , it return true if the num of courses of this is smaller then the parameter student and false in else case
    int count1, count2;
    Node* current1(this->head);
    while (current1){                                  // Check the sum of courses of this
        ++count1;
        current1 = current1->getNext();
    }
    Node* current2(student.head);
    while (current2){                                  // Check the sum of courses of the parameter student
        ++count2;
        current2 = current2->getNext();
    }
    if (count1 < count2)                               // Check who is bigger
        return true;
    return false;
}
Student::operator float(){
    //This function is an casting operator, it return the average of the courses
    Node* current(this->head);
    int sumOfCourses = ZERO;
    float average = ZERO;
    if(!current)
        return 0;                             // Return 0 if the courses list is empty
    while (current){
        ++sumOfCourses;
        average += current->getCourse()->getGrade();         //Sum up the grades and the number of courses
        current = current->getNext();
    }
    average = average/sumOfCourses;                         //Calculate the average
    return average;
}
char* Student::getName(){
    //This function return name of student
    return name;
}