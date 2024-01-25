#ifndef TEST_H
#define TEST_H

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef enum NAME_SUBJECT_TAG : unsigned char {
    MATH,
    PHYSICAL,
    SCHEMATIC,
    ENGLISH,
    SUBJECT_MAX
} NAME_SUBJECT;

typedef enum TYPE_GRADE_TAG : unsigned char {
    PRIMARY,
    MEDIUM,
    FINISH,
    GRADE_MAX
} TYPE_GRADE;

class Grade {
public:
    TYPE_GRADE mGradeType;
    NAME_SUBJECT mNameSubject;
    float mGrade;
    float mAverageSub;
};

class Student {
private:
    string mName;
    int mGlass;
    std::map<NAME_SUBJECT,std::map<TYPE_GRADE,float>> mGradeOfStudent;
    float mAverage;
public: 
    string GetName() {
        return this->mName;
    }
    int GetGlass() {
        return this->mGlass;
    }
    auto GetGradeOfStudent() {
        return mGradeOfStudent;
    }
    void SetName(string name) {
        this->mName = name;
    }
    void SetGlass(int glass) {
        this->mGlass = glass;
    }
    void SetmGradeOfStudent(Grade* gradeOfStudent) {
        mGradeOfStudent.insert(make_pair(gradeOfStudent->mNameSubject,std::map<TYPE_GRADE,float>()));
        mGradeOfStudent[gradeOfStudent->mNameSubject].insert(make_pair(gradeOfStudent->mGradeType,gradeOfStudent->mGrade));
    }
};

void input();
void output();
string ConvertSubjectName2String(const NAME_SUBJECT subjectName);
string ConvertGradeType2String(const TYPE_GRADE gradeType);
TYPE_GRADE ConvertGradeType(const string gradeType);
NAME_SUBJECT ConvertSubjectName (const string subjectName);

#endif