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
  (*head) = new_node;
} // элементы в список которые не работают аааааа