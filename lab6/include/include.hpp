#include<iostream>
#include<list>
#include<stdlib.h>
#include<memory>

using namespace std;

int TOTAL_POPULATION;

class Continent {
private:
    int total_population;
    string name;
public:
    Continent(const int total_population, const string name):
              total_population(total_population), name(name) {};

    string to_string() {
        return "Continent " + name + ": " 
               + std::to_string(total_population) + " inhabitants";
    }

    void variate_population(int number) {
        total_population += number;
    }
 };

class Country {
private:
    int population;
    string name;
    shared_ptr<Continent> continent;
public:
    Country(const int population, const string name,
            const shared_ptr<Continent> continent):
            population(population), name(name),
            continent(continent)
    {
        continent->variate_population(population);
    };
    
    ~Country() {
        continent->variate_population(-1 * population);
    }

    // copiem pointer-ul si modificam si valoarea populatiei continentului
    Country(const Country& c) {
        name = c.name + " - copy";
        population = c.population;
        continent = c.continent;
        continent->variate_population(population);
    }

    Country& operator=(const Country& c) {
        return *this;
    }

    void variate_population(int number) {
        population += number;
        continent->variate_population(number);
    }

    string to_string() {
        return name + ": " + std::to_string(population) + " inhabitants";
    }
};
