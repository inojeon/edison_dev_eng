# C example


# inputdeck_fortran


#### Case 3.1. Inputdeck case study 1

다음과 같이 정수형 변수 1개, 실수형 변수 1개, 리스트형 변수 1개, 3차원 벡터 1개를 받는 Inputdeck를 생성하였다. 

![case1](case1.png)

Inputdeck에서 필요한 정보들만 담기 위해 Inputdeck 설정 값을 다음과 같이 정하였다. 

| INPUTDECK key | value |
| -- | -- |
| value delimiter | SPACE |
| line delimiter | NULL |
| Vector vracket | SQUARE_SPACE |
| Vector delimiter | SPACE |

이렇게 설정되어 생성된 입력 파일은 다음과 같다.

```
INT1 42
REAL1 42.112
LIST1 a
VECTOR1 [ 1 0 0 ]
```



#####C code example
```c
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char* argv[])
{
      FILE *fp_inputdeck ;
      int count;
      char args_error_flag = 0;
      char buf_char[256];

      int int1;
      double real1;
      char list1;
      int vector[3];

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
                  fscanf(fp_inputdeck, "%*s %d %d %d %*s", &vector[0], &vector[1], &vector[2]);
            } else {
                  printf("%s\n", buf_char);
                  printf("Inputdeck value read error\n");
                  exit(1);
            }

      printf("int1: %d \n", int1);
      printf("real1: %f \n", real1);
      printf("list1: %c \n", list);
      printf("vector =  %d %d %d \n",vector[0], vector[1], vector[2]);


      fclose(fp_inputdeck);

      return 0;
}



```


######주요 변수 설명 
- ```int1```, ```real1```, ```list1```, ```vector[3]``` : Inputdeck 파일에서 각각의 변수 값를 저장하는 변수
- ```buf_char[256]``` : 입력된 인풋덱 파일에서 변수 이름을 저장하는 배열

######주요 코드 설명

```c
...



...
```

```

```


1. 장치 번호 1번을 사용해 앞서 open한 입력 파일의 한 줄을 [read()](https://docs.oracle.com/cd/E19957-01/805-4939/6j4m0vnat/index.html)를 사용해 읽는다. 이때 입력 파일의 첫 번째 문자열인 변수 이름을 ```value_name```에 저장한다. 
- 여기서 파일을 끝까지 다 읽은 경우 파일 read를 하게 되면 ```io``` 값이 0보다 작게 된다. 이를 통해 파일을 끝까지 다 읽었는지 여부를 판단하고 파일을 끝까지 다 읽은 경우 loop문을 빠저나온다.
2. [read()](https://docs.oracle.com/cd/E19957-01/805-4939/6j4m0vnat/index.html)함수를 이용해 이미 앞에서 읽었던 파일 라인의 변수의 값을 다시 읽기 위해서, [backspace()](https://docs.oracle.com/cd/E19957-01/805-4939/6j4m0vn7j/index.html)를 이용 방금 읽었던 파일 라인을 다시 읽을 수 있도록 파일 포인터를 이동한다.
3. 입력 파일에서 읽은 변수 이름을 확인하여 저장 함. 벡터 변수의 경우 변수 이름과 값 사이에 있는 ```[``` 문자를 ```tempchar``` 변수에 저장하고, ```VEC(1~3)``` 에 각각의 벡터 원소들을 저장한다.
4. 원하지 않은 변수 값이 입력되는 경우 이에 대한 에러 메시지를 표시하고 프로그램을 종료




#### Case 3.2. Inputdeck case study 2

다음과 같이 정수형 변수 1개, 실수형 변수 1개, 리스트형 변수 1개, 3차원 벡터 1개를 받는 Inputdeck를 생성하였다. 

![case2](case3_3.jpg)

Inputdeck에서 필요한 정보들만 담기 위해 Inputdeck 설정 값을 다음과 같이 정하였다. 

| INPUTDECK key | value |
| -- | -- |
| value delimiter | EQUAL |
| line delimiter | SEMICOLON |
| Vector vracket | SQUARE_SPACE |
| Vector delimiter | SPACE |

이렇게 설정되어 생성된 인풋 파일은 다음과 같다.

```
INT1 = 42 ;
REAL1 = 42.112 ;
LIST = a ;
VECTOR1 = [ 1 0 0 ] ;
```



#####FORTRAN code example
위 케이스에서 생성된 입력 파일을 읽어와 같은 이름의 변수를 생성해 저장하는 코드이다. case 1의 코드와 크게 다르지 않으며, ```tempchar``` 변수를 이용해 변수 이름과 변수 값 사이에 있는 ```=``` 을 처리하는 부분을 추가하였다. 

```fortran
      program sample

      CHARACTER(len=16) :: cmd_option_name , value_name
      CHARACTER(len=512) :: inputdeck
      INTEGER :: num_of_args, i, io_status
      LOGICAL :: args_error_flag = .false.

      INTEGER INT1
      DOUBLE PRECISION REAL1
      CHARACTER LIST, tempchar
      INTEGER :: VEC(3)

      num_of_args = iargc()

      do i=1, num_of_args, 2
            call getarg(i,cmd_option_name)

            if( cmd_option_name .eq. "-inp") then
                  call getarg(i+1,inputdeck)
                  WRITE (*,*)  trim(inputdeck)
            else
                  args_error_flag = .true.
                  WRITE (*,*) "ERROR: INVALID COMAND OPTION: " ,
     +            cmd_option_name
            endif
      enddo

      if ( args_error_flag .eqv. .true. ) then
            WRITE(*,*) "CHECK YOUR COMAND OPTION"
            stop
      endif

      open(1,file=trim(inputdeck),iostat=io_status, status='old')
      if (io_status /= 0) then
            write(*,*) 'File open error'
            stop
      end if

      do
            READ(1,*, IOSTAT=io) value_name
            if ( io < 0) then
                  WRITE(*,*) "Inputdeck file read end"
                  EXIT
            end if

            BACKSPACE (1)

            if ( value_name .eq. "INT1") then
                  READ(1,*) value_name, tempchar, INT1
                  WRITE(*,*) "INT1 = ", INT1
            else if ( value_name .eq. "REAL1") then
                  READ(1,*) value_name, tempchar, REAL1
                  WRITE(*,*) "REAL1 = ", REAL1
            else  if ( value_name .eq. "LIST") then
                  read(1,*) value_name, tempchar, LIST
                  write(*,*) "list = ", LIST
            else  if ( value_name .eq. "VEC") then
                  read(1,*) value_name, tempchar, tempchar, VEC(1),
     + VEC(2), VEC(3)
                  write(*,*) "Vector = ", VEC(1), VEC(2), VEC(3)
            else
                  WRITE(*,*) "Inputdeck value read error"
                  stop
            endif
      end do



      CLOSE(1)


      end program

```
