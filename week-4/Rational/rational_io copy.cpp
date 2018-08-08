#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;



int FindDevider (int x, int y) {
    while (x > 0 && y > 0) {
        if (x > y) {
            x %= y;
        } else {
            y %= x;
        }
    }
    return x + y;
}

int FindNok(const int& a, const int& b) {
  return a * b / FindDevider(a, b);
}
class Rational {
  public:
  Rational() {
    num = 0;
    den = 1;
  }


  Rational(int numerator, int denominator) {
    if (numerator == 0) {
      num = 0;
      den = 1;
    } else {
      int devider = FindDevider(abs(numerator), abs(denominator));
      num = numerator / devider;
      den = denominator / devider;
      if(den < 0){
        num *= -1;
        den *= -1;
      }
    }
  }

  int Numerator() const {
    return num;
  }

  

  int Denominator() const {
    return den;
  }

  

  private:
  int num;
  int den;
};

// Rational CreateR(const stringstream& ss, Rational& r) {
//   string s_rhs, s_lhs = "";
//   getline(ss, s_rhs, '/');
//   getline(ss, s_lhs);
//   r = Rational(stoi(s_rhs), stoi(s_lhs));
//   return r;
// }


Rational operator+(const Rational& lhs, const Rational rhs) {
  if (lhs.Denominator() == rhs.Denominator()) {
    return Rational(lhs.Numerator() + rhs.Numerator(), lhs.Denominator());
  } else {
    int nok = FindNok(lhs.Denominator(), rhs.Denominator());
    int n_l = nok / lhs.Denominator();
    int d_l = nok / rhs.Denominator();
    return Rational(lhs.Numerator() * n_l + rhs.Numerator() * d_l, nok);
  }
}



Rational operator-(const Rational& lhs, const Rational& rhs) {
  if (lhs.Denominator() == rhs.Denominator()) {
    return Rational(lhs.Numerator() - rhs.Numerator(), lhs.Denominator());
  } else {
    int nok = FindNok(lhs.Denominator(), rhs.Denominator());
    int n_l = nok / lhs.Denominator();
    int d_l = nok / rhs.Denominator();
    return Rational(lhs.Numerator() * n_l - rhs.Numerator() * d_l, nok);
  }
}



bool operator==(const Rational& lhs, const Rational& rhs) {
  if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()) {
    return true;
  } else {
    return false;
  }
}



Rational operator*(const Rational& lhs, const Rational& rhs) {
  return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}



Rational operator/(const Rational& lhs, const Rational& rhs) {
  return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}



ostream& operator<<(ostream& stream, const Rational& r) {
  stream << r.Numerator() << '/' << r.Denominator();
  return stream;
}

istream& operator>>(istream& stream, Rational& r) {
  if(stream) {
    int n, m = 0;
    stream >> n;
    stream.ignore(1);
    stream >> m;
    if ( m!= 0) {
      r = Rational(n, m);
    }
  }
  return stream;
}

bool operator<(const Rational& lhs, const Rational& rhs) {
  int nok = FindNok(lhs.Denominator(), rhs.Denominator());
  int n_l = nok / lhs.Denominator();
  int d_l = nok / rhs.Denominator();
  if (lhs.Numerator() * n_l == rhs.Numerator() * d_l) {
    return lhs.Numerator() * n_l < rhs.Numerator() * d_l;
  }
  return lhs.Numerator() * n_l < rhs.Numerator() * d_l;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}

