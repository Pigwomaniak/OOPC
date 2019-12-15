#pragma once

#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Employee{
private:

public:
    string name;
    string position;
    int age;

    Employee(string  newName, string  newPosition, const int newAge)
    :name(std::move(newName)), position(std::move(newPosition)), age(newAge){};

    friend ostream&operator << (ostream& out, const Employee& src){
        out << src.name << "\t" << src.position << "\t" << src.age << endl;
        return out;
    }

    bool operator == (const Employee& second) const{
        return (name == second.name && position == second.position && age == second.age);
    }
    bool operator != (const Employee& second) const{
        return (name != second.name || position != second.position || age != second.age);
    }
};