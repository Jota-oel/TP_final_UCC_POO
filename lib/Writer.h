#ifndef WRITER_H
#define WRITER_H
#pragma once

#include <fstream>
#include <stdexcept>

template <typename T>
class Writer {
public:
    explicit Writer(const char* filename);
    ~Writer();

    void write(const T& data);

private:
    std::ofstream file;
};

template <typename T>
Writer<T>::Writer(const char* filename) {
    file.open(filename, std::ios::binary | std::ios::app);
    if (!file.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo para escritura");
    }
}

template <typename T>
Writer<T>::~Writer() {
    if (file.is_open()) file.close();
}

template <typename T>
void Writer<T>::write(const T& data) {
    file.write(reinterpret_cast<const char*>(&data), sizeof(T));
}

#endif
