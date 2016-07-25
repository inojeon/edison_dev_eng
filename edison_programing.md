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

본 예제는 EDISON 입력 형식을 맞춘 예제이며, 커맨드 옵션(포트 명)이 "-inp"인 입력 파일을 읽어와 path 정보를 출력하는 코드이다. 

EDISON 포털에서 앱 등록시 이와 관련된 정보를 입력해 주어야 한다. 


##### FORTRAN Code example

```fortran
      program sample1

      CHARACTER(len=16) :: cmd_option_name
      CHARACTER(len=512) :: inputdeck
      INTEGER :: num_of_args, i, io_status
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


