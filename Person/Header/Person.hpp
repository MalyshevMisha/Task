#pragma once
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

#include<Activity.hpp>

struct Person
{
    Person();

    void copy(Person & destination);
    void move(Person & destination);
    void print();

    std::string first_name;
    std::string second_name;
    int age;
    std::vector<Activity> occupation;

    friend std::ostream& operator<< (std::ostream &out, Person &pers);
};

