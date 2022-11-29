#include "include.hpp"

int main(int argc, char* argv[]) {
    Student* student = new Student(12345, "John Doe");
    Student* student2 = new Student(54321, "Jane Doe");
    StudentBursier* studentBursa = new StudentBursier(2222, "StudBurs", 700.00);

    FisaMatricola fm(student, list<int>());

    fm.adauga_nota(10);
    cout << fm.to_string() << endl;

    FisaMatricola fm2(student, list<int>{9, 8, 7});
    FisaMatricola fm3(student2, list<int>{2, 3, 5});

    // item 10:

    fm += fm2;
    cout << fm.to_string() << endl;

    fm = fm2;
    cout << fm.to_string() << endl;

    // self assignment test - item 11
    fm = fm;
    cout << fm.to_string() << endl;

    // NO-OP: fm3.student != fm.student
    fm += fm3;
    cout << fm3.to_string() << endl;
    cout << fm.to_string() << endl;
    

    // item 12:
    FisaMatricola fm4(studentBursa, list<int>{10, 10, 9});

    cout << endl << fm4.to_string() << endl;

    StudentBursier studentBursaCopy(*studentBursa);

    cout << studentBursaCopy.to_string() << endl;

    return 0;

}