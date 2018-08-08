#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void PrintVector(const vector<string>& work_in_this_months) {
  cout << "hi" << endl;
  int i = 1;
  for (auto w : work_in_this_months) {
    cout << i <<  ": " << w << endl;
    ++i;
  }
}
void PrintMap(const map<vector<string>, int>& m) {
  for (const auto& i : m) {
    for (const auto& i1: i.first) {
      cout << i1 << " ";
    }
    cout << i.second << endl;
  }
}

int main() {
  bool first_circle = true;
  int q;
  map<vector<string>, int> bus_stations;
  vector<string> stations;
  vector<string> v;
  int new_value;
  int last_value = -1;
  cin >> q;
  for (int i = 0; i < q; ++i) {

    int n;
    cin >> n;
    v.clear();

    for (int j = 0; j < n; ++j) {
      string s;
      cin >> s;
      v.push_back(s);
    }
      if (bus_stations.count(v) == 0) {
         new_value = bus_stations.size() + 1;
         bus_stations[v] = new_value;
         cout << "New bus " << new_value << endl;
      } else {
        cout << "Already exists for " <<  bus_stations[v] << endl;
      }
  }
  return 0;
}
