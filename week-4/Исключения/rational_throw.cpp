// Реализуйте функции и методы классов и при необходимости добавьте свои
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <iomanip>
#include <set>

using namespace std;

void EnsureNextSimbolAndSkip(stringstream& stream, const string& date_str) {
if (stream.peek() != '-') {
  stringstream ss;
  ss << "Wrong date format: " << date_str;
  throw runtime_error(ss.str());
  }
stream.ignore(1);
}
int AddMonth(stringstream& stream) {
  int m;
  stream >> m;
  if (m <= 0 || m > 12) {
    stringstream ss;
    ss << "Month value is invalid: " <<  to_string(m);
    throw runtime_error(ss.str());
  } else {
    return m;
  }
}
int AddDay(stringstream& stream) {
  int d;
  stream >> d;
  if (d <= 0 || d > 31) {
    stringstream ss;
    ss << "Day value is invalid: " <<  to_string(d);
    throw runtime_error(ss.str());
  } else {
    return d;
  }
}
class Date {
public:
  Date () {
    year = 0;
    month = 0;
    day = 0;
  }
  Date (const int& new_year, const int& new_month, const int& new_day) {
    year = new_year;
    month = new_month;
    day = new_day;
  }

  Date (const string& date_str) {
    stringstream stream(date_str);
    stream >> year;
    EnsureNextSimbolAndSkip(stream, date_str);
    try {
      month = AddMonth(stream);
    // stream >> month;
    } catch (const invalid_argument& e) {  
      cout << e.what();
    }
    EnsureNextSimbolAndSkip(stream, date_str);
    try {
      day = AddDay(stream);
    // stream >> day;
    } catch (const invalid_argument& e) {  
      cout << e.what();
    }
  }

  int GetYear() const {
    return year;
  }
  int GetMonth() const {
    return month;
  }
  int GetDay() const {
    return day;
  }
  void Print() const {
    cout << year << "-" << month << "-" << day;
  }

private:
  int year;
  int month;
  int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
  if (lhs.GetYear() == rhs.GetYear()) {
   if (lhs.GetMonth() == rhs.GetMonth()) {
     return lhs.GetDay() < rhs.GetDay();
   }
   return lhs.GetMonth() < rhs.GetMonth();
  }
  return lhs.GetYear() < rhs.GetYear();
}

class Database {
public:
  void AddEvent(const Date& date, const string& event) {
    database[date].insert(event);
  }
  bool DeleteEvent(const Date& date, const string& event) {
    if(database.count(date)) {
      if(database[date].count(event)) {
        database[date].erase(event);
        return true;
      }
    }
  }

  int DeleteDate(const Date& date) {
    int num_of_events = 0;
    if(database.count(date)) {
      num_of_events = database[date].size();
    }
    database.erase(date);
    return num_of_events;
  }

  set<string> Find(const Date& date) const {
    set<string> events;
      if(database.count(date)) {
        for (const auto& e : database.at(date)) {
          events.insert(e);
        }
      }
    return events;
  }

  void Print() const {
    for(const auto& i : database) {
      cout << setfill('0');
      cout << setw(4) << i.first.GetYear() << "-"
           << setw(2) << i.first.GetMonth() << "-"
           << setw(2) << i.first.GetDay() << " ";
      for(const auto& j : i.second) {
        cout << j << " ";
      }
      cout << endl;
    }
  }

private: 
  map<Date, set<string>> database;
};

int main() {
  Database db;

  string command;
  
  Date date;

  while (getline(cin, command)) {
    stringstream ss(command);
    string cmd;
     try {
       if (ss.peek() != '\n') {
          ss >> cmd;
        }
     } catch (const invalid_argument& e) {
     }
    // Считайте команды с потока ввода и обработайте каждую
   
    if (cmd == "Add") {
      string date_str, event;
      ss >> date_str >> event;
      // try {
        db.AddEvent({date_str}, event);
      // } catch(const invalid_format& e) {
      //   cout << e.what();
      // }
    } else if(cmd == "Del"){
      string date_str, event;
      ss >> date_str >> event;
      if (event != "") {
        if (db.DeleteEvent({date_str}, event)) {
          cout << "Deleted successfully" << endl;
        } else {
          cout << "Event not found" << endl;
        }
      } else {
        cout << "Deleted " <<  db.DeleteDate({date_str}) << " events" << endl;
      }
    } else if (cmd == "Find") {
        string date_str;
        ss >> date_str; 
        set<string> events = db.Find({date_str});
        for(const auto& e : events) {
          cout << e << endl;
        }
    } else if (cmd == "Print") {
        db.Print();
    } else if (cmd == "") {
        // db.Print();
    } else {
      throw invalid_argument("Unknown command: " + cmd);
    }
  }
  return 0;
}
