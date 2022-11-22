#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TABELA_H_INCLUDED
#define TABELA_H_INCLUDED

#define MAX_STR_LEN 20
#define BUFFER_SIZE 4096
#define ARRAY_SIZE 20

typedef enum {
  janeiro,
  fevereiro,
  marco,
  abril,
  maio,
  junho,
  julho,
  agosto,
  setembro,
  outubro,
  novembro,
  dezembro
} meses;
static char mes_str[12][10] = {"janeiro",  "fevereiro", "março",    "abril",
                               "maio",     "junho",     "julho",    "agosto",
                               "setembro", "outubro",   "novembro", "dezembro"};

typedef enum { masculino, feminino } generos;
static char genero_str[2][9] = {"masculino", "feminino"};

typedef struct {
  generos genero;
  char nome[MAX_STR_LEN];
  int idade;
  double altura;
  meses mes;
  int fama;

} type_actors;

// Programa 1
bool readTextFile(char *filename, type_actors *arr);
bool writeBinFile(char *filename, type_actors *data, int total);

// Programa 2
type_actors *readBinFile(char *filename, int *total);
bool writeTxtFile(char *filename, type_actors *data, int total);
int printAll();
int avgFilter();

// Ambos
int editarDados();
int countFileLines(char *filename);

#endif // TABELA_H_INCLUDED
