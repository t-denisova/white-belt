#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool myf(int i, int j) {
  return (abs(i) < abs(j));
}

int main() {
 vector<int> v;
 int q, n;
 cin >> q;
 for (int i = 0; i < q; ++i) {
   cin >> n;
   v.push_back(n);
 }
 sort (begin(v), end(v), myf);
 for (auto i : v) {
   cout << i << " ";
 }
 return 0;
}