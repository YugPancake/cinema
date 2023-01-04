#include <stdio.h>
#include <stdlib.h>
#include "movie.h"

typedef struct film {
  char *film_name;
  char *year;
  char *country;
  char *genre;
  char *rating;
 } FILM; // структура информации о фильме

typedef struct node {
  FILM all_film;
  struct node *next;
  struct node *prev;
} FILMS_LIST; // структура списка фильмов (пойдет для общего и избранного)

FILM film_create(char *n, char *y, char *c, char *g, char *r) {
  FILM smth = {n, y, c, g, r};
  return smth;
} // создание элемента для списка


int main(void) {
  char e, i, s;
  char *n = (char *)malloc(sizeof(100));
  char *g = (char *)malloc(sizeof(100));
  char *y = (char *)malloc(sizeof(100));
  char *c = (char *)malloc(sizeof(100));
  char *r = (char *)malloc(sizeof(100));
  FILE *films = fopen("films.txt", "r");
  
  fgets(n, 100, films);
  fgets(y, 100, films);
  fgets(c, 100, films);
  fgets(g, 100, films);
  fgets(r, 100, films);
  
  FILM first = film_create(n, y, c, g, r);
  FILMS_LIST *f = new_film(first);
  f->next = f;
  f -> prev = f;

  for (int i = 1; i < 30; i++){
    fgets(n, 100, films);
    fgets(y, 100, films);
    fgets(c, 100, films);
    fgets(g, 100, films);
    fgets(r, 100, films);
    head(&f, film_create(n, y, c, g, r));
  } // создание списка которое не работает

  printf("Это экран ввода логина и пороля, который пока не готов\nНажмите l чтобы перейти к списку фильмов\nНажмите x чтобы выйти\n");
  scanf("%s", &e);
  
  if (e == 'x'){
    system("clear");
    printf("\%30s\n", "Вы вышли");
    exit(0);
  } // выход из проги при любой непонятной ситуации

  if (e == 'l'){
    system("clear");
    while (f -> next != NULL || f -> prev != NULL) {
      printf("\%40s\n\n", "Каталог фильмов");
      printf("\%28s\%20s\n\n", f -> all_film.film_name, f -> all_film.rating);
      printf("\%26s\n\n", "e <--     --> d");
      printf("\%34s\n", "s - подробнее");
      printf("\%28s\n", "x - выйти");
      scanf("%s", &i);
      if (i == 'd'){
        system("clear");
        f = f -> next;
      }
      if(i == 'a') {
        system("clear");
        f = f -> prev;
      }
      if (i == 's'){
        system("clear");
        printf("\%59s\n\n", "Подробная информация о фильме");
        printf("\%28s\%20s\n\n", f -> all_film.film_name, f -> all_film.rating);
        printf("\n\n<<-- x\n");
        scanf("%s", &s);
        if (s == 'x'){
          system("clear");
          continue;
        }
      }
      if (i == 'x'){
        system("clear");
        printf("\%30s\n", "Вы вышли");
        break;
      }
      system("clear");
    }
  }// пролистывание + просмотр доп инфы
}