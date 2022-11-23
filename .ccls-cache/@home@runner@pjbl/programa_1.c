#include "tabela.h"


int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "Portuguese");

  // if (!argsVerify(argc)) return 1;

  // char *path = argv[1];
  char *path = "meuArquivo.txt";

  type_actors *arr_actors;
  arr_actors = malloc(sizeof(type_actors) * ARRAY_SIZE);

  
  // Lê o conteúdo do arquivo .txt e armazena num array de struct
  if (readTextFile("originalActors.txt", arr_actors)) {
    printf("[%s]\tSUCESSO: leitura bem sucedida.\n\n", path);
  } else {
    printf("[%s]\tERRO: não foi possível ler o arquivo.\n\n", path);
    return 1;
  }

  // Pega o conteúdo do array de strutc e escreve (em binário) num arquivo .bin
  if (writeBinFile("binActors.bin", arr_actors, ARRAY_SIZE)) {
    printf("[%s]\tSUCESSO: escrita bem sucedida.\n\n", path);
  } else {
    printf("[%s]\tERRO: não foi possível escrever o arquivo.\n\n", path);
    return 1;
  }

  //  Limpa o array de struct
  free(arr_actors);




  // PROGRAMA 2

  int total = 0;
  type_actors *file_data;

  file_data = readBinFile("binActors.bin", &total);

  if (file_data == NULL) {
    printf("[%s]\tERRO: não foi possível ler o arquivo.\n\n", path);
    return 1;
  }
  printf("[%s]\tSUCESSO: leitura bem sucedida.\n\n", path);


  if (writeTxtFile("txtAtores.txt", file_data, ARRAY_SIZE)) {
    printf("[%s]\tSUCESSO: escrita bem sucedida.\n\n", path);
  } else {
    printf("[%s]\tERRO: não foi possível escrever o arquivo.\n\n", path);
    return 1;
  }

  int opcao;
  bool encerrar = false;
  
  do{
    puts("-------------[MENU]--------------");
    puts("|\t1. Média Aritmética de algo\t|");
    puts("|\t2. Imprimir algo\t\t\t|");
    puts("|\t0. Sair\t\t\t\t\t\t|");
    puts("---------------------------------");

    puts("\nOpcao: ");
    scanf("%d", &opcao);
    limpaBuffer();
    
    switch(opcao) {
      case 0:
        system("cls || clear");
        encerrar = true;
        break;
      case 1:
        system("cls || clear");
        avgFilter(file_data);
        break;
      case 2:
        system("cls || clear");
        printFeatures(file_data);
        break;
      default:
      system("cls || clear");
      printf("\n[!!!]   Opcao invalida! Tente novamente.\n\n");
    }
  }
  while (!encerrar);
  
  puts("\nPrograma encerrado.\n");
  
  free(file_data); 
  return 0;
}
