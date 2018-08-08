#include <iostream>
using namespace std;

int FindDevider(int x, int y) {
  while (x > 0 && y > 0) {
    if (x > y) {
      x %= y;
    } else {
      y %= x;
    }
  }

  return  x + y;
}

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator) {
      int n, d = 0;
        // Реализуйте конструктор
      if (numerator == 0) {
        n = 0;
        d = 1;
      } else {
        int devider = FindDevider(numerator, denominator);
        n = numerator / devider;
        d = denominator / devider;
      }
      num = n;
      den = d;
    }

    int Numerator() const {
        // Реализуйте этот метод
        return num;
    }

    int Denominator() const {
        // Реализуйте этот метод
        return den;
    }

private:
    // Добавьте поля
    int num;
    int den;
};

int main() {
    // const Rational r(4, -8);
    // cout << r.Numerator() << '/' << r.Denominator() << endl;
    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK!"<< endl;
    return 0;
}
