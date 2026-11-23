//
// Created by markt on 2026. 11. 23..
//

#ifndef STUDENTSERVICEIMPL_H
#define STUDENTSERVICEIMPL_H

#include "StudentService.h"
#include "GraduationDao.h"

class StudentServiceImpl : public StudentService {
private:
    GraduationDao *dao;

public:
    StudentServiceImpl(GraduationDao *dao) : dao(dao) {}

    bool isEnrolled(int id) const override;
    vector<string> getSubjects(int id) const override;
    double getResultBySubject(int id, const string& subject) const override;
    double getAverage(int id) const override;
    bool isPassed(int id) const override;
};

#endif //CPP_2026_STUDENTSERVICEIMPL_H