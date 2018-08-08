#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;


void PrintMap(const map<set<string>,int>& m) {
  for (const auto& i: m) {
    for (const auto& i2: i.first) {
      cout << i2 << " ";
  }
  cout << i.second << endl;
  }
}
void PrintSet(const set<string> s) {
  for (const auto& i: s) {
    cout << i << " ";
  }
  cout << endl;
}


int main() {
  map<set<string>, int> buses;
  set<string> stops;
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    stops.clear();
    int n;
    cin >> n;
    for (int j = 1; j <= n; ++j) {
      string s;
      cin >> s;
      stops.insert(s);
    }
   if (buses.count(stops) == 0) {
    int new_value = buses.size() + 1;
    buses[stops] = new_value;
    cout << "New bus " << new_value << endl;
   } else {
     cout << "Already exists for " << buses[stops] << endl;
   }
  }
  return 0;
}