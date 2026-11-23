//
// Created by markt on 2026. 11. 23..
//



#include "Student.h"
#include <stdexcept>

Student::Student(int id, const string &firstName, const string &lastName) {
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
}

int Student::getId() const { return id; }
void Student::setId(int id) { this->id = id; }
const string &Student::getFirstName() const { return firstName; }
const string &Student::getLastName() const { return lastName; }
double Student::getAverage() const { return average; }
const map<string, double> &Student::getGrades() const { return grades; }

void Student::addGrade(const string& subject, double grade) {
    grades[subject] = grade;
}

double Student::getGrade(const string& subject) const {
    if (grades.count(subject) == 0) {
        throw out_of_range("Nincs ilyen tantargy!");
    }
    return grades.at(subject);
}

void Student::computeAverage() {
    if (grades.empty()) return;

    double osszeg = 0.0;
    for (auto elem : grades) {
        if (elem.second < 5.0) {
            average = 0.0;
            return;
        }
        osszeg += elem.second;
    }

    double atlag = osszeg / grades.size();
    if (atlag >= 6.0) {
        average = atlag;
    } else {
        average = 0.0;
    }
}

ostream& operator<<(ostream& os, const Student& student) {
    os << student.id << " - " << student.lastName << " " << student.firstName
       << " (Atlag: " << student.average << ")";
    return os;
}
