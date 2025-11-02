#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

std::string tabs(std::string);
std::string align_left(const std::string& str, size_t width = 24);
int menu();
int m_author();
int m_user();
int m_new();

int verify_int(const std::string&, int min=0, int max=1000000);
std::string verify_string(const std::string&, int max_length=100);

#endif
