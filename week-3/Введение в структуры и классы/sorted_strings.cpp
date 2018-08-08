class SortedStrings {
public:
  void AddString(const string& s) {
    // добавить строку s в набор
    v.push_back(s);
  }
  vector<string> GetSortedStrings() {
    // получить набор из всех добавленных строк в отсортированном порядке
   sort(begin(v), end(v));
   return v;
  }
private:
  // приватные поля
  vector<string> v;
};
