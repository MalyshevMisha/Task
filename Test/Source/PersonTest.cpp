#include<gtest/gtest.h>
#include"Person.hpp"

class PersonTest : public ::testing::Test 
{
protected:
  void SetUp() override 
  {
    pers1 = std::make_unique<Person>();
  }

  void init_pers1()
  {
    pers1->first_name = "Misha";
    pers1->second_name = "Mal";
    pers1->age = 22;

    std::vector<Activity> occ;
    Activity act;
    act.name = "o";
    occ.push_back(act);
    pers1->occupation = occ;

    pers2 = std::make_unique<Person>();
  }

  std::unique_ptr<Person> pers1;
  std::unique_ptr<Person> pers2;
};

TEST_F(PersonTest, constructor)
{
    std::cout<<pers1->age;
    EXPECT_TRUE(pers1->first_name.empty());
    EXPECT_TRUE(pers1->second_name.empty());
    EXPECT_TRUE(pers1->age == 0);
    EXPECT_TRUE(pers1->occupation.empty());
}

TEST_F(PersonTest, copy)
{
    init_pers1();
    pers1->copy(*pers2);
    EXPECT_TRUE(pers1->first_name == pers2->first_name);
    EXPECT_TRUE(pers1->second_name == pers2->second_name);
    EXPECT_TRUE(pers1->age == pers2->age);
    for(int i = 0; i < pers1->occupation.size() && i < pers2->occupation.size(); ++i)
    {
      EXPECT_EQ(pers1->occupation[i].name, pers2->occupation[i].name);
    }
}

TEST_F(PersonTest, move)
{
    init_pers1();
    pers1->move(*pers2);
    EXPECT_TRUE(pers1->first_name.empty());
    EXPECT_TRUE(pers1->second_name.empty());
    EXPECT_TRUE(pers1->age == 0);
    EXPECT_TRUE(pers1->occupation.empty());
    EXPECT_TRUE(pers2->first_name == "Misha");
    EXPECT_TRUE(pers2->second_name == "Mal");
    EXPECT_TRUE(pers2->age == 22);

   
    std::string o = "o";

    EXPECT_EQ(pers2->occupation[0].name, o);
}