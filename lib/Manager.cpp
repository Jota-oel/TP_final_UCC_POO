#include "Manager.h"
#include <iostream>
#define FILE_AUTHOR "dat/authors.dat"
#define FILE_USER   "dat/users.dat"
#define FILE_NEWS   "dat/news.dat"
#define FILE_COMMENT "dat/comments.dat"

int count_users = 0;
int count_authors = 0;
int count_news = 0;
int count_comments = 0;
Manager manager;


Manager::Manager()
    : writer_author(FILE_AUTHOR),
      writer_user(FILE_USER),
      writer_news(FILE_NEWS),
      writer_comment(FILE_COMMENT),
      reader_author(FILE_AUTHOR),
      reader_user(FILE_USER),
      reader_news(FILE_NEWS),
      reader_comment(FILE_COMMENT) {
    authors.resize(SIZE);
    users.resize(SIZE);
    news.resize(SIZE);
    comments.resize(SIZE);
      }

bool dni_exists(const std::string& dni) {
    for (int i = 0; i < count_users; ++i) {
        if (manager.users[i].getDNI() == dni) {
            return true;
        }
    }
    return false;
}

bool id_user_exists(int id) {
    for (int i = 0; i < count_users; ++i) {
        if (manager.users[i].getId() == id) return true;
    }
    return false;
}

void create_user() {
    if (count_users >= SIZE) {
        std::cout << "No se pueden agregar más usuarios (límite alcanzado)." << std::endl;
        return;
    }

    int id, age;
    std::string dni, name;

    std::cout << "Ingrese ID del usuario: ";
    std::cin >> id; std::cin.ignore();

    if (id_user_exists(id)) {
        std::cout << "Ya existe un usuario con ese ID.\n";
        return;
    }

    std::cout << "Ingrese edad: ";
    std::cin >> age; std::cin.ignore();

    std::cout << "Ingrese DNI: ";
    std::getline(std::cin, dni);

    for (int i = 0; i < count_users; ++i) {
        if (manager.users[i].getDNI() == dni) {
            std::cout << "Ya existe un usuario con ese DNI.\n";
            return;
        }
    }

    std::cout << "Ingrese nombre: ";
    std::getline(std::cin, name);

    User u(id, age, dni, name);
    manager.users[count_users++] = u;

    std::cout << "✅ Usuario creado correctamente.\n-------------------------------------\n";
}

bool dni_author_exists(const std::string& dni) {
    for (int i = 0; i < count_authors; ++i) {
        if (manager.authors[i].getDNI() == dni) {
            return true;
        }
    }
    return false;
}

bool id_author_exists(int id) {
    for (int i = 0; i < count_authors; ++i) {
        if (manager.authors[i].getId() == id) return true;
    }
    return false;
}

void create_author() {
    if (count_authors >= SIZE) {
        std::cout << "No se pueden agregar más autores (límite alcanzado)." << std::endl;
        return;
    }

    int id, media;
    std::string dni, name;

    std::cout << "Ingrese ID del autor: ";
    std::cin >> id; std::cin.ignore();

    if (id_author_exists(id)) {
        std::cout << "Ya existe un autor con ese ID.\n";
        return;
    }

    std::cout << "Ingrese medio (ID numérico): ";
    std::cin >> media; std::cin.ignore();

    std::cout << "Ingrese DNI: ";
    std::getline(std::cin, dni);

    for (int i = 0; i < count_authors; ++i) {
        if (manager.authors[i].getDNI() == dni) {
            std::cout << "Ya existe un autor con ese DNI.\n";
            return;
        }
    }

    std::cout << "Ingrese nombre: ";
    std::getline(std::cin, name);

    Author a(id, media, dni, name);
    manager.authors[count_authors++] = a;

    std::cout << "Autor creado correctamente.\n-------------------------------------\n";
}


bool id_news_exists(int id) {
    for (int i = 0; i < count_news; ++i) {
        if (manager.news[i].getId() == id) {
            return true;
        }
    }
    return false;
}

void create_new() {
    if (count_news >= SIZE) {
        std::cout << "No se pueden agregar más noticias (límite alcanzado)." << std::endl;
        return;
    }

    int id, day, month, year, author;
    std::string title, detail;

    std::cout << "Ingrese ID de la noticia: ";
    std::cin >> id; std::cin.ignore();

    if (id_news_exists(id)) {
        std::cout << "Ya existe una noticia con ese ID." << std::endl;
        return;
    }

    std::cout << "Ingrese día: ";
    std::cin >> day;
    std::cout << "Ingrese mes: ";
    std::cin >> month;
    std::cout << "Ingrese año: ";
    std::cin >> year;
    std::cout << "Ingrese ID del autor: ";
    std::cin >> author; std::cin.ignore();

    std::cout << "Ingrese título: ";
    std::getline(std::cin, title);
    std::cout << "Ingrese detalle: ";
    std::getline(std::cin, detail);

    News n(id, day, month, year, author, title, detail);
    manager.news[count_news++] = n;

    std::cout << "Noticia creada correctamente." <<"-------------------------------------"<< std::endl;
}

void create_comment() {
    if (count_comments >= SIZE) {
        std::cout << "No se pueden agregar más comentarios (límite alcanzado)." << std::endl;
        return;
    }

    int news_id, counter, user;
    std::string str;

    std::cout << "Ingrese ID de la noticia a la que pertenece el comentario: ";
    std::cin >> news_id; std::cin.ignore();

    if (!id_news_exists(news_id)) {
        std::cout << "No existe una noticia con ese ID. No se puede crear el comentario.\n";
        return;
    }

    std::cout << "Ingrese número de comentario (contador): ";
    std::cin >> counter;

    std::cout << "Ingrese ID del usuario que comenta: ";
    std::cin >> user; std::cin.ignore();

    
    if (!id_user_exists(user)) {
        std::cout << "No existe un usuario con ese ID.\n";
        return;
    }

    std::cout << "Ingrese texto del comentario: ";
    std::getline(std::cin, str);

    Comment c(news_id, counter, user, str);
    manager.comments[count_comments++] = c;

    std::cout << "Comentario creado correctamente.\n-------------------------------------\n";
}

void show_users() {
    if (count_users == 0) {
        std::cout << "No hay usuarios registrados.\n";
        return;
    }

    std::cout << "\n===== LISTA DE USUARIOS =====\n";
    for (int i = 0; i < count_users; ++i) {
        std::cout << "Usuario #" << (i + 1) << "\n";
        std::cout << "ID: " << manager.users[i].getId() << "\n";
        std::cout << "Edad: " << manager.users[i].getAge() << "\n";
        std::cout << "DNI: " << manager.users[i].getDNI() << "\n";
        std::cout << "Nombre: " << manager.users[i].getName() << "\n";
        std::cout << "---------------------------\n";
    }
}

void show_authors() {
    if (count_authors == 0) {
        std::cout << "No hay autores registrados.\n";
        return;
    }

    std::cout << "\n===== LISTA DE AUTORES =====\n";
    for (int i = 0; i < count_authors; ++i) {
        std::cout << "Autor #" << (i + 1) << "\n";
        std::cout << "ID: " << manager.authors[i].getId() << "\n";
        std::cout << "Media: " << manager.authors[i].getMedia() << "\n";
        std::cout << "DNI: " << manager.authors[i].getDNI() << "\n";
        std::cout << "Nombre: " << manager.authors[i].getName() << "\n";
        std::cout << "---------------------------\n";
    }
}

void show_news() {
    if (count_news == 0) {
        std::cout << "No hay noticias registradas.\n";
        return;
    }

    std::cout << "\n===== LISTA DE NOTICIAS =====\n";
    for (int i = 0; i < count_news; ++i) {
        std::cout << "Noticia #" << (i + 1) << "\n";
        std::cout << "ID: " << manager.news[i].getId() << "\n";
        std::cout << "Fecha: " 
                  << manager.news[i].getDay() << "/"
                  << manager.news[i].getMonth() << "/"
                  << manager.news[i].getYear() << "\n";
        std::cout << "Autor ID: " << manager.news[i].getAuthor() << "\n";
        std::cout << "Título: " << manager.news[i].getTitle() << "\n";
        std::cout << "Detalle: " << manager.news[i].getDetail() << "\n";
        std::cout << "---------------------------\n";
    }
}

void show_new(int id) {
    bool found = false;

    for (int i = 0; i < count_news; ++i) {
        if (manager.news[i].getId() == id) {
            std::cout << "\n===== DETALLE DE NOTICIA =====\n";
            std::cout << "ID: " << manager.news[i].getId() << "\n";
            std::cout << "Fecha: " 
                      << manager.news[i].getDay() << "/"
                      << manager.news[i].getMonth() << "/"
                      << manager.news[i].getYear() << "\n";
            std::cout << "Autor ID: " << manager.news[i].getAuthor() << "\n";
            std::cout << "Título: " << manager.news[i].getTitle() << "\n";
            std::cout << "Detalle: " << manager.news[i].getDetail() << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        std::cout << "No se encontró una noticia con ese ID " << id << ".\n";
}

void show_comments(int new_id) {
    bool found = false;

    std::cout << "\n===== COMENTARIOS DE LA NOTICIA ID: " << new_id << " =====\n";

    for (int i = 0; i < count_comments; ++i) {
        if (manager.comments[i].getUser() == new_id) {
            found = true;
            std::cout << "Comentario #" << (i + 1) << "\n";
            std::cout << "ID: " << manager.comments[i].getId() << "\n";
            std::cout << "Usuario ID: " << manager.comments[i].getUser() << "\n";
            std::cout << "Contador: " << manager.comments[i].getCounter() << "\n";
            std::cout << "Texto: " << manager.comments[i].getStr() << "\n";
            std::cout << "---------------------------\n";
        }
    }

    if (!found)
        std::cout << "No hay comentarios para esta noticia.\n";
}

void show_news_by_author() {
    if (count_news == 0) {
        std::cout << "No hay noticias registradas.\n";
        return;
    }

    for (int i = 0; i < count_news - 1; ++i) {
        for (int j = 0; j < count_news - i - 1; ++j) {
            if (manager.news[j].getAuthor() > manager.news[j + 1].getAuthor()) {
                std::swap(manager.news[j], manager.news[j + 1]);
            }
        }
    }

    std::cout << "\n===== NOTICIAS ORDENADAS POR AUTOR =====\n";
    for (int i = 0; i < count_news; ++i) {
        std::cout << "Autor ID: " << manager.news[i].getAuthor() << "\n";
        std::cout << "Noticia ID: " << manager.news[i].getId() << "\n";
        std::cout << "Título: " << manager.news[i].getTitle() << "\n";
        std::cout << "Fecha: "
                  << manager.news[i].getDay() << "/"
                  << manager.news[i].getMonth() << "/"
                  << manager.news[i].getYear() << "\n";
        std::cout << "---------------------------------\n";
    }
}

void show_news_by_year() {
    if (count_news == 0) {
        std::cout << "No hay noticias registradas.\n";
        return;
    }

    for (int i = 0; i < count_news - 1; ++i) {
        for (int j = 0; j < count_news - i - 1; ++j) {
            if (manager.news[j].getYear() < manager.news[j + 1].getYear()) {
                std::swap(manager.news[j], manager.news[j + 1]);
            }
        }
    }

    std::cout << "\n===== NOTICIAS ORDENADAS POR AÑO =====\n";
    for (int i = 0; i < count_news; ++i) {
        std::cout << "Año: " << manager.news[i].getYear() << "\n";
        std::cout << "ID: " << manager.news[i].getId() << "\n";
        std::cout << "Título: " << manager.news[i].getTitle() << "\n";
        std::cout << "Autor ID: " << manager.news[i].getAuthor() << "\n";
        std::cout << "---------------------------------\n";
    }
}

void show_news_by_last_month() {
    if (count_news == 0) {
        std::cout << "No hay noticias registradas.\n";
        return;
    }

    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int currentMonth = now->tm_mon + 1;
    int currentYear = now->tm_year + 1900;

    int lastMonth = currentMonth - 1;
    int yearToCheck = currentYear;

    if (lastMonth == 0) {
        lastMonth = 12;
        yearToCheck--;
    }

    bool found = false;
    std::cout << "\n===== NOTICIAS DEL MES ANTERIOR (" 
              << lastMonth << "/" << yearToCheck << ") =====\n";

    for (int i = 0; i < count_news; ++i) {
        if (manager.news[i].getMonth() == lastMonth && manager.news[i].getYear() == yearToCheck) {
            found = true;
            std::cout << "ID: " << manager.news[i].getId() << "\n";
            std::cout << "Título: " << manager.news[i].getTitle() << "\n";
            std::cout << "Autor ID: " << manager.news[i].getAuthor() << "\n";
            std::cout << "Fecha: " 
                      << manager.news[i].getDay() << "/" 
                      << manager.news[i].getMonth() << "/" 
                      << manager.news[i].getYear() << "\n";
            std::cout << "---------------------------------\n";
        }
    }

    if (!found)
        std::cout << "No se encontraron noticias del último mes.\n";
}

void show_comments_by_new() {
    if (count_comments == 0 || count_news == 0) {
        std::cout << "No hay comentarios o noticias registradas.\n";
        return;
    }

    int news_id;
    std::cout << "Ingrese el ID de la noticia: ";
    std::cin >> news_id;
    std::cin.ignore();

    bool found = false;

    std::cout << "\n===== COMENTARIOS DE LA NOTICIA ID " << news_id << " =====\n";

    for (int i = 0; i < count_comments; ++i) {
        if (manager.comments[i].getId() == news_id) {
            found = true;
            std::cout << "Comentario #" << (i + 1) << "\n";
            std::cout << "Usuario ID: " << manager.comments[i].getUser() << "\n";
            std::cout << "Texto: " << manager.comments[i].getStr() << "\n";
            std::cout << "---------------------------------\n";
        }
    }

    if (!found)
        std::cout << "No hay comentarios para esta noticia.\n";
}

void show_comments_by_user() {
    if (count_comments == 0) {
        std::cout << "No hay comentarios registrados.\n";
        return;
    }

    int user_id;
    std::cout << "Ingrese el ID del usuario: ";
    std::cin >> user_id;
    std::cin.ignore();

    bool found = false;
    std::cout << "\n===== COMENTARIOS DEL USUARIO ID " << user_id << " =====\n";

    for (int i = 0; i < count_comments; ++i) {
        if (manager.comments[i].getUser() == user_id) {
            found = true;
            std::cout << "Comentario ID (referencia noticia): " << manager.comments[i].getId() << "\n";
            std::cout << "Texto: " << manager.comments[i].getStr() << "\n";
            std::cout << "---------------------------------\n";
        }
    }

    if (!found)
        std::cout << "No hay comentarios de ese usuario.\n";
}


void c_author()
{
  bool flag=true;
  while (flag)
  {
    system("clear");
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
    std::cin.get();
  }
}

void c_user()
{
  bool flag=true;
  while (flag)
  {
    system("clear");
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
    std::cin.get();
  }
}

void c_new()
{
  bool flag=true;
  while (flag)
  {
    system("clear");
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
    std::cin.get();
  }
}

void controller()
{
  std::cout << "Bienvenido al gestor de noticias. . .\nEnter para continuar";
  std::cin.get();

  bool flag=true;
  while (flag)
  {
    system("clear");
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
