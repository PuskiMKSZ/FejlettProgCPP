//
// Created by markt on 2026. 11. 23..
//

#include "GraduationDao.h"
#include <fstream>
#include <stdexcept>

void GraduationDao::enrollStudents(const string &filename) {
    ifstream file(filename);
    int id;
    string lastName, firstName;

    while (file >> id >> lastName >> firstName) {
        students[id] = Student(id, firstName, lastName);
    }
}

void GraduationDao::readGradesSubject(const string &subject, const string &filename) {
    ifstream file(filename);
    int id;
    double grade;

    while (file >> id >> grade) {
        if (students.count(id) > 0) {
            students[id].addGrade(subject, grade);
        }
    }
}

void GraduationDao::computeAverage() {
    for (auto& elem : students) {
        elem.second.computeAverage();
    }
}

int GraduationDao::numEnrolled() const {
    return students.size();
}

int GraduationDao::numPassed() const {
    int sikeres = 0;
    for (auto elem : students) {
        if (elem.second.getAverage() >= 6.0) {
            sikeres++;
        }
    }
    return sikeres;
}

Student GraduationDao::findById(int id) const {
    if (students.count(id) == 0) {
        throw out_of_range("Nincs ilyen azonositoju diak!");
    }
    return students.at(id);
}

double GraduationDao::getAverageBySubject(const string &subject) const {
    double osszeg = 0.0;
    int db = 0;
    for (auto elem : students) {
        if (elem.second.getGrades().count(subject) > 0) {
            osszeg += elem.second.getGrade(subject);
            db++;
        }
    }
    return (db > 0) ? (osszeg / db) : 0.0;
}