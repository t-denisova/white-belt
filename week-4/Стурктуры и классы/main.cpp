struct Specialization {
  string value;
  explicit Specialization (string new_value) {
    value = new_value;
  }
};

struct Course {
  string value;
  explicit Course(string new_value) {
    value = new_value;
  }
};

struct Week {
  string value;
  explicit Week (string new_value) {
    value = new_value;
  }
};

struct LectureTitle {
  string specialization;
  string course;
  string week;
  
  LectureTitle (const Specialization& new_specialization, const Course& new_course, const Week& new_week) {
    specialization = new_specialization.value;
    course = new_course.value;
    week = new_week.value;
  }
};