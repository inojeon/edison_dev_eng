#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.140592
#define SIZE 128

int main (int argc, char* argv[])
{
	FILE *fp_inputdeck, *fp_out, *fp_gnuplot;
	int count;
	char args_error_flag = 0;
	char buf_char[256];

	int int1;
	double real1;

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
                  fscanf(fp_inputdeck, "%*s %d %*s", &int1);
            } else if (!strcmp(buf_char, "REAL1")) {
                  fscanf(fp_inputdeck, "%*s %lf %*s", &real1);		
		} else {
                  printf("Error Invalid value name :: %s\n", buf_char);
			exit(1);
		}
	}

	printf("int1: %d \n", int1);
	printf("real1: %f \n", real1);

	system("rm -rf result");
	system("mkdir result");

      fp_out = fopen("result.oneD", "w");

      fprintf(fp_out,"#NumField: 1\n");
      fprintf(fp_out,"#LabelX: time, LabelY: a*sine(x+b) \n");
      fprintf(fp_out,"#Field1: a=%d b=%f,NumPoint:%d\n", int1, real1, SIZE);
	
	double x,y;
	int t;
	for(t=0; t< SIZE; t++) {
		x = (4*PI * t )/SIZE -2*PI;
		y = int1*sin( x - real1 );
		fprintf(fp_out,"%e %e\n",x, y);
	} 

	fclose(fp_inputdeck);
	
	fp_gnuplot = fopen("plot.gnu","w");

	fprintf(fp_gnuplot,"set term png\n");
	fprintf(fp_gnuplot,"set output \"result.png\"\n");
	fprintf(fp_gnuplot,"set xrange[-6:6]\n");
      fprintf(fp_gnuplot,"set yrange[-50:50]\n");
	fprintf(fp_gnuplot,"plot 'result.oneD' using 1:2 with lines\n");
	fclose(fp_gnuplot);

	return 0;
}
