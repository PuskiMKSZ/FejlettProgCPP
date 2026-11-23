//
// Created by markt on 2026. 11. 23..
//

#include "StudentServiceImpl.h"

bool StudentServiceImpl::isEnrolled(int id) const {
    try {
        dao->findById(id);
        return true;
    } catch (...) {
        return false;
    }
}

vector<string> StudentServiceImpl::getSubjects(int id) const {
    Student s = dao->findById(id);
    vector<string> lista;
    for (auto elem : s.getGrades()) {
        lista.push_back(elem.first);
    }
    return lista;
}

double StudentServiceImpl::getResultBySubject(int id, const string& subject) const {
    Student s = dao->findById(id);
    return s.getGrade(subject);
}

double StudentServiceImpl::getAverage(int id) const {
    Student s = dao->findById(id);
    return s.getAverage();
}

bool StudentServiceImpl::isPassed(int id) const {
    Student s = dao->findById(id);
    return s.getAverage() >= 6.0;
}