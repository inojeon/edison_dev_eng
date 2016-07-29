# c Code example


```c
int main (int argc, char* argv[])
{
      FILE *inputdeck;
      int count;
      char args_error_flag = 0;

      if (argc > 1) {
            for (count = 1; count < argc; count+=2) {
                  if(!strcmp(argv[count],"-inp")) {
                        printf("-inp : %s \n", argv[count+1]);
                        inputdeck = fopen(argv[count+1], "r");
                        if (inputdeck == NULL) {
                              printf("Error opening file \n");
                              exit(1);
                        }
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
      }



      fclose(inputdeck);

      return 0;
}
```
######주요 변수 설명 
 - ```*inputdeck``` : 파일을 가르키는 파일포인터 변수 선언
 - ```args_error_flag = 0``` : 커맨드 옵션(포트 명)이 잘못 입력된 경우, 이 변수의 값을 ```1```로 변경


######주요 코드 설명

```c
      ...
[1]   if (argc > 1) {
[2]         for (count = 1; count < argc; count+=2) {
[3]               if(!strcmp(argv[count],"-inp")) {
                        printf("-inp : %s \n", argv[count+1]);
[4]                     inputdeck = fopen(argv[count+1], "r");
[6]                        if (inputdeck == NULL) {
                              printf("Error opening file \n");
                              exit(1);
                        }
[6]               } else {
                        printf("Invalid command option: %s\n", argv[count] );
                        args_error_flag = 1;
                  };
            }
[7]         if(args_error_flag == 1) {
                  printf("Check your comand option\n");
                  exit(1);
            }
      } else {
            printf("Invalid arguments number.\n");
            exit(1);
      }


[9]   fclose(inputdeck);
      ...
```
1. 프로그램 실행 시 ```argc``` 값을 확인하여, 커맨드 옵션과 실행 파일 경로가 입력되어 있는지 확인하고, 정상적으로 입력이 되지 않은 경우 에러 메시지와 함께 프로그램 종료
 - 프로그램 실행 시 옵션을 하나도 입력하지 않으면 ```argc``` 값은 1이다. 따라서 1 이상 값이 입력이 되었는지 확인한다.
2. ```for```문을 이용해 ```argc``` 개수 까지 ```count``` 값을 2씩 증가하면서 ```for``` 문 수행
 -  예제에서 ```argc``` 값이 3이고, ```count```값이 1 이므로 ```for```문이 한번만 수행 됨
3. [strcmp()](http://www.cplusplus.com/reference/cstring/strcmp/) 함수를 이용해 



