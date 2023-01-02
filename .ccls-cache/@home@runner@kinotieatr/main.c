#include <stdio.h>
#include <stdlib.h>

typedef struct film {
  char *film_name;
  int year;
  char *country;
  char *genre;
  float rating;
} FILM; // структура информации о фильме

typedef struct node {
  FILM all_film;
  struct node *next;
  struct node *prev;
} FILMS_LIST; // структура списка фильмов (пойдет для общего и избранного)

FILM film_create(char *n, int y, char *c, char *g, float r) {
  FILM smth = {n, y, c, g, r};
  return smth;
} // создание элемента для списка, значения брать из файла

FILMS_LIST *new_film(FILM film) {
  FILMS_LIST *film_in = (FILMS_LIST*)malloc(sizeof(FILMS_LIST));
  film_in->all_film = film;
  film_in->next = NULL;
  film_in->prev = NULL;
  return film_in;
}

void head(FILMS_LIST **head, FILM node) {
  FILMS_LIST *new_node = new_film(node);
  if (new_node -> next != NULL){
    new_node -> next = (*head);
  }
  if (new_node -> prev != NULL){
    new_node -> prev = (*head);
  }
  new_node->next = *head;
  (*head)->prev = new_node;
  (*head) = new_node;
} // элемент в хед

void add(FILMS_LIST **head, FILMS_LIST **film1, FILM new_node){
  FILMS_LIST *node1 = new_film(new_node);
  node1 -> next = (*film1) -> next;
  if (node1 -> next != NULL){
    node1 -> next -> prev = (*film1);
  }
  node1 -> prev = (*film1);
  (*film1) -> next = node1;
  node1 -> next = (*film1);
  (*film1) -> prev = node1;
}

int main(void) {
  char e, i;
  FILM film1;
  FILMS_LIST *f = new_film(film1);
  f->next = f;
  f -> prev = f;
  
  head(&f, film_create("df", 3, "fd", "gfd", 4.5));
  head(&f, film_create("aaaa", 3, "fdd", "gfd", 4.5));
  head(&f, film_create("cccc", 3, "fd", "gfd", 4.5));
  head(&f, film_create("bbbb", 3, "fdd", "gfd", 4.5));

  printf("Это экран ввода логина и пороля, который пока не готов\nНажмите l чтобы перейти к списку фильмов\nНажмите е чтобы завершить программу\n");

  scanf("%s", &e);
  
  if (e == 'e'){
    exit(0);
  } // выхож из проги при любой непонятной ситуации

  if (e == 'l'){
  system("clear");
    while (f -> next != NULL) {
      printf("%s\n%d\n%s\n%s\n%.1f\n", f-> all_film.film_name,
             f -> all_film.year, f -> all_film.country, f -> all_film.genre,
             f -> all_film.rating);
      scanf("%s", &i);
      if (i == 'd'){
        f = f -> next;
      }
      if(i == 'a') {
        f = f -> prev;
      }
      system("clear");
    }
  } // пролистывание, надо убрать некоторые вещи из вывода и будет норм
}