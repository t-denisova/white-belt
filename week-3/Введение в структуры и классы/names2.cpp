#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
void PrintString(string s) {
  cout << "stroka: " << s;
}
void PrintVector(vector<string> v) {
  
   cout << "vector: ";
 for(const auto i : v) {
   cout << i << " ";
 } 
 cout << endl;
}

bool Contains(vector<string>& v, string s)  {
  if(!v.empty()) {
   if (v[v.size()-1] == s) {
      return false;
    } else {
      return true;
    }
  }
  return true;
}

string CreateString(vector<string>& v) {
  
  string tmp = "";
  string s = "";
  
  if (!v.empty()) {
    for (int i = v.size() - 1; i >= 1; --i) {
        if (v[i] == v[v.size()-1] ) {
          tmp += v[i];
        } else {
          tmp +=   ", " + v[i];
      }
    }
  }
  
  if (tmp.length() > 0) {
    s = " (" + tmp + ")";
  }
  
  return s;
}

vector<string> FindAllNamesByYear(const map<int, string>& names, int year, const string& n) {
 vector<string> v = {""};  // изначально имя неизвестно
 // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
  for (const auto& item : names) {
    // если очередной год не больше данного, обновляем имя
    
    if (item.first <= year) {
     if (Contains(v, item.second)) {
        v.push_back(item.second);
     }
    } else {
      // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
      break;
    }
  }
  
  if (v[v.size()-1] == n) {
    v.resize(v.size()-1);
  }
  return v;
}

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
  string name;  // изначально имя неизвестно
  
  // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
  for (const auto& item : names) {
    // если очередной год не больше данного, обновляем имя
    
    if (item.first <= year) {
      name = item.second;
    } else {
      // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
      break;
    }
  }
  
  return name;
}

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    last_names[year] = last_name;
  }
  string GetFullName(int year) {
    // получаем имя и фамилию по состоянию на год year
    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);
    
    // если и имя, и фамилия неизвестны
    if (first_name.empty() && last_name.empty()) {
      return "Incognito";
    
    // если неизвестно только имя
    } else if (first_name.empty()) {
      return last_name + " with unknown first name";
      
    // если неизвестна только фамилия
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";
      
    // если известны и имя, и фамилия
    } else {
      return first_name + " " + last_name;
    }
  }
  
string GetFullNameWithHistory(int year) {
    // получить все имена и фамилии по состоянию на конец года year
   
    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);
    vector<string> all_first_names = FindAllNamesByYear(first_names, year, first_name);
    vector<string> all_last_names = FindAllNamesByYear(last_names, year, last_name);

    
    // PrintString(v1);
    // если и имя, и фамилия неизвестны
    if (first_name.empty() && last_name.empty()) {
      return "Incognito";
    
    // если неизвестно только имя
    } else if (first_name.empty()) {
      return last_name + CreateString(all_last_names) + " with unknown first name";
      
    // если неизвестна только фамилия
    } else if (last_name.empty()) {
      return first_name + CreateString(all_first_names) + " with unknown last name";
      
    // если известны и имя, и фамилия
    } else {
      return first_name + CreateString(all_first_names) + " " + last_name + CreateString(all_last_names);
    }
  }
  
private:
  map<int, string> first_names;
  map<int, string> last_names;

};