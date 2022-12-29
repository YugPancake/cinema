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
  new_node->next = *head;
  (*head)->prev = new_node;
  new_node->prev = *head;
  (*head)->next = new_node;
  *head = new_node;
} // элемент в хед

void print_list(FILMS_LIST *head1) {
  char i;
  while (head1 -> next != NULL) {
    printf("%s\n%d\n%s\n%s\n%.1f\n", head1-> all_film.film_name,
           head1 -> all_film.year, head1 -> all_film.country, head1 -> all_film.genre,
           head1 -> all_film.rating);
    scanf("%s", &i);
    if (i == 'd'){
      head1 = head1 -> next;
    }
    else if(i == 'a') {
      head1 = head1 -> prev;
    }
    system("clear");
  }
} // вывод всего + перелистывание

int main(void) {
  char ex;
  FILM film1;
  FILMS_LIST *f = new_film(film1);
  f->next = f;
  f -> prev = f;
  
  head(&f, film_create("df", 3, "fd", "gfd", 4.5));
  head(&f, film_create("dff", 33, "fd", "gfd", 4.5));
  head(&f, film_create("dssff", 323, "fd", "gfd", 4.5));
  
  print_list(f);

  scanf("%s", &ex);
  if (ex == 'e'){
    exit(0);
  }
}

// надо вынести перелистывание из функции вывода в меин иначе мы не сможем выйти никуда из списка фильмов
// возможно функция вывода не нужна в принципе ибо выводиться список будет только 2 раза и далее через ифы к этим двум разам мы будем возвращаться