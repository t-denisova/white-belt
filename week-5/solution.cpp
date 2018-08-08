// Реализуйте функции и методы классов и при необходимости добавьте свои
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

using namespace std;


void ThrowWrongDateFormatError(const string &date_str) {
	stringstream ss;
	ss << "Wrong date format: " << date_str;
	throw runtime_error(ss.str());
}
void EnsureNextSimbolIsDash(stringstream &stream, const string &date_str) {
  if (stream.peek() != '-') {
    ThrowWrongDateFormatError(date_str);
  }
  stream.ignore(1);
}

class Date {
public:
	Date(const int &new_year, const int &new_month, const int &new_day) {
		year = new_year;
		month = new_month;
		day = new_day;
	}

	void ParseDate(const string &date_str) {
		int y, m, d = 999999;
		stringstream stream(date_str);
		stream >> y;
		EnsureNextSimbolIsDash(stream, date_str);
		stream >> m;
		EnsureNextSimbolIsDash(stream, date_str);
		stream >> d;
		if (!stream.eof()) {
			ThrowWrongDateFormatError(date_str);
		}
		if (y > 9999) {
			ThrowWrongDateFormatError(date_str);
		} else {
			year = y;
		}
		if (m > 99) {
			ThrowWrongDateFormatError(date_str);
		}
		if (d > 99) {
			ThrowWrongDateFormatError(date_str);
		}
		if (m <= 0 || m > 12) {
			stringstream ss;
			ss << "Month value is invalid: " << to_string(m);
			throw runtime_error(ss.str());
		} else {
			month = m;
		}
		if (d <= 0 || d > 31) {
			stringstream ss;
			ss << "Day value is invalid: " << to_string(d);
			throw runtime_error(ss.str());
		} else {
			day = d;
		}
	}

	Date(const string &date_str) {
		ParseDate(date_str);
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

bool operator<(const Date &lhs, const Date &rhs) {
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
	void AddEvent(const Date &date, const string &event) {
		database[date].insert(event);
	}
	bool DeleteEvent(const Date &date, const string &event) {
		if (database.count(date)) {
			if (database[date].count(event)) {
				database[date].erase(event);
				return true;
			}
		}
		return false;
	}

	int DeleteDate(const Date &date) {
		int num_of_events = 0;
		if (database.count(date)) {
			num_of_events = database[date].size();
		}
		database.erase(date);
		return num_of_events;
	}

	set<string> Find(const Date &date) const {
		set<string> events;
		if (database.count(date)) {
			for (const auto &e : database.at(date)) {
				events.insert(e);
			}
		}
		return events;
	}

	void Print() const {
		for (const auto &i : database) {
			for (const auto &j : i.second) {
				if (i.first.GetYear() != -1) {
					cout << setfill('0');
					cout << setw(4) << i.first.GetYear() << "-" << setw(2)
						 << i.first.GetMonth() << "-" << setw(2)
						 << i.first.GetDay();
					cout << " " << j;
					cout << endl;
				}
			}
		}
	}

private:
	map<Date, set<string>> database;
};

int main() {
	Database db;

	string command;

	while (getline(cin, command)) {
		stringstream ss(command);
		string cmd;
		try {
			ss >> cmd;

			// Считайте команды с потока ввода и обработайте каждую

			if (cmd == "Add") {
				string date_str, event = "";
				ss >> date_str >> event;
				try {
					db.AddEvent({date_str}, event);
				} catch (exception &e) {
					cout << e.what() << endl;
          return 0;
				}
			} else if (cmd == "Del") {
				string date_str, event;
				ss >> date_str >> event;
				if (event != "") {
					if (db.DeleteEvent({date_str}, event)) {
						cout << "Deleted successfully" << endl;
					} else {
						cout << "Event not found" << endl;
					}
				} else {
          int e = db.DeleteDate({date_str});
					cout << "Deleted " << e << " events"
						 << endl;
				}
			} else if (cmd == "Find") {
				string date_str;
				ss >> date_str;
				set<string> events = db.Find({date_str});
				for (const auto &e : events) {
					cout << e << endl;
				}
			} else if (cmd == "Print") {
				db.Print();
			} else {
				if (cmd != "") {
					stringstream ss;
					ss << "Unknown command: " << cmd;
			  	throw runtime_error(ss.str());
				}
			}
		} catch (const exception &e) {
			cout << e.what() << endl;
      return 0;
		}
	}
	return 0;
}