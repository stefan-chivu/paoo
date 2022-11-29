#include<iostream>
#include<list>
#include<stdlib.h>

using namespace std;

class Student {
private:
    int nr_matricol;
    string nume;
public:
    Student(const int nr_matricol, const string nume):
            nr_matricol(nr_matricol), nume(nume){};

    Student(const Student& s) {
        nr_matricol = s.nr_matricol;
        nume = s.nume + " - copy";
    }

    virtual string to_string() {
        return "[ " + std::to_string(nr_matricol) + " ] " + nume;
    }

    bool operator==(const Student& rhs) {
        return (nr_matricol == rhs.nr_matricol) 
                && (nume == rhs.nume);
    }

    Student& operator=(const Student& rhs) {
        nr_matricol = rhs.nr_matricol;
        nume = rhs.nume;

        return *this;
    }
};

class StudentBursier : public Student {
private:
    double valoare_bursa;
public:
    StudentBursier(const int nr_matricol, const string nume,
                   const double valoare_bursa) : Student(nr_matricol, nume),
                   valoare_bursa(valoare_bursa) {};

    // copy constructor ce apeleaza copy constructor-ul super clasei
    StudentBursier(const StudentBursier& s) : Student(s), valoare_bursa(s.valoare_bursa) {};

    string to_string() {
        return Student::to_string() + " - bursa: " + std::to_string(valoare_bursa);
    }

    // copying base class field values as well
    StudentBursier& operator=(const StudentBursier& rhs) {
        Student::operator=(rhs);
        valoare_bursa = rhs.valoare_bursa;
        return *this;
    }
};

class FisaMatricola {
private:
    Student* student;
    list<int> note;
public:
    FisaMatricola(Student* student, const list<int> note):
                  student(student), note(note){};
    
    FisaMatricola& operator=(const FisaMatricola& rhs) {

        // self assignment safety
        Student *stOrig = student;
        student = new Student(*rhs.student);
        delete stOrig;

        note = rhs.note;
        return *this;
    }

    FisaMatricola& operator+=(const FisaMatricola& rhs) {
        // se va face join doar daca studentul este acelasi
        if (student == rhs.student) {
            for (auto const& nota : rhs.note)
                note.push_back(nota);
        }
        return *this;
    }

    void adauga_nota(const int n) {
        note.push_back(n);
    }

    string to_string() {
        string res = (*student).to_string() + ": ";

        for (auto const& nota : note) {
            res += std::to_string(nota) + "; ";
        }
        
        return res;
    }
};