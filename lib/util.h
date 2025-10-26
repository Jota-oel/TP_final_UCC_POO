#ifndef UTIL_H
#define UTIL_H

#include "classes.h"
#include <cstdlib>

#define SIZE 60
#define FILE_AUTHOR "A.bin"
#define FILE_NEW "N.bin"
#define FILE_USER "U.bin"
#define FILE_COMMENT "C.bin"

extern Author arr_author[SIZE];
extern News arr_news[SIZE];
extern User arr_Users[SIZE];
extern Comment arr_Comment[SIZE];

void init();
int menu();
int m_author();
int m_user();
int m_new();
void controller();
void c_author();
void c_user();
void c_new();

void create_user();
void create_author();
void create_new();
void create_comment();

void show_users();
void show_authors();
void show_news();
void show_new(int);
void show_comments(int);

void show_news_by_author();
void show_news_by_year();
void show_news_by_last_month();
void show_comments_by_new();
void show_comments_by_user();

#endif
