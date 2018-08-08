#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string myf(string& s) {
  for(int i = 0; i < s.size(); ++i) {
    s[i] = tolower(s[i]);
  }
  return s;
}

int main() {
  int n;
  cin >> n;
  vector<string> v(n);
  for(string& s : v) {
    cin >> s;
   
  }
  sort(begin(v), end(v),
    [](string l, string r) {
      myf(l);
      myf(r);
      return l < r;
    }
  );
  for (string i : v) {
    cout << i << " ";
  }
 return 0;
}