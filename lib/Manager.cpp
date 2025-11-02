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
std::string medias[4] = {"Clarin" ,"La Voz" ,"El Pais" ,"TN" };


Manager::Manager()
    :   writer_author(FILE_AUTHOR),
        writer_user(FILE_USER),
        writer_news(FILE_NEWS),
        writer_comment(FILE_COMMENT),
        reader_author(FILE_AUTHOR),
        reader_user(FILE_USER),
        reader_news(FILE_NEWS),
        reader_comment(FILE_COMMENT) 
{
    count_authors = reader_author.get_last_id();
    count_users = reader_user.get_last_id();
    count_news = reader_news.get_last_id();
    count_comments = reader_comment.get_last_id();

    if (count_authors + count_users + count_news + count_comments > 0) {
        read_all();
    }

}

void Manager::read_all() {
    try {
        size_t countA = reader_author.count();
        for (size_t i = 0; i < countA; i++) {
            A a_struct;
            if (reader_author.read_at(i, a_struct)) {
                Author a;
                a.from_struct(a_struct);
                authors.push_back(a);
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error leyendo autores: " << e.what() << std::endl;
    }

    try {
        size_t countU = reader_user.count();
        for (size_t i = 0; i < countU; i++) {
            U u_struct;
            if (reader_user.read_at(i, u_struct)) {
                User u;
                u.from_struct(u_struct);
                users.push_back(u);
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error leyendo usuarios: " << e.what() << std::endl;
    }

    try {
        size_t countN = reader_news.count();
        for (size_t i = 0; i < countN; i++) {
            N n_struct;
            if (reader_news.read_at(i, n_struct)) {
                News n;
                n.from_struct(n_struct);
                news.push_back(n);
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error leyendo noticias: " << e.what() << std::endl;
    }

    try {
        size_t countC = reader_comment.count();
        for (size_t i = 0; i < countC; i++) {
            C c_struct;
            if (reader_comment.read_at(i, c_struct)) {
                Comment c;
                c.from_struct(c_struct);
                comments.push_back(c);
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error leyendo comentarios: " << e.what() << std::endl;
    }

    std::cout << "Datos cargados correctamente: "
              << authors.size() << " autores, "
              << users.size() << " usuarios, "
              << news.size() << " noticias, "
              << comments.size() << " comentarios.\n";
}

void create_user() {
    if (count_users >= SIZE) {
        std::cout << "No se pueden agregar más usuarios (límite alcanzado)." << std::endl;
        return;
    }
    int id, age;
    std::string dni, name;

    id = count_users + 1;

    std::cout << id << "\n";

    
    age = verify_int(align_left("Ingrese edad:"), 0, 120);
    dni = verify_string(align_left("Ingrese DNI\n[xx.xxx.xxx]:"), 10);
    for (int i = 0; i < count_users; ++i) {
        if (manager.users[i].getDNI() == dni) {
            std::cout << "Ya existe un usuario con ese DNI.\n";
            return;
        }
    }

    name = verify_string(align_left("Ingrese nombre:"), 50);

    User u(id, age, dni, name);
    manager.users.push_back(u);
    count_users++;
    manager.writer_user.write(u.to_struct());

    std::cout << "Usuario creado correctamente.\n-----------------------------------------------------\n";
}

void create_author() {
    if (count_authors >= SIZE) {
        std::cout << "No se pueden agregar más autores (límite alcanzado)." << std::endl;
        return;
    }

    int id, media;
    std::string dni, name;

    id = count_authors + 1;

    std::cout << id << "\n";

    media = verify_int(align_left("Ingrese medio\nClarin (0)\nLa Voz (1)\nEl Pais (2)\nTN (3)\n"), 0, 3);
    dni = verify_string(align_left("Ingrese DNI\n[xx.xxx.xxx]:"), 10);

    for (int i = 0; i < count_authors; ++i) {
        if (manager.authors[i].getDNI() == dni) {
            std::cout << "Ya existe un autor con ese DNI.\n";
            return;
        }
    }

    name = verify_string(align_left("Ingrese nombre: "), 50);

    Author a(id, media, dni, name);
    manager.authors.push_back(a);
    count_authors++;
    manager.writer_author.write(a.to_struct());

    std::cout << "Autor creado correctamente.\n-----------------------------------------------------\n";
}

void create_new() {
    if (count_news >= SIZE) {
        std::cout << "No se pueden agregar más noticias (límite alcanzado)." << std::endl;
        return;
    }

    int id, day, month, year, author;
    std::string title, detail;

    id = count_news + 1;

    std::cout << id << "\n";

    day = verify_int(align_left("Ingrese día (1-31):"), 1, 31);
    month = verify_int(align_left("Ingrese mes (1-12):"), 1, 12);
    year = verify_int(align_left("Ingrese año:"), 0, 2025);
    author = verify_int(align_left("Ingrese ID del autor:"), 1, count_authors);
    if (!id_author_exists(author)) {
        std::cout << "No existe un autor con ese ID.\n";
        return;
    }
    title = verify_string(align_left("Ingrese título:"), 100);
    detail = verify_string(align_left("Ingrese detalle:"), 500);

    News n(id, day, month, year, author, title, detail);
    manager.news.push_back(n);
    count_news++;
    manager.writer_news.write(n.to_struct());

    std::cout << "Noticia creada correctamente.\n-----------------------------------------------------\n";
}

void create_comment(int news_id) {
    if (count_comments >= SIZE) {
        std::cout << "No se pueden agregar más comentarios (límite alcanzado)." << std::endl;
        return;
    }

    int id, user;
    std::string str;

    id = count_comments + 1;

    std::cout << id << "\n";

    user = verify_int(align_left("Ingrese ID del usuario:"), 1, count_users);
    if (!id_user_exists(user)) {
        std::cout << "No existe un usuario con ese ID.\n";
        return;
    }
    str = verify_string(align_left("Ingrese el comentario:"), 300);

    Comment c(id, news_id, user, str);
    manager.comments.push_back(c);
    count_comments++;
    manager.writer_comment.write(c.to_struct());

    std::cout << "Comentario creado correctamente.\n-----------------------------------------------------\n";
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

bool id_news_exists(int id) {
    for (int i = 0; i < count_news; ++i) {
        if (manager.news[i].getId() == id) {
            return true;
        }
    }
    return false;
}

void show_users() {
    if (count_users == 0) {
        std::cout << "No hay usuarios registrados.\n";
        return;
    }

    std::cout << "\n=============== LISTA DE USUARIOS ===============\n";
    for (int i = 0; i < count_users; ++i) {
        std::cout << align_left("Usuario") << (i + 1) << "\n";
        std::cout << align_left("Edad:") << manager.users[i].getAge() << "\n";
        std::cout << align_left("DNI:") << manager.users[i].getDNI() << "\n";
        std::cout << align_left("Nombre:") << manager.users[i].getName() << "\n";
        std::cout << "-----------------------------------------------------\n";
    }
}

void show_authors() {
    if (count_authors == 0) {
        std::cout << "No hay autores registrados.\n";
        return;
    }

    std::cout << "\n=============== LISTA DE AUTORES ===============\n";
    for (int i = 0; i < count_authors; ++i) {
        std::cout << align_left("Autor") << (i + 1) << "\n";
        std::cout << align_left("Media:") << medias[manager.authors[i].getMedia()] << "\n";
        std::cout << align_left("DNI:") << manager.authors[i].getDNI() << "\n";
        std::cout << align_left("Nombre:") << manager.authors[i].getName() << "\n";
        std::cout << "-----------------------------------------------------\n";
    }
}

void show_news() {
    if (count_news == 0) {
        std::cout << "No hay noticias registradas.\n";
        return;
    }

    std::cout << "\n=============== LISTA DE NOTICIAS ===============\n";
    for (int i = 0; i < count_news; ++i) {
        std::cout << align_left("Noticia")  << (i + 1) << "\n";
        std::cout << align_left("Fecha:")  
                  << manager.news[i].getDay() << "/"
                  << manager.news[i].getMonth() << "/"
                  << manager.news[i].getYear() << "\n";
        std::cout << align_left("Título:")  << manager.news[i].getTitle() << "\n";
        std::cout << "-----------------------------------------------------\n";
    }

    int choice = verify_int("Ingrese el ID de la noticia para ver detalles (0 para salir): ", 0, count_news);
    if (choice != 0) {
        show_new(choice);
    }
}

void show_new_data(int id)
{
    bool found = false;

    for (int i = 0; i < count_news; ++i) {
        if (manager.news[i].getId() == id) {
            std::cout << "\n=============== DETALLE DE NOTICIA ===============\n";
            std::cout << align_left("ID:") << manager.news[i].getId() << "\n";
            std::cout << align_left("Fecha:") 
                      << manager.news[i].getDay() << "/"
                      << manager.news[i].getMonth() << "/"
                      << manager.news[i].getYear() << "\n";
            std::cout << align_left("Autor ID:") << manager.news[i].getAuthor() << "\n";
            std::cout << align_left("Título:") << manager.news[i].getTitle() << "\n";
            std::cout << align_left("Detalle:") << manager.news[i].getDetail() << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        std::cout << "No se encontró una noticia con ese ID " << id << ".\n";
}

void show_new(int id) {
    show_new_data(id);

    std::cout << "Quieres ver los comentarios de esta noticia? (s/n): ";
    char choice;
    std::cin >> choice; std::cin.ignore();
    if (choice == 's' || choice == 'S') {
        show_comments(id);
    }
    std::cout << "Quieres crear un comentario para esta noticia? (s/n): ";
    std::cin >> choice; std::cin.ignore();
    if (choice == 's' || choice == 'S') {
        create_comment(id);
    }
}

void show_comments(int new_id) {
    bool found = false;

    std::cout << "\n=============== COMENTARIOS DE LA NOTICIA ID: " << new_id << " ===============\n";

    for (int i = 0; i < count_comments; ++i) {
        if (manager.comments[i].getUser() == new_id) {
            found = true;
            std::cout << align_left("Comentario") << (i + 1) << "\n";
            std::cout << align_left("ID:") << manager.comments[i].getId() << "\n";
            std::cout << align_left("Usuario ID:") << manager.comments[i].getUser() << "\n";
            std::cout << align_left("Texto:") << manager.comments[i].getStr() << "\n";
            std::cout << "-----------------------------------------------------\n";
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

    int author_id = verify_int("Ingrese el ID del autor: ", 1, count_authors);

    std::cout << "\n=============== NOTICIAS DEL AUTOR ID " << author_id << " ===============\n";
    for (int i = 0; i < count_news; ++i) {
        if (manager.news[i].getAuthor() == author_id) {
            show_new_data(manager.news[i].getId());
        }
    }
}

void show_news_by_year() {
    if (count_news == 0) {
        std::cout << "No hay noticias registradas.\n";
        return;
    }

    int year = verify_int("Ingrese el año: ", 0, 2025);

    std::cout << "\n=============== NOTICIAS DEL AÑO " << year << " ===============\n";
    for (int i = 0; i < count_news; ++i) {
        if (manager.news[i].getYear() == year) {
            show_new_data(manager.news[i].getId());
        }
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
    std::cout << "\n=============== NOTICIAS DEL MES ANTERIOR (" 
              << lastMonth << "/" << yearToCheck << ") ===============\n";

    for (int i = 0; i < count_news; ++i) {
        if (manager.news[i].getMonth() == lastMonth && manager.news[i].getYear() == yearToCheck) {
            show_new_data(manager.news[i].getId());
            found = true;
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

    std::cout << "\n=============== COMENTARIOS DE LA NOTICIA ID " << news_id << " ===============\n";

    for (int i = 0; i < count_comments; ++i) {
        if (manager.comments[i].getId() == news_id) {
            found = true;
            std::cout << "Comentario #" << (i + 1) << "\n";
            std::cout << "Usuario ID: " << manager.comments[i].getUser() << "\n";
            std::cout << "Texto: " << manager.comments[i].getStr() << "\n";
            std::cout << "-----------------------------------------------------\n";
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
    std::cout << "\n=============== COMENTARIOS DEL USUARIO ID " << user_id << " ===============\n";

    for (int i = 0; i < count_comments; ++i) {
        if (manager.comments[i].getUser() == user_id) {
            found = true;
            std::cout << "Comentario ID (referencia noticia): " << manager.comments[i].getId() << "\n";
            std::cout << "Texto: " << manager.comments[i].getStr() << "\n";
            std::cout << "-----------------------------------------------------\n";
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
