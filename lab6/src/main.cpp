#include "include.hpp"
#include <memory>

using namespace std;

int main(int argc, char* argv[]) {
    // folosesc shared_ptr pentru a fi sigur de eliberarea memoriei
    // respective la finalul executiei
    shared_ptr<Continent> pContinent(new Continent(0, "Africa"));

    Country c(150000, "Algeria", pContinent);
    Country c2(100000, "South Sudan", pContinent);
    Country c3(c2);
    Country c4 = c3;

    cout << c.to_string() << std::endl;
    cout << c2.to_string() << std::endl;
    cout << c3.to_string() << std::endl;
    cout << c4.to_string() << std::endl;
    cout << pContinent->to_string() << std::endl;

    c2.variate_population(-50000);
    c4.variate_population(60000);
    cout << endl;

    cout << c.to_string() << std::endl;
    cout << c2.to_string() << std::endl;
    cout << c3.to_string() << std::endl;
    cout << c4.to_string() << std::endl;
    cout << pContinent->to_string() << std::endl;

    return 0;
}