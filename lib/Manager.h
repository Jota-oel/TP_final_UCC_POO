#ifndef MANAGER_H
#define MANAGER_H
#pragma once
#include "classes.h"
#include "Reader.h"
#include "Writer.h"
#include "util.h"
#include <vector>

#define SIZE 100

class Manager {
public:
    Manager();
    std::vector<Author> authors;
    std::vector<User> users;
    std::vector<News> news;
    std::vector<Comment> comments;
    Writer<A> writer_author;
    Writer<U> writer_user;
    Writer<N> writer_news;
    Writer<C> writer_comment;
    Reader<A> reader_author;
    Reader<U> reader_user;
    Reader<N> reader_news;
    Reader<C> reader_comment;
    void read_all();
};

extern Manager manager;

extern std::string medias[4];

extern int count_users;
extern int count_authors;
extern int count_news;
extern int count_comments;

bool dni_exists(const std::string& dni);
bool dni_author_exists(const std::string& dni);
bool id_news_exists(int id);
bool id_comment_exists(int id);
bool id_user_exists(int id);
bool id_author_exists(int id);

void create_user();
void create_author();
void create_new();
void create_comment(int);

void show_users();
void show_authors();
void show_news();
void show_new(int);
void show_new_data(int);
void show_comments(int);

void show_news_by_author();
void show_news_by_year();
void show_news_by_last_month();
void show_comments_by_new();
void show_comments_by_user();

void controller();
void c_author();
void c_user();
void c_new();

#endif

