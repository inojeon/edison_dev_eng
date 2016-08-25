# C Example

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.140592
#define SIZE 128

int main (int argc, char* argv[])
{
      FILE *fp_inputdeck, *fp_out;
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

      fp_out = fopen("result/result.oneD", "w");

      fprintf(fp_out,"#NumField: 1\n");
      fprintf(fp_out,"#LabelX: time, LabelY: a*sine(x+b) \n");
      fprintf(fp_out,"#Field1: a=%d b=%f,NumPoint:%d\n", int1, real1, SIZE);
      double x,y;
      int t;
      for(t=0; t< SIZE; t++) {
            x = (4*PI * t )/SIZE -2*PI;
            y = int1*sin( x - real1 );
            fprintf(fp_out,"%10.3f  %10.3f\n",x, y);
      }

      fclose(fp_inputdeck);

      return 0;
}
```

####주요 코드 설명

입력 파일을 읽고 이를 각각의 변수로 저장하는 부분은 [Inputdeck 프로그래밍](../input/c_example3.md) 예제에서 가져왔다.

```c
...
#include <math.h>

#define PI 3.140592
#define SIZE 128
```

- sin() 함수를 이용하기 위해 ```math.h```를 include 하였으며, 필요한 상수들을 define하였다.

```c
      ...
      system("rm -rf result");
      system("mkdir result");
      
      fp_out = fopen("result/result.oneD", "w");
      ...
```
- 결과 데이터를 저장할 ```result```  폴더를 생성하는 부분이며, result 폴더안에 ```result.oneD``` 파일을 생성하고 쓰기모드로 오픈하여 fp_out 파일포인터에 넣어주었다.

```c
      fprintf(fp_out,"#NumField: 1\n");
      fprintf(fp_out,"#LabelX: time, LabelY: a*sine(x+b) \n");
      fprintf(fp_out,"#Field1: a=%d b=%f,NumPoint:%d\n", int1, real1, SIZE);

```
- oneD 파일의 헤더 부분의 내용을 입력해주는 부분이다. [oneD 데이터 구조](output/oneDplot.md)에 대한 자세한 설명은 해당 페이지 참조.
- 필드가 1개이며, x라벨이 time y라벨이 a*sine(x+b)이고 필드의 이름은 사용자가 입력한 a,b 값을 나타내고 있다.

```c
      double x,y;
      int t;
      for(t=0; t< SIZE; t++) {
            x = (4*PI * t )/SIZE -2*PI;
            y = int1*sin( x - real1 );
            fprintf(fp_out,"%10.3f  %10.3f\n",x, y);
      }

      fclose(fp_inputdeck);
```
 - t=0 부터 SIZE 까지 for문을 수행한다. 있대 $$-2*pi$$에서 $$2*pi$$ 까지 SIZE등분으로 일정하게 나눈 값을 x에 저장하고, 이 x값에 대한 $$a*sin(t+b)$$ 결과 값을 y에 저장한 뒤 각각 파일에 써준다.
- 이때 저장하는 데이터의 규칙은 10진수 형태로 총 10자리를 가지고, 소수점 아래로는 3자리를 가지도록 저장한다.






