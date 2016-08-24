#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[])
{
	FILE *fp_inputdeck, *fp_mesh ;
	int count;
	char args_error_flag = 0;

	if (argc > 1) {
		for (count = 1; count < argc; count+=2) {
			if(!strcmp(argv[count],"-inp")) {
				printf("-inp : %s \n", argv[count+1]);
				fp_inputdeck = fopen(argv[count+1], "r");
			} else if(!strcmp(argv[count],"-mesh")) {
				printf("-mesh : %s \n", argv[count+1]);
				fp_mesh = fopen(argv[count+1], "r");
			} else {
				printf("Invalid command option: %s\n", argv[count] );
				args_error_flag = 1;
			};
		}
		if(args_error_flag == 1) {
			printf("Check your comand option\n");
			exit(1);
		}
	} else {
		printf("Invalid arguments number.\n");
		exit(1);
	}
	if (fp_inputdeck == NULL) { 
		printf("Error opening fp_inputdeck file \n");
		exit(1);
	}
	if (fp_mesh == NULL) { 
		printf("Error opening mesh file \n");
		exit(1);
	}


	fclose(fp_inputdeck);
	fclose(fp_mesh);

	return 0;
}
