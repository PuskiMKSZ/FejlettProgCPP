#include <iostream>
#include "Student.h"
#include "GraduationDao.h"
#include "StudentService.h"
#include "StudentServiceImpl.h"

using namespace std;

int main() {
    string subjects[] {"maths", "romanian", "hungarian"};
    int numSubjects = sizeof(subjects) / sizeof(subjects[0]);

    GraduationDao dao(2023);
    dao.enrollStudents("names.txt");
    cout << "Number of enrolled students: " << dao.numEnrolled() << endl;

    for (int i = 0;  i < numSubjects; ++i) {
        dao.readGradesSubject(subjects[i], subjects[i] + ".txt");
    }


    dao.computeAverage();
    cout << "Number of passed students: " << dao.numPassed() << endl;

    StudentService* service = new StudentServiceImpl(&dao);
    cout << "Individual results: " << endl;
    int id = 0;

    while (id != -1) {
        cout << "Enter ID (-1 for EXIT): ";
        cin >> id;
        if (id == -1) {
            break;
        }
        if (!service->isEnrolled(id)) {
            cout << "Student id=" << id << " not found" << endl;
            continue;
        }
        cout << "Student id=" << id << " results: " << endl;
        bool passed = service->isPassed(id);
        cout << "\tpassed: " << (passed ? "yes" : "no") << endl;
        if (!passed) {
            continue;
        }
        vector<string> diakTantargyai = service->getSubjects(id);
        for (int i = 0; i < diakTantargyai.size(); ++i) {
            cout << "\t" << diakTantargyai[i] << ": "
                 << service->getResultBySubject(id, diakTantargyai[i]) << endl;
        }
        cout << "\taverage: " << service->getAverage(id) << endl;
    }

    delete service;
    return 0;
}