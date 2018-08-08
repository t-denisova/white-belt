#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PrintVector(const vector<int>& v, const double& m) {
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] > m) {
     cout << i << " ";
    }
  }
}

void FindMean (const vector<int>& v, const int& n) {
  double m = 0;
  int count = 0;
  for (auto i : v) {
    m += i;
  }
  m /= n;

  for (auto i : v) {
    if (i > m) {
     ++count;
    }
  }
  
  cout << count << endl;
  PrintVector(v, m);
}

int main() {
  int n;
  cin >> n;
  vector<int>v(n);
  for(int& i : v) {
    cin >> i;
  }
  FindMean(v, n);
  return 0;
}