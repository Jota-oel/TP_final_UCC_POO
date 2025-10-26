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
    Author();
    Author(int id, int media, const std::string& dni, const std::string& name);
        

    A to_struct() const;
    void from_struct(const A&);

    int getId() const;
    int getMedia() const;
    std::string getDNI() const;
    std::string getName() const;

    
    void setId(int);
    void setMedia(int);
    void setDNI(const std::string&);
    void setName(const std::string&);



private:
    int id, media;
    std::string dni, name;
};

class User {
public:
    User();
    User(int id, int age, const std::string& dni, const std::string& name);

    int getId() const;
    int getAge() const;
    std::string getDNI() const;
    std::string getName() const;

    void setId(int);
    void setAge(int);
    void setDNI(const std::string&);
    void setName(const std::string&);

    U to_struct() const;
    void from_struct(const U&);

private:
    int id, age;
    std::string dni, name;
};

class Comment {
public:
    Comment();
    Comment(int id, int counter, int user, const std::string& str);

    int getId() const;
    int getCounter() const;
    int getUser() const;
    std::string getStr() const;

    void setId(int);
    void setCounter(int);
    void setUser(int);
    void setStr(const std::string&);

    C to_struct() const;
    void from_struct(const C&);
private:
    int id, counter, user;
    std::string str;
};

class News {
public:
    News();
    News(int id, int day, int month, int year, int author,
         const std::string& title, const std::string& detail);

    int getId() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    int getAuthor() const;
    std::string getTitle() const;
    std::string getDetail() const;

    void setId(int);
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    void setAuthor(int);
    void setTitle(const std::string&);
    void setDetail(const std::string&);

    N to_struct() const;
    void from_struct(const N&);
private:
    int id, day, month, year, author;
    std::string title, detail;
};

#endif

