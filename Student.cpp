/*
    Student.cpp

    Demonstration of generalization/inheritance concepts

    Note: To provide an overview, inline methods are used
*/

#include <vector>
#include <memory>
#include <cassert>

class Student {
public:
    virtual int costTuition() { return 0; }
};

class Undergraduate : public Student {
public:
    int costTuition() { return 1000; }
};

class Graduate : public Student {

};

void collectTuition(Student student) {

}

int main() {

    Student student;
    assert(student.costTuition() == 0);

    Undergraduate ugrad;
    assert(ugrad.costTuition() == 1000);

    Student* pStudent = &student;
    assert(pStudent->costTuition() == 0);
    pStudent = &ugrad;
    assert(pStudent->costTuition() == 1000);

    collectTuition(student);
    collectTuition(ugrad);

    return 0;
}
