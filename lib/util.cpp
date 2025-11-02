#include "util.h"

std::string tabs(std::string str)
{
    int i = str.length();
    if (i < 4) return "\t\t\t\t";
    if (i < 8) return "\t\t\t";
    if (i < 16) return "\t\t";
    if (i < 24) return "\t";

    return "\t";
}

std::string align_left(const std::string& str, size_t width) {
    std::ostringstream oss;
    oss << std::string(8, ' ');
    oss << std::left << std::setw(width) << std::setfill(' ') << str;
    return oss.str();
}



int menu()
{
  std::cout << "1. Autor" << std::endl
            << "2. Usuario" << std::endl
            << "3. Noticia" << std::endl
            << "4. Salir" << std::endl;
  int o;
  std::cin >> o; std::cin.ignore();
  return o;
}

int m_author()
{
  std::cout << "1. Crear" << std::endl
            << "2. Listar" << std::endl
            << "3. Listar Noticias Asociadas" << std::endl
            << "4. Atras" << std::endl;
  int o;
  std::cin >> o; std::cin.ignore();
  return o;
}

int m_user()
{
  std::cout << "1. Crear" << std::endl
            << "2. Listar" << std::endl
            << "3. Listar Comentarios Asociados" << std::endl
            << "4. Atras" <<  std::endl;
  int o;
  std::cin >> o; std::cin.ignore();
  return o;
}

int m_new()
{
  std::cout << "1. Crear" << std::endl
            << "2. Listar" << std::endl 
            << "3. Listar por anio" << std::endl
            << "4. Listar por ultimo mes" << std::endl
            << "5. Salir" << std::endl;
  int o;
  std::cin >> o; std::cin.ignore();
  return o;
}

int verify_int(const std::string& str, int min, int max) {
    std::string input;
    int value;

    while (true) {
        try {
            std::cout << str;
            std::getline(std::cin, input);
            value = std::stoi(input);

            if (value < min || value > max)
                throw std::out_of_range("Fuera de rango");

            return value;
        }
        catch (const std::invalid_argument&) {
            std::cout << "Error: Debe ingresar un número entero válido." << std::endl;
        }
        catch (const std::out_of_range&) {
            std::cout << "Error: El número debe estar entre " << min << " y " << max << "." << std::endl;
        }
    }
}

std::string verify_string(const std::string& str, int max_length) {
    std::string input;

    while (true) {
        try {
            std::cout << str;
            std::getline(std::cin, input);

            if (input.empty())
                throw std::invalid_argument("Vacío");

            bool flag = true;
            for (char c : input) {
                if (!std::isdigit(c)) {
                    flag = false;
                    break;
                }
            }

            if (input.length() > max_length)
                throw std::out_of_range("Fuera de rango");

            if (flag)
                throw std::invalid_argument("Solo números");

            return input;
        }
        catch (const std::invalid_argument&) {
            std::cout << "Error: Debe ingresar texto (no solo números)." << std::endl;
        }
        catch (const std::out_of_range&) {
            std::cout << "Error: El texto no debe exceder " << max_length << " caracteres." << std::endl;
        }
    }
}
