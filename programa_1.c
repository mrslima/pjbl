#include "tabela.h"

int main(int argc, char *argv[]) {
	
	// Verifica se os parâmetros foram informados corretamente.
    if (!argsVerify(argc)) return 1;


	char *in_path = argv[1];
	char *out_path = argv[2];

	type_actors *arr_actors;
	arr_actors = malloc(sizeof(type_actors) * ARRAY_SIZE);


	// Lê o conteúdo do arquivo .txt e armazena num array de struct
	if (readTextFile(in_path, arr_actors)) {
		printf("[%s]\tSUCESSO: leitura bem sucedida.\n\n", in_path);
	} else {
		printf("ERRO: nao foi possível ler o arquivo.\n\n");
		return 1;
	}

	// Pega o conteúdo do array de strutc e escreve (em binário) num arquivo .bin
	if (writeBinFile(out_path, arr_actors, ARRAY_SIZE)) {
		printf("[%s] -> [%s]\tSUCESSO: escrita bem sucedida.\n\n", in_path, out_path);
	} else {
		printf("ERRO: nao foi possível escrever o arquivo.\n\n");
		return 1;
	}

	//  Limpa o array de struct
	free(arr_actors);


	return 0;
}
