#include<iostream>
using namespace std;

class Uncopyable {
protected: // allow construction
Uncopyable() {} // and destruction of
~Uncopyable() {} // derived objects...
private:
Uncopyable(const Uncopyable&); // ...but prevent copying
Uncopyable& operator=(const Uncopyable&);
};

class Address {
private:
    string street;
    string town;
public:
    Address(const string street, const string town):
                    street(street),
                    town(town){}
    string to_string() {
        return (street + ", " + town);
    }

    Address(const Address& a) {
        street = a.street + " - copy";
        town = a.town + " - copy";
    }

    ~Address() {
        cout << "Destroying address: " << to_string() << endl;
    }
};

class Student: private Uncopyable {
private:
    string name;
    Address& address;
public:
    Student(const string name, Address& address):
                     name(name), address(address){};

    string to_string() {
        return (name + ": " + address.to_string());
    }
};

int main(int argc, char* argv[]) {
    Address addr = Address("101 Ave", "New York");
    Address addr_copy(addr);
    Student student("John Doe", addr);
    cout << student.to_string() << endl;

    // Student student2(student); throws undefined reference error
    // Student student2 = student; throws error
}