//
// Created by Student on 8/27/2023.
//

#ifndef SECHW_COURSE_H
#define SECHW_COURSE_H


class Course {
private:
    char* name;                                              // Statement of course department members
    int grade;
public:
    Course(const char*, int);
    ~Course();
    int getGrade()const;
    char* getNameOfCourse() const;                            // Statement of Course Department Functions
    Course& operator=(const Course&);
    void setGrade(int);
    void setName(const char*);

};


#endif //SECHW_COURSE_H
