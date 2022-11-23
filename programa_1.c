#include "tabela.h"

int main(int argc, char *argv[]) {
	
   	if (!argsVerify(argc)) return 1;


	char *in_path = argv[1];
	char *out_path = argv[2];

	type_actors *arr_actors;
	arr_actors = malloc(sizeof(type_actors) * ARRAY_SIZE);

	if (readTextFile(in_path, arr_actors)) {
		printf("[%s]\tSUCESSO: leitura bem sucedida.\n\n", in_path);
	} else {
		printf("ERRO: nao foi possível ler o arquivo.\n\n");
		return 1;
	}

	if (writeBinFile(out_path, arr_actors, ARRAY_SIZE)) {
		printf("[%s] -> [%s]\tSUCESSO: escrita bem sucedida.\n\n", in_path, out_path);
	} else {
		printf("ERRO: nao foi possível escrever o arquivo.\n\n");
		return 1;
	}

	free(arr_actors);


	return 0;
}
