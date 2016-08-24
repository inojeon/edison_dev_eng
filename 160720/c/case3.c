#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[])
{
	FILE *fp_inputdeck ;
	int count;
	char args_error_flag = 0;
	char buf_char[256];

	int int1;
	double real1;
	char list1;
	int vector1[3];	

	if (argc > 1) {
		for (count = 1; count < argc; count+=2) {
			if(!strcmp(argv[count],"-inp")) {
				printf("-inp : %s \n", argv[count+1]);
				fp_inputdeck = fopen(argv[count+1], "r");
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

	while(1)
	{
            fscanf(fp_inputdeck,"%s", buf_char);
		if(feof(fp_inputdeck))
			break;
		
		if(!strcmp(buf_char, "INT1")) {
			fscanf(fp_inputdeck, "%d", &int1);
		} else if (!strcmp(buf_char, "REAL1")) {
			fscanf(fp_inputdeck, "%lf", &real1);
		} else if (!strcmp(buf_char, "LIST")) {
                  fscanf(fp_inputdeck, "%s", &list1);
            } else if (!strcmp(buf_char, "VECTOR1")) {
			fscanf(fp_inputdeck, "%*s %d %d %d %*s", &vector1[0], &vector1[1], &vector1[2]);
		} else {
                  printf("Error Invalid value name :: %s\n", buf_char);
			exit(1);
		}
	}

	printf("int1: %d \n", int1);
	printf("real1: %f \n", real1);
	printf("list1: %c \n", list1);
	printf("vector1 =  %d %d %d \n",vector1[0], vector1[1], vector1[2]);


	fclose(fp_inputdeck);

	return 0;
}
