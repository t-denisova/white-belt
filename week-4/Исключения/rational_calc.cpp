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
    if(denominator == 0) {
      throw runtime_error("Invalid argument");
    }
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
  if(rhs.Numerator() == 0) {
    throw domain_error("Division by zero");
  }
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
    if(stream.peek() != '/') {
      throw runtime_error("Invalid argument");
    }
    stream.ignore(1);
    stream >> m;
    if ( m != 0) {
      r = Rational(n, m);
    } else {
      throw runtime_error("Invalid argument");
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

Rational MakeCount (const Rational& r1, const Rational& r2, const char& c) {
  if(c == '+') {
    return r1 + r2;
  } else if (c == '-') {
    return r1 - r2;
  } else if (c == '/') {
    return r1 / r2;
  } else {
    return r1 * r2;
  }
}

int main() {
  char c;
  Rational r1, r2;
  try {
    cin >> r1 >> c >> r2;
    cout << MakeCount(r1, r2, c);
  } catch (exception& ex) {
    cout << ex.what();
  }

  return 0;
}

