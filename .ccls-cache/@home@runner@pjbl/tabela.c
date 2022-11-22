#include "tabela.h"

bool writeBinFile(char *filename, type_actors *data, int total) {
  FILE *file;
  file = fopen(filename, "wb");

  if (file == NULL) {
    puts("Erro! Não foi possível abrir o arquivo.");
    return false;
  }

  if (fwrite(&total, sizeof(int), 1, file) != 1)
    return false;

  if (fwrite(data, sizeof(type_actors), total, file) != total)
    return false;

  if (fclose(file) == EOF)
    return false;

  return true;
}

bool readTextFile(char *filename, type_actors *arr) {
  FILE *file;
  file = fopen(filename, "r");

  if (file == NULL) {
    puts("Arquivo não pode ser aberto!");
    return false;
  }
  char *query = "%d, %20[^,], %d, %lf, %d, %d\n";
  int read = 0;
  int indice = 0;

  while (!feof(file)) {
    read = fscanf(file, query, &arr[indice].genero, &arr[indice].nome,
                  &arr[indice].idade, &arr[indice].altura, &arr[indice].mes,
                  &arr[indice].fama);

    if (read == 6) {
      indice++;
    }
  }

  if (fclose(file) == EOF)
    return false;

  return true;
}

type_actors *readData(char *filename, int *total) {
  FILE *file;
  file = fopen(filename, "rb");

  if (file == NULL) {
    puts("1");
    return NULL;
  }

  if (fread(total, sizeof(int), 1, file) != 1) {
    puts("2");
    return NULL;
  }

  type_actors *data = malloc(sizeof(type_actors) * *total);

  if (fread(data, sizeof(type_actors), *total, file) != total) {
    puts("3");
    free(data);
    return NULL;
  }

  if (fclose(file) == EOF) {
    puts("4");
    free(data);
    return NULL;
  }

  return data;
}