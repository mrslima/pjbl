#include "tabela.h"

bool argsVerify(int args) {
  if (args < 1) {
    puts("ERRO: nenhum arquivo foi passado como parâmetro!");
    return false;
  } else if (args == 2) {
    puts("ERRO: parâmetros insuficientes.");
    return false;
  } else if (args > 3) {
    puts("ERRO: informe apenas 2 parâmetros");
    return false;
  }

  return true;
}

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
  char *query = "%c, %20[^,], %d, %lf, %d, %d\n";
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

  if (fclose(file) == EOF) return false;
  return true;
}

type_actors *readBinFile(char *filename, int *total) {
  FILE *file;
  file = fopen(filename, "rb");

  if (file == NULL) {
    return NULL;
  }

  if (fread(total, sizeof(int), 1, file) != 1) {
    return NULL;
  }

  type_actors *data = malloc(sizeof(type_actors) * *total);

  if (fread(data, sizeof(type_actors), *total, file) != *total) {
    free(data);
    return NULL;
  }

  if (fclose(file) == EOF) {
    free(data);
    return NULL;
  }

  return data;
}

bool writeTxtFile(char *filename, type_actors *data, int total) {
  FILE *file;
  file = fopen("txtAtores.txt", "w");

  if (file == NULL) {
    puts("Erro ao criar o arquivo!");
    return false;
  }

  for (int i = 0; i < total; i++) {
    fprintf(file, "%c, %s, %d, %lf, %d, %d\n", data[i].genero, data[i].nome, data[i].idade, data[i].altura, data[i].mes, data[i].fama);

    if (ferror(file)) {
      puts("Erro ao escrever arquivo.\n");
      return false;
    }
  }

  fclose(file);

  printf("\n%d linhas escritas.\n", total);
  
}