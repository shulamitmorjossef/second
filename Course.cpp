//
// Created by Student on 8/27/2023.
//
#include <cstring>
#include "Course.h"

Course::Course(const char* name, int grade):name(nullptr){
    //This function is a constructor with parameters = initialize the course accordingly
    this->setName(name);
    this->setGrade(grade);
}
int Course::getGrade()const{
    //This function return grade in course
    return grade;
}
char* Course::getNameOfCourse() const{
    //This function return name of course
    return name;
}
Course::~Course(){
    //This function is a destructor
    delete[]name;
}
Course& Course::operator=(const Course& course){
    //This function is an assignment operator, accepts a course as parameter and update this with the parameter values
    this->setGrade(course.getGrade());
    this->setName(course.getNameOfCourse());
}
void Course::setGrade(int grade){
    //This function setter the grade in the course
    this->grade = grade;
}
void Course::setName(const char* name){
    //This function setter the name of course
    delete[]this->name;
    this->name = new char [strlen(name)+1];
    for (int i = 0; i< strlen(name)+1 ; ++i)
        this->name[i] = name[i];
}