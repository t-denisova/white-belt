class Incognizable {
  public:
    Incognizable () {};
    Incognizable (const int& a) {
       a_main = a;
    }
    Incognizable (const int& a, const int& b) {
       a_main = a;
       b_main = b;
    }
  private:
    int a_main;
    int b_main;
};