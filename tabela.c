#include "tabela.h"


void limpaBuffer(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

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

  // printf("\n%d linhas escritas.\n", total);

  return true;
}

void printFeatures(type_actors *arr) {
  int feature;
  puts("\t[IMPRIMIR CARACTERÍSTICA]");
  puts("\t1. Gênero");
  puts("\t2. Idade");
  puts("\t3. Altura");
  puts("\t4. Mês de nascimento");
  puts("\t5. Índice de fama");
  puts("\t6. Imprimir tudo");
  puts("\t0. Voltar");


  puts("\nOpcao: ");
  scanf("%d", &feature);
  limpaBuffer();
  
  switch (feature) {
    case 0:
      system("cls || clear");
      break;
    case 1:
      system("cls || clear");
      puts("Gênero dos atores:");
      for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("\t%s - %c\n", arr[i].nome, arr[i].genero);
      }
      puts("\n\n");
      break;
    case 2:
      system("cls || clear");
      puts("Idade dos atores:");
      for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("\t%s - %d anos\n", arr[i].nome, arr[i].idade);
      }
      puts("\n\n");
      break;
    case 3:
      system("cls || clear");
      puts("Altura dos atores:");
      for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("\t%s - %.2lfm\n", arr[i].nome, arr[i].altura);
      }
      puts("\n\n");
      break;
    case 4:
      system("cls || clear");
      puts("Mês de nascimento dos atores:");
      for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("\t%s - %d\n", arr[i].nome, arr[i].mes);
      }
      puts("\n\n");
      break;
    case 5:
      system("cls || clear");
      puts("Índice de fama dos atores:");
      for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("\t%s - %d\%\n", arr[i].nome, arr[i].fama);
      }
      puts("\n\n");
      break;
    case 6:
      system("cls || clear");
      for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("----- Ator/Atriz %d -----\n", i);
        printf("\tGenero: %c\n", arr[i].genero);
        printf("\tNome: %s\n", arr[i].nome);
        printf("\tIdade: %d\n", arr[i].idade);
        printf("\tAltura: %.2lf\n", arr[i].altura);
        printf("\tMes nasc: %d\n", arr[i].mes);
        printf("\tFama: %d\%\n\n", arr[i].fama);
      }
      puts("\n\n");
      break;
    default:
      system("cls || clear");
      printf("\n[!!!]   Opcao invalida! Tente novamente.\n\n");
      break;
  }
}



double average(double a[], int n)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
      sum += a[i];

  return (double)sum / n;
}

void avgFilter(type_actors *arr) {
  double d_arr[ARRAY_SIZE];
  int opcao, n;
  double avg;
  
  puts("\t[IMPRIMIR CARACTERÍSTICA]");
  puts("\t1. Idade");
  puts("\t2. Altura");
  puts("\t3. Índice de fama");
  puts("\t0. Voltar");

  puts("\nOpção: ");
  scanf("%d", &opcao);
  limpaBuffer();
  
  switch (opcao) {
    case 0:
      system("cls || clear");
      break;
    case 1:
      system("cls || clear");
      for (int i = 0; i < ARRAY_SIZE; i++) {
        d_arr[i] = arr[i].idade;
      }
      avg = average(d_arr, ARRAY_SIZE);
      printf(">>> Média da idade dos atores [%.1lf anos]", avg);
      puts("\n\n");
      break;
    case 2:
      system("cls || clear");
      for (int i = 0; i < ARRAY_SIZE; i++) {
        d_arr[i] = arr[i].altura*100;
      }
      avg = average(d_arr, ARRAY_SIZE);
      printf(">>> Média da altura dos atores: [%.1lfm]", avg);
      puts("\n\n");
      break;
    case 3:
      system("cls || clear");
      for (int i = 0; i < ARRAY_SIZE; i++) {
        d_arr[i] = arr[i].fama;
      }
      avg = average(d_arr, ARRAY_SIZE);
      printf(">>> Média da fama dos atores: [%.1lf\%]", avg);
      puts("\n\n");
      break;
    default:
      system("cls || clear");
      printf("\n[!!!]   Opcao invalida! Tente novamente.\n\n");
      break;
  }
}