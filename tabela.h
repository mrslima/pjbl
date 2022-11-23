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

typedef struct {
  char genero;
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
void printFeatures(type_actors *arr);
double average(double a[], int n);
void avgFilter(type_actors *arr);
void limpaBuffer();

// Ambos;
bool argsVerify(int args);

#endif // TABELA_H_INCLUDED
