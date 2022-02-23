#include"Activity.hpp"

bool operator== (Activity &a1, Activity &a2)
{
    if(a1.name == a2.name)
        return true;
    else
        return false;
}