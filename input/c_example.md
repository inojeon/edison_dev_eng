# c example


```c
#include <stdio.h>
#include <stdlib.h>


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
```


####주요 변수 설명 
 - ```*fp_inputdeck, *fp_mesh``` : 파일을 가르키는 파일포인터 변수 선언
 - ```args_error_flag = 0``` : 커맨드 옵션(포트 명)이 잘못 입력된 경우, 이 변수의 값을 ```1```로 변경


####주요 코드 설명

```c
      ...
[1]   if (argc > 1) {
[2]         for (count = 1; count < argc; count+=2) {
[3]               if(!strcmp(argv[count],"-inp")) {
                        printf("-inp : %s \n", argv[count+1]);
[4]                     fp_inputdeck = fopen(argv[count+1], "r");
[3]               } else if(!strcmp(argv[count],"-mesh")) {
                        printf("-mesh : %s \n", argv[count+1]);
[4]                     fp_mesh = fopen(argv[count+1], "r");
[5]               } else {
                        printf("Invalid command option: %s\n", argv[count] );
                        args_error_flag = 1;
                  };
            }
            if(args_error_flag == 1) {
                  printf("Check your comand option\n");
                  exit(1);
            }
[7]   } else {
            printf("Invalid arguments number.\n");
            exit(1);
      }
[8]   if (fp_inputdeck == NULL) {
            printf("Error opening fp_inputdeck file \n");
            exit(1);
      }
[8]   if (fp_mesh == NULL) {
            printf("Error opening mesh file \n");
            exit(1);
      }


[9]   fclose(fp_inputdeck);
      fclose(fp_mesh);

      ...
```
1. 프로그램 실행 시 ```argc``` 값을 확인하여, 커맨드 옵션과 실행 파일 경로가 입력되어 있는지 확인하고, 정상적으로 입력이 되지 않은 경우 에러 메시지와 함께 프로그램 종료
 - 프로그램 실행 시 옵션을 하나도 입력하지 않으면 ```argc``` 값은 1이다. 따라서 1 이상 값이 입력이 되었는지 확인한다.
2. ```for```문을 이용해 ```argc``` 개수 까지 ```count``` 값을 2씩 증가하면서 ```for``` 문 수행
 -  예제에서 ```argc``` 값이 5이고, 초기 ```count```값이 1 이므로 ```for```문이 두번 수행 됨
3. [strcmp()](http://www.cplusplus.com/reference/cstring/strcmp/) 함수를 이용해 입력된 커맨드 옵션과 ```"-inp"``` 값과 ```-mesh``` 값을 비교해 원하는 옵션 값이 입력 되었는지 확인한다.
 - 비교하는 문자열이 일치하는 경우 [strcmp()](http://www.cplusplus.com/reference/cstring/strcmp/) 는 0 값을 리턴한다. 따라서 ```!```연산자를 이용해 일치하는 경우 조건문이 참이 되도록 하였다.
 - 커맨드 옵션을 ```-inp```와 ```-mesh```가 아닌 다른 옵션 명으로 설정 하고 싶다면, 이 부분을 수정하면 된다.  
4. [fopen()](http://www.cplusplus.com/reference/cstdio/fopen/?kw=fopen) 함수를 이용해 ```argv[count+1]```에 저장되어 있는 경로의 실행 파일을 읽기 전용(```"r"``` 옵션 사용)으로 연다.
 - 파일 포인터를 반환하여 ```*fp_inputdeck```과 ```*fp_mesh``` 파일포인터에 각각 저장한다.
5. 커맨드 옵션이 잘못 입력된 경우 에러 메시지를 표시하고 ```args_error_flag``` 값을 1로 변경하고 잘못 입력한 커맨드 옵션을 출력
6. ```args_error_flag``` 가 1인 경우 (커맨드 옵션이 잘못 입력 되었을 경우) 프로그램 종료 한다.
7. 파일 포인터가 정상적으로 반환되지 않는 경우 ```NULL``` 값을 리턴하고, 파일 포인터 값이 ```NULL```인 경우 에러 매시지를 표시하고 프로그램을 종료한다.
8. [fclose()](http://www.cplusplus.com/reference/cstdio/fclose/?kw=fclose) 함수를 이용해 파일 포인터의 연결을 끊는다.

