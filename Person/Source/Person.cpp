#include<Person.hpp>


Person::Person()
{
    age = 0;
}

void Person::copy(Person & destination)
{
    destination.first_name = first_name;
    destination.second_name = second_name;
    destination.age = age;
    std::copy(occupation.begin(), occupation.end(), 
            std::back_inserter(destination.occupation));
}

void Person::move(Person & destination)
{
    destination.first_name = first_name;
    first_name.clear();
    destination.second_name = second_name;
    second_name.clear();
    destination.age = age;
    age = 0;
    std::copy(occupation.begin(), occupation.end(), 
            std::back_inserter(destination.occupation));
    occupation.clear();
}

void Person::print()
{
    std::cout<<"Person:\n"
        <<"\tFirst name:\t"<<first_name<<"\n"
        <<"\tSecond name:\t"<<second_name<<"\n"
        <<"\tAge:\t"<<age<<"\n";

    std::cout<<"\tOccupation:\n";
    for(auto & i : occupation)
        std::cout<<"\t\t"<<i.name<<std::endl;
}

std::ostream& operator<< (std::ostream &out, Person &pers)
{
    out<<"Person:\n"
        <<"\tFirst name:\t"<<pers.first_name<<"\n"
        <<"\tSecond name:\t"<<pers.second_name<<"\n"
        <<"\tAge:\t"<<pers.age<<"\n";
    
    out<<"\tOccupation:\n";
    for(auto & i : pers.occupation)
        out<<"\t\t"<<i.name<<"\n";
    return out;
}