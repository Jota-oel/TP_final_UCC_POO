#include <classes.h>
#include <cstdlib>

int menu();
int m_author();
int m_user();
int m_new();
void controller();
void c_author();
void c_user();
void c_new();

int main()
{
  controller();
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
        {

        } break;
      case 2:
        {

        } break;
      case 3:
        {

        } break;
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
            << "4. Listar por ultimo mes" << std::endl;
  int o;
  std::cin >> o; std::cin.ignore();
  return o;
}
