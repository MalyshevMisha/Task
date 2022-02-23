#include<Activity.hpp>
#include<Person.hpp>
#include<memory>

int main()
{
    std::unique_ptr<Person> per(new Person);
    per->print();
    per->first_name = "Misha";
    per->second_name = "Mal";
    per->age = 22;

    std::vector<Activity> occ;
    Activity act;
    act.name = "ondfjms";
    occ.push_back(act);

    per->occupation = occ;

    per->print();

    std::unique_ptr<Person> per1(new Person);
    per->move(*per1);
    per->print();
    per1->print();

    std::cout<<*per;

    return 0;
}