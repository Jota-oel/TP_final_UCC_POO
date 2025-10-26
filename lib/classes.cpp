#include "classes.h"

A Author::to_struct() const {
  A s{};
  s.id = id;
  s.media = media;
  std::strncpy(s.dni, dni.c_str(), sizeof(s.dni) - 1);
  std::strncpy(s.name, name.c_str(), sizeof(s.name) - 1);
  return s;
}

void Author::from_struct(const A& s) {
  id = s.id;
  media = s.media;
  dni = s.dni;
  name = s.name;
}

U User::to_struct() const {
  U s{};
  s.id = id;
  s.age = age;
  std::strncpy(s.dni, dni.c_str(), sizeof(s.dni) - 1);
  std::strncpy(s.name, name.c_str(), sizeof(s.name) - 1);
  return s;
}

void User::from_struct(const U& s) {
  id = s.id;
  age = s.age;
  dni = s.dni;
  name = s.name;
}

C Comment::to_struct() const {
  C s{};
  s.id = id;
  s.counter = counter;
  s.user = user;
  std::strncpy(s.str, str.c_str(), sizeof(s.str) - 1);
  return s;
}

void Comment::from_struct(const C& s) {
  id = s.id;
  counter = s.counter;
  user = s.user;
  str = s.str;
}

N News::to_struct() const {
  N s{};
  s.id = id;
  s.day = day;
  s.month = month;
  s.year = year;
  s.author = author;
  std::strncpy(s.title, title.c_str(), sizeof(s.title) - 1);
  std::strncpy(s.detail, detail.c_str(), sizeof(s.detail) - 1);
  return s;
}

void News::from_struct(const N& s) {
  id = s.id;
  day = s.day;
  month = s.month;
  year = s.year;
  author = s.author;
  title = s.title;
  detail = s.detail;
}


