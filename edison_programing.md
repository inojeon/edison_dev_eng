# EDISON 입출력 프로그래밍 방법

EDISON 플랫폼을 활용하여 웹 기반 시뮬레이션 서비스를 하기 위해서는 EDISON에서 정의한 입출력 형식을 준수해야 한다. 
- 시뮬레이션 SW의 실행 방식은 **./[실행 파일 명] [커맨드 옵션] [인풋 파일의 절대 경로]** 형태로 실행 
  -  ex) ./a.out –inp /home/user1/data/input.dat
  - 소스코드에서 **[인풋 파일의 절대경로]** 처리를 위해 파일 경로 버퍼에 저장하는 경우, 버퍼 공간을 512byte 잡아야 함
- 결과 파일은 실행 파일 디렉토리에 result 폴더를 생성하여 그 안에 저장해야 함

다음과 같이 프로그래밍 된 시뮬레이션 SW는 EDISON 플랫폼에서 서비스 될 수 없다.
 - 입력 파일을 입력 받지 않고 특정 위치의 특정 이름인 입력 파일만 읽는 경우
 - 사용자 키 입력을 통해 입력 파일의 이름이나 위치를 입력 받는 경우
   - C언어의 **scanf()** 함수, python의 **input()** 함수 등을 통해 입력 파일 값을 받는 경우 
 - 결과 파일을 **result** 폴더가 아닌 다른 폴더에 결과 파일을 생성하는 경우

### 입력 프로그래밍

EDISON에서 시뮬레이션 SW 실행 시 1개 이상의 파일을 입력 받을 수 있고, 이를 구분하기 위해 각각 다른 커맨드 옵션(포트 명)을 통해 입력 파일을 받을 수 있도록 프로그래밍 되어야 한다. 

#### Case 1. 입력 파일이 1개인 경우  

본 예제는 실행 파일이 **a.out**이며, 커맨드 옵션(포트 명)이 "-inp"인 입력 파일을 읽어와 path 정보를 출력하는 코드이다.

 - 리눅스 상에서 실행 커맨드 ::  **./a.out -inp /home/user1/data/sample1.dat** 


EDISON 포털에서 앱 등록시 작성된 입력 포트 정보는 아래 그림과 같다.  


![입력 파일이 1개인 경우 입력포트 설정 예제](sample1.png)


##### FORTRAN Code example

```fortran
      program sample1

      CHARACTER(len=16) :: cmd_option_name
      CHARACTER(len=512) :: inputdeck
      INTEGER :: num_of_args, i
      LOGICAL :: args_error_flag = .false.

      num_of_args = iargc()

      do i=1, num_of_args, 2
            call getarg(i,cmd_option_name)

            if( cmd_option_name .eq. "-inp") then
                  call getarg(i+1,inputdeck)
            else
                  args_error_flag = .true.
                  write (*,*) "ERROR: INVALID COMAND OPTION: " ,
     +            cmd_option_name
            endif
      enddo

      if ( args_error_flag .eqv. .true. ) then
            write (*,*) "CHECK YOUR COMAND OPTION"
            stop
      endif

      write (*,*) "Input file path : ", inputdeck



      end program

```
######주요 변수 설명 
 - ```cmd_option_name``` : 커맨드 옵션(포트 명)을 저장하는 크기가 16인 character형 배열로 선언 하였다. 
 - ```inputdeck``` : 입력 파일의 path를 저장하는 배열로 크기는 512인 characcter형 배열을 선언 하였다.
 - ```num_of_args``` : 실행 시 같이 입력된 argument의 개수를 저장하는 변수 
 - ```args_error_flag = .false.``` : 커맨드 옵션(포트 명)이 잘못 입력된 경우, 이 변수의 값을 ```.true.```로 변경


######주요 코드 설명

```fortran
      ...
      num_of_args = iargc()
      ...
```
 - [iargc()](https://gcc.gnu.org/onlinedocs/gfortran/IARGC.html) 함수를 이용하여 입력된 argument의 개수를 num_of_args 변수에 저장 

```fortran
      ...
      do i=1, num_of_args, 2   
            call getarg(i,cmd_option_name)

            if( cmd_option_name .eq. "-inp") then
                  call getarg(i+1,inputdeck)
            else
                  args_error_flag = .true.
                  write (*,*) "ERROR: INVALID COMAND OPTION: " ,
     +            cmd_option_name
            endif
      enddo
      ...
```
- do loop를 이용해 num_of_args 개수 까지 i 값을 2씩 증가하면서 loop 문 수행
- [getarg()](https://gcc.gnu.org/onlinedocs/gfortran/GETARG.html#GETARG) 함수를 이용해 i번째 arument 값을 ```cmd_option_name``` 변수에 저장
- 저장한 ```cmd_option_name``` 값이 **-inp**와 같은지 확인하여 같으면, i+1번째 arument 값을 읽어서 ```inputdeck``` 배열에 저장
- ```cmd_option_name``` 값이 **-inp**와 다르면, ```args_error_flag``` 를 ```.false.```로 변경하고 잘못 입력한 커맨드 옵션을 출력

