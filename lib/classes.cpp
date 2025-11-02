#include "classes.h"

Author::Author() = default;

Author::Author(int id, int media, const std::string& dni, const std::string& name)
    : id(id), media(media), dni(dni), name(name) 
    {}

int Author::getId() const 
{
    return id;
}

int Author::getMedia() const 
{
    return media;
}

std::string Author::getDNI() const 
{
    return dni;
}

std::string Author::getName() const 
{
    return name;
}

void Author::setId(int newId) 
{
    id = newId;
}

void Author::setMedia(int newMedia) 
{
    media = newMedia;
}

void Author::setDNI(const std::string& newDNI) 
{
    dni = newDNI;
}

void Author::setName(const std::string& newName) 
{
    name = newName;
}

A Author::to_struct() const 
{
  A s{};
  s.id = id;
  s.media = media;
  std::strncpy(s.dni, dni.c_str(), sizeof(s.dni) - 1);
  std::strncpy(s.name, name.c_str(), sizeof(s.name) - 1);
  return s;
}

void Author::from_struct(const A& s) 
{
  id = s.id;
  media = s.media;
  dni = s.dni;
  name = s.name;
}

User::User() = default;
User::User(int id, int age, const std::string& dni, const std::string& name)
    : id(id), age(age), dni(dni), name(name) 
    {}

int User::getId() const 
{
    return id;
}

int User::getAge() const 
{
    return age;
}

std::string User::getDNI() const 
{
    return dni;
}

std::string User::getName() const 
{
    return name;
}

void User::setId(int newId) 
{
    id = newId;
}

void User::setAge(int newAge) 
{
    age = newAge;
}

void User::setDNI(const std::string& newDNI) 
{
    dni = newDNI;
}

void User::setName(const std::string& newName) 
{
    name = newName;
}

U User::to_struct() const 
{
  U s{};
  s.id = id;
  s.age = age;
  std::strncpy(s.dni, dni.c_str(), sizeof(s.dni) - 1);
  std::strncpy(s.name, name.c_str(), sizeof(s.name) - 1);
  return s;
}

void User::from_struct(const U& s) 
{
  id = s.id;
  age = s.age;
  dni = s.dni;
  name = s.name;
}

Comment::Comment() = default;
Comment::Comment(int id, int user, int news, const std::string& str)
    : id(id), user(user), news(news), str(str) 
    {}


int Comment::getId() const 
{
    return id;
}

int Comment::getNew() const 
{
    return news;
}

int Comment::getUser() const 
{
    return user;
}

std::string Comment::getStr() const 
{
    return str;
}

void Comment::setNew(int _news) 
{
    news = _news;
}

void Comment::setId(int newId) 
{
    id = newId;
}

void Comment::setUser(int newUser) 
{
    user = newUser;
}

void Comment::setStr(const std::string& newStr) 
{
    str = newStr;
}


C Comment::to_struct() const 
{
  C s{};
  s.id = id;
  s.user = user;
  std::strncpy(s.str, str.c_str(), sizeof(s.str) - 1);
  return s;
}

void Comment::from_struct(const C& s) 
{
  id = s.id;
  user = s.user;
  str = s.str;
}


News::News() = default;
News::News(int id, int day, int month, int year, int author,
           const std::string& title, const std::string& detail)
    : id(id), day(day), month(month), year(year),
      author(author), title(title), detail(detail) 
      {}

int News::getId() const 
{
    return id;
}

int News::getDay() const 
{
    return day;
}

int News::getMonth() const 
{
    return month;
}

int News::getYear() const 
{
    return year;
}

int News::getAuthor() const 
{
    return author;
}

std::string News::getTitle() const 
{
    return title;
}

std::string News::getDetail() const 
{
    return detail;
}


void News::setId(int newId) 
{
    id = newId;
}

void News::setDay(int newDay) 
{
    day = newDay;
}

void News::setMonth(int newMonth) 
{
    month = newMonth;
}

void News::setYear(int newYear) 
{
    year = newYear;
}

void News::setAuthor(int newAuthor) 
{
    author = newAuthor;
}

void News::setTitle(const std::string& newTitle) 
{
    title = newTitle;
}

void News::setDetail(const std::string& newDetail) 
{
    detail = newDetail;
}


N News::to_struct() const 
{
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

void News::from_struct(const N& s) 
{
  id = s.id;
  day = s.day;
  month = s.month;
  year = s.year;
  author = s.author;
  title = s.title;
  detail = s.detail;
}


