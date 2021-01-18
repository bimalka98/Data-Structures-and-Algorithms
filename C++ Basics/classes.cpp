#include <iostream>
#include <string>
using namespace std;

class Person{

private://only inside this class
  //varibale declaratioon
  int age;
  string name;

public: // inside and out side the class
    Person(string name, int age){
      //cout << "Constructor called!"<< '\n';
      this->name = name;
      this->age = age;
    }
    ~Person(){
      cout << "Destructor called!" << '\n';
    }

//******************************************************************************
//Accessors - GETTERS
const string& getName() const
// function does not copy the name. it just passes the reference
// function a reference to a constant string
//function does not change anything
{
  return this->name;
}

const int& getAge() const
{
  return this->age;
}
//******************************************************************************
//Modifiers -SETTERS
void setName(const string name)
{
  this->name = name;
}
void setAge(const int age)
{
  this->age = age;
}
//******************************************************************************
//FUNCTIONS
const string toString() const
{
  return this->name + " is " + to_string(this->age) + " years old!";
}



};

int main(){
Person me("Bimalka", 23);
// me.setAge(23);
// me.setName("Bimalka");
cout << me.toString() << '\n';

// Person bro;
// bro.setAge(18);
// bro.setName("Madusanka");
// cout << bro.toString() << '\n';

return 0;
}
