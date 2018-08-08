#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void PrintMap(const map<string, string>& countries) {
  if (countries.size() == 0) {
    cout << "There are no countries in the world" << endl;
  } else {
    for (const auto& c : countries) {
      cout << c.first << "/" << c.second <<  " ";
    }
  }
  cout << endl;
}  

map<string, string> ChangeCapital(map<string, string>& countries, const string& country_name, const string& capital_name) {
  if (countries.count(country_name) == 0) {
    countries[country_name] = capital_name;
    cout << "Introduce new country " << country_name << " with capital " << capital_name << endl;
  } else {
    for (const auto& c : countries) {
      if (c.first == country_name) {
        if (c.second == capital_name) {
          cout << "Country " << country_name << " hasn't changed its capital" << endl;
          break;
        }
        else {
          cout << "Country " << c.first << " has changed its capital from " << c.second;
          countries[country_name] = capital_name;
          cout << " to " << c.second << endl;
          break;
        }
      }
    }
  }
  return countries;
}

map<string, string> RenameCountry(map<string, string>& countries, const string& country_name, const string& new_country_name) {
  if (new_country_name == country_name || countries.count(country_name) == 0 || countries.count(new_country_name) != 0) {
    cout << "Incorrect rename, skip"<< endl;
  } else {
    for (const auto& c :countries) {
      if (c.first  == country_name) {
         cout << "Country " << c.first << " with capital "<< c.second << " has been renamed to ";
      }
    }
    countries[new_country_name] = countries[country_name];
    countries.erase(country_name);
    cout << new_country_name << endl;
  }
  return countries;
}
void PrintAboutCountry (const map<string, string>& countries, const string& country_name) {
  if (countries.count(country_name) == 0) {
    cout << "Country " << country_name << " doesn't exist" << endl;
    
  } else {
    for (const auto& c : countries) {
      if (c.first  == country_name) {
        cout << "Country "<< c.first << " has capital " << c.second << endl;
      }
    }
  }
}
int main() {
  int q, n;
  string command, country_name, capital_name, new_country_name;
  
  map<string, string> countries;
  
  cin >> q;

  for (int i = 0; i < q; ++i) {
   cin >> command;
   if (command == "CHANGE_CAPITAL") {
    cin >> country_name >> capital_name;
    countries = ChangeCapital(countries, country_name, capital_name);
   }
    if (command == "RENAME") {
    cin >> country_name >> new_country_name;
    countries = RenameCountry(countries, country_name, new_country_name);
   }
   if (command == "ABOUT") {
    cin >> country_name;
    PrintAboutCountry(countries, country_name);
   }
   if (command == "DUMP") {
    PrintMap(countries);
   }
  }
  return 0;
}
