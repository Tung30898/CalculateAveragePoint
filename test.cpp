#include "test.h"

std::vector<Student*> inform;

NAME_SUBJECT ConvertSubjectName (const string subjectName) {
    NAME_SUBJECT ret = SUBJECT_MAX;
    if("math" == subjectName) {
        ret = MATH;
    } else if("physical" == subjectName) {
        ret = PHYSICAL;
    } else if("schematic" == subjectName) {
        ret = SCHEMATIC;
    } else if("english" == subjectName) {
        ret = ENGLISH;
    } else {
        cout << "subject's name is failed";
    }
    return ret;
}

TYPE_GRADE ConvertGradeType(const string gradeType) {
    TYPE_GRADE ret = GRADE_MAX;
    if("primary" == gradeType) {
        ret = PRIMARY;
    } else if("medium" == gradeType) {
        ret = MEDIUM;
    } else if("finish" == gradeType) {
        ret = FINISH;
    } else {
        cout << "Grade's type is failed";
    }
    return ret;
}

string ConvertGradeType2String(const TYPE_GRADE gradeType) {
    string ret = "barbage";
    switch(gradeType) {
        case PRIMARY:
            ret = "primary";
            break;
        case MEDIUM:
            ret = "medium";
            break;
        case FINISH:
            ret = "finish";
            break;
        default:
            cout << "the code is error";
            break;
    }
    return ret;
}

string ConvertSubjectName2String(const NAME_SUBJECT subjectName) {
    string ret = "subject max";
    switch(subjectName) {
        case MATH:
            ret = "math";
            break;
        case PHYSICAL:
            ret = "physical";
            break;
        case ENGLISH:
            ret = "english";
            break;
        case SCHEMATIC:
            ret = "schematic";
            break;
        default:
            cout << "the code is error";
            break;
    }
    return ret;
}

void input() {
    string name;
    int glass = 0;
    string subject = "";
    string gradeType = "";
    float point;
    Grade* gradeStudent = new Grade();
    Student* mStudent = new Student();

    cout << "Student's Name:";
    cin >> name;
    cout << "Enter the Glass:";
    cin >> glass;
    cout << "Input Subject's Name:";
    cin >> subject;
    cout << "Enter The Grade Type:";
    cin >> gradeType;
    cout << "Enter The point:";
    cin >> point;
    if(point>=0 && point<=10)
        gradeStudent->mGrade = point;
    gradeStudent->mGradeType = ConvertGradeType(gradeType);
    gradeStudent->mNameSubject = ConvertSubjectName(subject);
    mStudent->SetName(name);
    mStudent->SetGlass(glass);
    mStudent->SetmGradeOfStudent(gradeStudent);
    inform.push_back(mStudent);
}

void output() {
    for(auto& i:inform) {
        cout << "\n" << i->GetName() << "\n";
        cout << i->GetGlass() << "\n";
        for(auto& j:i->GetGradeOfStudent()) {
            cout << ConvertSubjectName2String(j.first) << "\n";
            for(auto& u:j.second) {
                cout << ConvertGradeType2String(u.first)<<"\n";
                cout << u.second;
            }
        }
    }
}

int main() {
    input();
    output();
    return 0;
}