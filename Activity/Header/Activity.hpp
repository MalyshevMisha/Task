#pragma once
#include<string>

class Activity
{
    public:
    std::string name;
    friend bool operator== (Activity &a1, Activity &a2);
};