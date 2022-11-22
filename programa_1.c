#include "tabela.h"

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "Portuguese");

  //    if (!(argc < 1)){
  //        puts("Nenhum arquivo foi passado como parâmetro!");
  //        return 1;
  //    } else if (argc > 2) {
  //        puts("Informe apenas um parâmetro");
  //        return 1;
  //    }

  // char *path = argv[1];
  char *path = "meuArquivo.txt";


  const int array_size = countFileLines("originalActors.txt");

  type_actors *arr_actors;
  arr_actors = malloc(sizeof(type_actors) * array_size);

  
  // Lê o conteúdo do arquivo .txt e armazena num array de struct
  if (readTextFile("originalActors.txt", arr_actors)) {
    printf("[%s]\tSUCESSO: leitura bem sucedida.\n\n", path);
  } else {
    printf("[%s]\tERRO: não foi possível ler o arquivo.\n\n", path);
    return 1;
  }

  // Pega o conteúdo do array de strutc e escreve (em binário) num arquivo .bin
  if (writeBinFile("binActors.bin", arr_actors, array_size)) {
    printf("[%s]\tSUCESSO: leitura bem sucedida.\n\n", path);
  } else {
    printf("[%s]\tERRO: não foi possível ler o arquivo.\n\n", path);
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

  
  for (int i = 0; i < array_size; i++) {
    printf("----- Pessoa %d -----\n", i);
    printf("\tGenero: %c\n", file_data[i].genero);
    printf("\tNome: %s\n", file_data[i].nome);
    printf("\tIdade: %d\n", file_data[i].idade);
    printf("\tAltura: %.2lf\n", file_data[i].altura);
    printf("\tMes nasc: %d\n", file_data[i].mes);
    printf("\tFama: %d\%\n\n", file_data[i].fama);
  }


  writeTxtFile("txtArquivo.txt", file_data, array_size);

  
  free(file_data); 






  
  return 0;
}
