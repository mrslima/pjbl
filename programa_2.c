// #include "tabela.h"

// int main(int argc, char *argv[]) {
//   int total = 0;
//   type_actors *file_data;

//   file_data = readBinFile("binAtores.bin", &total);

//   if (file_data == NULL) {
//     puts("Error reading from file!\n");
//     return 1;
//   }

//   puts("Data read OK\n\n");
//   for (int i = 0; i < ARRAY_SIZE; i++) {
//     printf("----- Pessoa %d -----\n", i);
//     printf("\tGenero: %d\n", file_data[i].genero);
//     printf("\tNome: %s\n", file_data[i].nome);
//     printf("\tIdade: %d\n", file_data[i].idade);
//     printf("\tAltura: %lf\n", file_data[i].altura);
//     printf("\tMes nasc: %d\n", file_data[i].mes);
//     printf("\tFama: %d\%\n\n", file_data[i].fama);
//   }

//   free(file_data);  
// }