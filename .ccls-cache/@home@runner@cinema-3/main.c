#include "movie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct film {
  char *film_name;
  char *year;
  char *country;
  char *genre;
  char *rating;
} FILM; // структура информации о фильме

typedef struct user {
  char *login;
  char *pass;
  int card;
  int fav;
  int admin;
} USER; // структура пользователя

typedef struct node {
  FILM all_film;
  struct node *next;
  struct node *prev;
} FILMS_LIST; // структура списка фильмов (пойдет для общего и избранного)

FILM film_create(char *n, char *y, char *c, char *g, char *r) {
  FILM smth = {n, y, c, g, r};
  return smth;
} // создание элемента для списка

USER user_create(char *l, char *p, int c, int f, int a) {
  USER smn = {l, p, c, f, a};
  return smn;
} // создание пользователя

int main(void) {
  int t = 0;
  int t1 = 0;
  int t11 = 0;
  int t12 = 0;
  int t2 = 0;
  char e, i, s;
  char *n = (char *)malloc(sizeof(100));
  char *g = (char *)malloc(sizeof(100));
  char *y = (char *)malloc(sizeof(100));
  char *c = (char *)malloc(sizeof(100));
  char *r = (char *)malloc(sizeof(100));
  char lp[62] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A',
                 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C',
                 'V', 'B', 'N', 'M', 'q', 'w', 'e', 'r', 't', 'y', 'u',
                 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k',
                 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', '0', '1', '2',
                 '3', '4', '5', '6', '7', '8', '9'};
  char num[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  char l[100];
  char p[100];
  char k[100];

  FILE *films = fopen("films.txt", "r");
  FILE *users = fopen("users.txt", "w+");

  fgets(n, 100, films);
  fgets(y, 100, films);
  fgets(c, 100, films);
  fgets(g, 100, films);
  fgets(r, 100, films);

  FILM first = film_create(n, y, c, g, r);
  FILMS_LIST *f = new_film(first);
  f->next = f;
  f->prev = f;

  for (int i = 1; i < 30; i++) {
    fgets(n, 100, films);
    fgets(y, 100, films);
    fgets(c, 100, films);
    fgets(g, 100, films);
    fgets(r, 100, films);
    head(&f, film_create(n, y, c, g, r));
  } // создание списка которое не работает

  system("clear");
  printf("\%24s\n\n", "Вход");
  printf("\%50s\n", "Зарегестрироваться --> r");
  scanf("%s", &e);

  if (e == 'r') {
    system("clear");
    printf("\%35s\n\n", "Регистрация");
    printf("Логин: ");
    scanf("%s", &l);
    if ((strlen(l) >= 3 && strlen(l) <= 20)) {
      for (int i = 0; i < strlen(l); i++)
        for (int j = 0; j < 52; j++)
          if (l[i] == lp[j]) {
            t++;
          }
      if (t == strlen(l)) {
        printf("Пароль: ");
        scanf("%s", &p);
        if ((strlen(p) >= 6 && strlen(p) <= 20)) {
          for (int l = 0; l < strlen(p); l++) {
            for (int g = 0; g < 62; g++)
              if (p[l] == lp[g]) {
                t1++;
              }
            for (int g = 0; g < 26; g++)
              if (p[l] == lp[g]) {
                t11++;
              }
            for (int g = 0; g < 10; g++)
              if (p[l] == num[g]) {
                t12++;
              }
          }
          if (t1 == strlen(p) && t11 > 0 && t12 > 0) {
            printf("Номер карты: ");
            scanf("%s", &k);
            if ((strlen(k) == 16)) {
              for (int l = 0; l < strlen(k); l++)
                for (int g = 0; g < 10; g++)
                  if (k[l] == num[g]) {
                    t2++;
                  }
              if (t2 == strlen(k)) {
                printf("Вы зарегестрировались");
              } else {
                printf("Номер карты должен содержать 16 цифр\n");
                printf("\n\%29s\n", "Выйти --> x");
                scanf("%s", &s);
                if (s == 'x') {
                  system("clear");
                  printf("\%30s\n", "Вы вышли");
                  exit(0);
                }
              }
            } else {
              printf("Номер карты должен 16 цифр\n");
              printf("\n\%29s\n", "Выйти --> x");
              scanf("%s", &s);
              if (s == 'x') {
                system("clear");
                printf("\%30s\n", "Вы вышли");
                exit(0);
              }
            }
          } else {
            printf("Пароль должен содержать от 6 до 20 символов латинского "
                   "алфавита и цифр и содержать минимум по одной букве в "
                   "верхнем и нижнем регистре и одну цифру\n");
            printf("\n\%29s\n", "Выйти --> x");
            scanf("%s", &s);
            if (s == 'x') {
              system("clear");
              printf("\%30s\n", "Вы вышли");
              exit(0);
            }
          }
        } else {
          printf("Пароль должен содержать от 6 до 20 символов латинского "
                 "алфавита и цифр и содержать минимум по одной букве в "
                 "верхнем и нижнем регистре и одну цифру\n");
          printf("\n\%29s\n", "Выйти --> x");
          scanf("%s", &s);
          if (s == 'x') {
            system("clear");
            printf("\%30s\n", "Вы вышли");
            exit(0);
          }
        }
      } else {
        printf("Логин должен содержать от 3 до 20 символов латинского "
               "алфавита\n");
        printf("\n\%29s\n", "Выйти --> x");
        scanf("%s", &s);
        if (s == 'x') {
          system("clear");
          printf("\%30s\n", "Вы вышли");
          exit(0);
        }
      }
    } else {
      printf(
          "Логин должен содержать от 3 до 20 символов латинского алфавита\n");
      printf("\n\%29s\n", "Выйти --> x");
      scanf("%s", &s);
      if (s == 'x') {
        system("clear");
        printf("\%30s\n", "Вы вышли");
        exit(0);
      }
    }
  }

  if (e == 'x') {
    system("clear");
    printf("\%30s\n", "Вы вышли");
    exit(0);
  } // выход из проги при любой непонятной ситуации

  if (e == 'l') {
    system("clear");
    while (f->next != NULL || f->prev != NULL) {
      printf("\%40s\n\n", "Каталог фильмов");
      printf("\%28s\%20s\n\n", f->all_film.film_name, f->all_film.rating);
      printf("\%26s\n\n", "a <--     --> d");
      printf("\%34s\n", "s - подробнее");
      printf("\%28s\n", "x - выйти");
      scanf("%s", &i);
      if (i == 'd') {
        system("clear");
        f = f->next;
      }
      if (i == 'a') {
        system("clear");
        f = f->prev;
      }
      if (i == 's') {
        system("clear");
        printf("\%59s\n\n", "Подробная информация о фильме");
        printf("\%28s\%20s\n\n", f->all_film.film_name, f->all_film.rating);
        printf("\n\n<-- x\n");
        scanf("%s", &s);
        if (s == 'x') {
          system("clear");
          continue;
        }
      }
      if (i == 'x') {
        system("clear");
        printf("\%30s\n", "Вы вышли");
        break;
      }
      system("clear");
    }
  } // пролистывание + просмотр доп инфы
}