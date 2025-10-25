#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <fstream>
#include <cstring>

template <typename T>
class Writer {
public:
    Writer(const char* filename) {
        file.open(filename, std::ios::binary | std::ios::app);
        if (!file.is_open()) throw std::runtime_error("No se pudo abrir el archivo");
    }

    ~Writer() { file.close(); }

    void write(const T& data) {
        file.write(reinterpret_cast<const char*>(&data), sizeof(T));
    }

private:
    std::ofstream file;
};

struct A {
    int id, media;
    char dni[10];
    char name[50];
};

struct U {
    int id, age;
    char dni[10];
    char name[50];
};

struct C {
    int id, counter, user;
    char str[50];
};

struct N {
    int id, day, month, year, author;
    char title[50];
    char detail[200];
};

class Author {
public:
    Author() = default;
    Author(int id, const std::string& dni, const std::string& name, int media)
        : id(id), dni(dni), name(name), media(media) {}

    A to_struct();
    void from_struct(const A&);

private:
    int id, media;
    std::string dni, name;
};

class User {
public:
    User() = default;
    User(int id, const std::string& dni, const std::string& name, int age)
        : id(id), dni(dni), name(name), age(age) {}

    U to_struct();
    void from_struct(const U&);

private:
    int id, age;
    std::string dni, name;
};

class Comment {
public:
    Comment() = default;
    Comment(int id, int counter, int user, const std::string& str)
        : id(id), counter(counter), user(user), str(str) {}

    C to_struct();
    void from_struct(const C&);
private:
    int id, counter, user;
    std::string str;
};

class News {
public:
    News() = default;
    News(int id, int day, int month, int year, int author,
         const std::string& title, const std::string& detail)
        : id(id), day(day), month(month), year(year),
          author(author), title(title), detail(detail) {}

    N to_struct();
    void from_struct(const N&);
private:
    int id, day, month, year, author;
    std::string title, detail;
};

#endif

