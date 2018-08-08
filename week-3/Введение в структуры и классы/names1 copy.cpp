#include <map>

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
   full_name[year].name = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
    full_name[year].surname = last_name;
  }

  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
    bool flag = true;
    string n = "with unknown first name";
    string s = "with unknown last name";
    string result = "Incognito";
    for(const auto& i: full_name) {
      if (i.first <= year) {
       if(i.second.name != "") {
        n = i.second.name;
        flag = false;
       } 
       if(i.second.surname != "") {
        s = i.second.surname;
       }
       if (flag) {
         result = s + " " + n;
       } else {
        result = n + " " + s;
       }
      }
    }
   return result;
  }
private:
  // приватные поля
  struct NameSurname {
    string name;
    string surname;
  };
   
  map <int, NameSurname> full_name;
};