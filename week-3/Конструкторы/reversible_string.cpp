#include <iostream>
#include <string>

using namespace std;

class ReversibleString {
  public:
  ReversibleString () {}
  
  ReversibleString (const string& new_str) {
    str = new_str;
  }
  
  void Reverse() {
    for(int i = 0; i < str.length()/2; ++i) {
      char tmps = str[i];
      str[i] = str[str.length() - 1 - i];
      str[str.length() - 1 - i] = tmps;
    }
  }
  string ToString () const {
    return str;
  }
  
  private:
  string str;
};