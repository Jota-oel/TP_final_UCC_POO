#include "util.h"

Author arr_author[SIZE];
News arr_news[SIZE];
User arr_Users[SIZE];
Comment arr_Comment[SIZE];

void init() {
}

// to create
void create_user() {}
void create_author() {}
void create_new() {}
void create_comment() {}

// to show
void show_users() {}
void show_authors() {}
void show_news() {}
void show_new(int) {}
void show_comments(int) {}

// queries
void show_news_by_author() {}
void show_news_by_year() {}
void show_news_by_last_month() {}
void show_comments_by_new() {}
void show_comments_by_user() {}

void c_author()
{
  bool flag=true;
  while (flag)
  {
    switch (m_author()) {
      case 1:
        create_author();
        break;

      case 2:
        show_authors();
        break;

      case 3:
        show_news_by_author();
        break;

      case 4:
        std::cout << "Volviendo. . .";
        flag=false;
        break;
        
      default:
        std::cout << "Opcion incorrecta, intente de nuevo. . ." << std::endl;
        break;
    }
  }
}

void c_user()
{
  bool flag=true;
  while (flag)
  {
    switch (m_user()) {
      case 1:
        create_user();
        break;

      case 2:
        show_users();
        break;

      case 3:
        show_comments_by_user();
        break;

      case 4:
        std::cout << "Saliendo. . .";
        flag=false;
        break;

      default:
        std::cout << "Opcion incorrecta, intente de nuevo. . ." << std::endl;
        break;
    }
  }
}

void c_new()
{
  bool flag=true;
  while (flag)
  {
    switch (m_new()) {
      case 1:
        create_new();
        break;

      case 2:
        show_news();
        break;

      case 3:
        show_news_by_year();
        break;

      case 4:
        show_news_by_last_month();
        break;

      case 5:
        std::cout << "Saliendo. . .";
        flag=false;
        break;
      default:
        std::cout << "Opcion incorrecta, intente de nuevo. . ." << std::endl;
        break;
    }
  }
}

void controller()
{
  std::cout << "Bienvenido al gestor de noticias. . .\nEnter para continuar";
  std::cin.get();
  std::cin.ignore();
  system("clear");

  bool flag=true;
  while (flag)
  {
    switch (menu()) {
      case 1:
        c_author();
        break;
      case 2:
        c_user();
        break;
      case 3:
        c_new();
        break;
      case 4:
        std::cout << "Saliendo. . .";
        flag=false;
        break;
      default:
        std::cout << "Opcion incorrecta, intente de nuevo. . ." << std::endl;
        break;
    }
  }
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
