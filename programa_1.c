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

  //    char *path = argv[1];

  type_actors *arr_actors;
  arr_actors = malloc(sizeof(type_actors) * ARRAY_SIZE);

  if (readTextFile("txtAtores.txt", arr_actors)) {
    puts("Read data OK.\n");
  } else {
    puts("Error reading to file.\n");
    return 1;
  }

  if (writeBinFile("binAtores.bin", arr_actors, ARRAY_SIZE)) {
    puts("Write data OK.\n");
  } else {
    puts("Error writing to file.\n");
    return 1;
  }

  free(arr_actors);



  // Programa 2
  int total = 0;
  type_actors *file_data;

  file_data = readBinFile("binAtores.bin", &total);

  if (file_data == NULL) {
    puts("Error reading from file!\n");
    return 1;
  }

  puts("Data read OK\n\n");
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("----- Pessoa %d -----\n", i);
    printf("\tGenero: %d\n", file_data[i].genero);
    printf("\tNome: %s\n", file_data[i].nome);
    printf("\tIdade: %d\n", file_data[i].idade);
    printf("\tAltura: %lf\n", file_data[i].altura);
    printf("\tMes nasc: %d\n", file_data[i].mes);
    printf("\tFama: %d\%\n\n", file_data[i].fama);
  }

  free(file_data);

  return 0;
}
