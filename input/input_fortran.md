# FORTRAN Code example


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
 - ```cmd_option_name``` : 커맨드 옵션(포트 명)을 저장하는 크기가 16인 character형 배열로 선언
 - ```inputdeck``` : 입력 파일의 path를 저장하는 배열로 크기는 512인 characcter형 배열을 선언
 - ```num_of_args``` : 실행 시 같이 입력된 argument의 개수를 저장하는 변수 
 - ```args_error_flag = .false.``` : 커맨드 옵션(포트 명)이 잘못 입력된 경우, 이 변수의 값을 ```.true.```로 변경


######주요 코드 설명

```fortran
      ...
[1]   num_of_args = iargc()
      ...
```
 1. [iargc()](https://gcc.gnu.org/onlinedocs/gfortran/IARGC.html) 함수를 이용하여 입력된 argument의 개수를 num_of_args 변수에 저장 

```fortran
      ...
[1]   do i=1, num_of_args, 2   
[2]         call getarg(i,cmd_option_name)

[3]         if( cmd_option_name .eq. "-inp") then
                  call getarg(i+1,inputdeck)
[4]         else
                  args_error_flag = .true.
                  write (*,*) "ERROR: INVALID COMAND OPTION: " ,
     +            cmd_option_name
            endif
      enddo
      ...
```
1. do loop를 이용해 num_of_args 개수 까지 i 값을 2씩 증가하면서 loop 문 수행
  - 예제에서 [iargc()](https://gcc.gnu.org/onlinedocs/gfortran/IARGC.html) 함수로 받은 값이 2 이므로 loop문이 한번만 수행 됨 
2. [getarg()](https://gcc.gnu.org/onlinedocs/gfortran/GETARG.html#GETARG) 함수를 이용해 i번째 arument 값을 ```cmd_option_name``` 변수에 저장
3. 저장한 ```cmd_option_name``` 값이 **-inp**와 같은지 확인하여 같으면, i+1번째 arument 값을 읽어서 ```inputdeck``` 배열에 저장
 - 커맨드 옵션을 ```-inp```가 아닌 다른 옵션 명으로 설정 하고 싶다면, 이 부분을 수정하면 된다.
4. ```cmd_option_name``` 값이 **-inp**와 다르면, ```args_error_flag``` 를 ```.false.```로 변경하고 잘못 입력한 커맨드 옵션을 출력

```fortran
      ...
[1]   if ( args_error_flag .eqv. .true. ) then
            write (*,*) "CHECK YOUR COMAND OPTION"
            stop
      endif
      ...
```

1. 커맨드 옵션이 잘못 입력 되었는지 확인하고. 잘못 입력 되었을 경우 프로그램 종료

