# Gnuplot C example

이번 예제는 실행파일과 실행 파일을 동작시키는 bash 쉘 스크립트 파일 그리고 gnuplot의 PATH export 명령어를 저장하고 있는 ```simrc```파일이 필요하다. 실행 파일에 대한 c소스 코드 파일은 아래와 같다. 

### main.c 
```c
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
```
해당 코드를 다음과 같이 리눅스 명령어를 이용해 컴파일을 한다.

Gnu 컴파일러를 사용하는 경우는 다음과 같이 입력하며,
```
gcc main.c -o sinx -lm
```
인텔 컴파일러를 사용하는 경우는 다음과 같이 컴파일을 수행한다.
```
icc main.c -o sinx
```
정상적으로 컴파일이 완료가 되었다면, ```simx``` 실행파일이 생성된다.

추가로 아래와 같이 ```simrc``` 파일과 ```run.sh```파일을 만든다.

### simrc
```
export PATH=/SYSTEM/gnuplot-4.6.3/bin/bin:$PATH
```

### run.sh
```
#!/bin/bash

./sinx -inp $2

gnuplot plot.gnu

rm -f plot.gnu
mv result.png result/
mv result.oneD result/
```

작성이 완료된 이후 리눅스 soruce 명령어를 이용해 gnuplot의 PATH를 추가하고, 샘플 입력파일을 이용하여, 실행 스크립트를 실행한다. 

```
source simrc 
./run.sh -inp input.dat
```

###input.dat
```
INT1 = 42 ;
REAL1 = 0.2423 ;
```

이후 result 폴더에 결과 파일이 정상적으로 생성되는지 확인한다. 이번 예제에서는 ```result.oneD```, ```result.png```파일이 생성된다.

결과 파일이 정상적으로 나오는 것을 확인한 후, 실행에 필요한 파일들만 압축하여 sftp를 이용 자신에 PC에 저장한다.
 - zip, tar 등의 명령어를 사용하면 된다. 

```
zip test.zip a.sh sinx simrc
or
tar -cvf test.tar a.sh sinx simrc
```
