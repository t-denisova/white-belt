#include <iostream>
#include <sstream>
#include <string>

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
      //cout << devider << endl;
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
    int nok = lhs.Denominator() * rhs.Denominator() / FindDevider(lhs.Denominator(), rhs.Denominator());
    int n_l = nok / lhs.Denominator();
    int d_l = nok / rhs.Denominator();
    return Rational(lhs.Numerator() * n_l + rhs.Numerator() * d_l, nok);
  }
}



Rational operator-(const Rational& lhs, const Rational& rhs) {
  if (lhs.Denominator() == rhs.Denominator()) {
    return Rational(lhs.Numerator() - rhs.Numerator(), lhs.Denominator());
  } else {
    int nok = lhs.Denominator() * rhs.Denominator() / FindDevider(lhs.Denominator(), rhs.Denominator());
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


int main() {
  {
    ostringstream output;
    output << Rational(-6, 8);
    if (output.str() != "-3/4") {
      cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
      return 1;
    }
  }


  {

    istringstream input("5/7");
    Rational r;
    input >> r;
    bool equal = r == Rational(5, 7);
    if (!equal) {
      cout << "5/7 is incorrectly read as " << r << endl;
      return 2;
    }
  }

  

  {
    istringstream input("5/7 10/8");
    Rational r1, r2;
    input >> r1 >> r2;
    bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
    if (!correct) {
      cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
      return 3;
  }


    input >> r1;
    input >> r2;
    correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
    if (!correct) {
      cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
      return 4;
    }
  }

  


  cout << "OK" << endl;
  return 0;
}

