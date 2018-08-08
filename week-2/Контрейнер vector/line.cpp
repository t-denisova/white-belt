#include <iostream>
#include <string>
#include <vector>

using namespace std;

void WorryCount(const vector<bool>& p) {
  int count = 0;
  for (auto i : p) {
    if (i == 1) {
      count++;
    }
  }
  cout << count << endl;
}

int main() {
  int Q, n;
  string s;
  cin >> Q;
  vector<string>v(Q);
  vector<bool>p(0, false);
  
  for (string& s : v) {
   cin >> s;
   if (s == "WORRY") {
     cin >> n;
     p[n] = true;
   }
   else if (s == "QUIET") {
     cin >> n;
     p[n] = false;
   }
   else if (s == "COME") {
     cin >> n;
    p.resize(p.size() + n);
   }
   else if (s == "WORRY_COUNT") {
    WorryCount(p);
   }
  }
  return 0;
}