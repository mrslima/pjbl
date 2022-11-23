#include "tabela.h"

int main(int argc, char *argv[]) {

    if (!argsVerify(argc)) return 1;

	char *in_path = argv[1];
	char *out_path = argv[2];


	int total = 0;
	type_actors *file_data;

	file_data = readBinFile(in_path, &total);

	if (file_data == NULL) {
		printf("[%s]\tERRO: nao foi possível ler o arquivo.\n\n", in_path);
		return 1;
	}
	printf("[%s]\tSUCESSO: leitura bem sucedida.\n\n", in_path);


	if (writeTxtFile(out_path, file_data, ARRAY_SIZE)) {
		printf("[%s]\tSUCESSO: escrita bem sucedida.\n\n", in_path);
	} else {
		printf("[%s]\tERRO: nao foi possível escrever o arquivo.\n\n", in_path);
		return 1;
	}
	
	
	int opcao;
	bool encerrar = false;

	do{
		puts("-=-=<[MENU]>=-=-");
		puts(" 1. Media Aritmetica de algo");
		puts(" 2. Imprimir algo");
		puts(" 0. Sair");

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