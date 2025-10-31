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
            << "4. Atras";
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
