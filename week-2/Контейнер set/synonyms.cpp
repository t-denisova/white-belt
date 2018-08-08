#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include<vector>

using namespace std;


void PrintMap(const map<string, set<string>>& m) {
  for (const auto& i: m) {
    cout << i.first << " ";
    for (const auto& i2: i.second) {
      cout << i2 << " ";
  }
  cout << endl;
  }
}
void PrintSet(const set<string> s) {
  for (const auto& i: s) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  map<string, set<string>> m;
  set<string> st;
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
  string s;
  cin >> s;
  if (s == "ADD") {
    string w1, w2;
    cin >> w1 >> w2;
    m[w1].insert(w2);
    m[w2].insert(w1);
  } else if (s == "COUNT") {
    string w;
    cin >> w;
    cout << m[w].size() << endl;
  } else if (s == "CHECK") {
    string w1, w2;
    cin >> w1 >> w2;
    if ((m[w1].count(w2) > 0) && (m[w2].count(w1)>0)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
   }
  }
  return 0;
}
