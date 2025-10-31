#ifndef READER_H
#define READER_H
#pragma once

#include <fstream>
#include <stdexcept>

template <typename T>
class Reader {
public:
    explicit Reader(const char* filename);
    ~Reader();

    int get_last_id();
    bool read_at(size_t index, T& out_data);
    size_t count();

private:
    std::ifstream file;
};

template <typename T>
Reader<T>::Reader(const char* filename) {
    file.open(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo para lectura");
    }
}

template <typename T>
Reader<T>::~Reader() {
    if (file.is_open()) file.close();
}

template <typename T>
int Reader<T>::get_last_id() {
    file.seekg(0, std::ios::end);
    std::streampos size = file.tellg();

    if (size == 0)
        return 0;

    file.seekg(-static_cast<std::streamoff>(sizeof(T)), std::ios::end);

    T last_record;
    file.read(reinterpret_cast<char*>(&last_record), sizeof(T));

    return last_record.id;
}

template <typename T>
bool Reader<T>::read_at(size_t index, T& out_data) {
    file.seekg(index * sizeof(T), std::ios::beg);
    if (!file.read(reinterpret_cast<char*>(&out_data), sizeof(T)))
        return false;
    return true;
}

template <typename T>
size_t Reader<T>::count() {
    file.seekg(0, std::ios::end);
    return static_cast<size_t>(file.tellg() / sizeof(T));
}

#endif
