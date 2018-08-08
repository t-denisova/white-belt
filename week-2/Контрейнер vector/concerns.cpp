#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
  
int main() {
  int q, n;
  int index = 0;
  int current = 0;
  int cnt=0;
  string todo, command;
  cin >> q;
  vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  vector<string> v1 (days_in_month[current], "");
  vector<string> v1_tmp;
  vector<string> v2;
  for (int i = 0; i < q; ++i) {
   cin >> command;
   if (command == "ADD") {
      cin >> n >> todo;
      v1[n-1] += todo + " ";
      v2.push_back(todo);
   }
   else if (command == "NEXT") {
     v1_tmp = v1;
     if (current < 11) {
       current++;
     } else {
       current = 0;
     }
     string work;
     int left = days_in_month[current-1] - days_in_month[current];
     v1.resize(days_in_month[current]);
      if (current > 0) {
       if (days_in_month[current] < days_in_month[current-1]) {
         v1.resize(days_in_month[current]);
         for (int i = v1_tmp.size()-left-1; i < v1_tmp.size(); ++i) {
           if (v1_tmp[i]!= "") {
             work += v1_tmp[i];
             v1[(days_in_month[current]) - 1] = work;
           }
         }
       }
     }
   }
   else if (command == "DUMP") {
    cin >> n;
    int pos;
    for (const auto& st: v2) {
      pos = v1[n-1].find(st);
      if (pos != std::string::npos) {
        cnt++;
      }
    }
    cout << cnt << " " << v1[n-1] << endl;
    cnt = 0;
   }
  }
  return 0;
}