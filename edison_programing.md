# EDISON 입출력 프로그래밍 방법

EDISON 플랫폼을 통하여 웹기반 시뮬레이션을 제공하기 위해서는, 

개발자가 EDISON에서 제공하는 계산 자원 환경에 맞는 개발하거나 테스트하고, 관련 모든 정보를 스스로 업로드해야 한다. EDISON 서비스는 이에 관련한 모든 기능을 웹을 통하여 제공한다.

EDISON을 통하여 서비스를 하고자 하는 시뮬레이션 SW은 EDISON에서 정의한 입출력 형식을 준수해야 한다. EDISON은 임의의 다중 사용자들에게 계산 프로그램들을 서비스하며, 일련의 시스템적 프로그램 관리와 서비스 관리를 수행하기 때문에, 형식을 정확하게 따르지 않으면 서비스가 불가능하다.

## EDISON 시뮬레이션 SW 프로그래밍 개요
EDISON 시스템과 연동을 위해서는 몇 가지 지켜주어야 할 사항이 있다.

- 시뮬레이션 SW의 실행 방식은 **./[실행파일 명] [옵션] [인풋 파일]** 형태로 실행 되도록 해야 한다. 
  -  ex) ./a.out –inp input.dat
  - **[옵션]**은 꼭 설정 해주어야 한다.
  - 소스코드에서 **[인풋 파일]** 처리를 위해 파일 경로 버퍼에 저장하는 경우, 버퍼 공간을 512byte 정도로 넉넉하게 잡아주어야 한다. 
- 결과 파일은 실행파일 디렉토리에 result 폴더를 생성하여 그 안에 저장되어야 한다. 

### Case 1. 입력 파일이 1개인 경우  


```fortran
      program sample1

      CHARACTER(len=16) :: cmd_option_name , value_name , temp
      CHARACTER(len=512) :: inputdeck
      INTEGER :: num_of_args, i, io_status
      LOGICAL :: args_error_flag = .false.

      num_of_args = iargc()

      do i=1, num_of_args, 2
            call getarg(i,cmd_option_name)

            if( cmd_option_name .eq. "-inp") then
                  call getarg(i+1,inputdeck)
                  write (*,*)  inputdeck
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


