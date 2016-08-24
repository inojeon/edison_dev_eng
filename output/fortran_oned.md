# Fortran Example

```fortran
      program sample

      CHARACTER(len=8) :: cmd_option_name , value_name
      CHARACTER(len=256) :: inputdeck
      INTEGER :: num_of_args, i, io_status, t
      LOGICAL :: args_error_flag = .false.

      INTEGER INT1
      DOUBLE PRECISION REAL1
      CHARACTER LIST, tempchar
      INTEGER :: VEC(3)

      DOUBLE PRECISION x, y

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
            else
                  WRITE(*,*) "Inputdeck value read error"
                  stop
            endif
      end do
      
      CALL SYSTEM("rm -rf result")
      CALL SYSTEM("mkdir result")

      open(2,file="result/result.oneD")
      write(2,*)"#NumField: 1"
      write(2,*)"#LabelX: time, LabelY: a*sine(x+b)"
      write(2,'(a11,i3,a3,f7.3,a13)') "#Field1: a=",INT1," b=",REAL1,
     +",NumPoint:128"

      PI = 3.140592

      do t=1, 129, 1
            x = (4*PI * t )/128 -2*PI
            y = INT1*sin( x - REAL1 )
            write(2,'(F10.3, F10.3)') x, y
      enddo

      CLOSE(2)

      CLOSE(1)


      end program
```
####주요 코드 설명

입력 파일을 읽고 이를 각각의 변수로 저장하는 부분은 [Inputdeck 프로그래밍](../input/fortran_example3.md) 예제에서 가져왔다.

코드 앞부분에서 oneD 데이터 생성에 필요한 변수를 ``` INTEGER :: t``` ```DOUBLE PRECISION x, y``` 를 선언 하였다.


```fortran
      CALL SYSTEM("rm -rf result")
      CALL SYSTEM("mkdir result")

      open(2,file="result/result.oneD")
```

- 결과 데이터를 저장할 ```result```  폴더를 생성하는 부분이며, result 폴더안에 ```result.oneD``` 파일을 생성하고 쓰기모드로 오픈하였다.

```fortran
      write(2,*)"#NumField: 1"
      write(2,*)"#LabelX: time, LabelY: a*sine(x+b)"
      write(2,'(a11,i3,a3,f7.3,a13)') "#Field1: a=",INT1," b=",REAL1,
     +",NumPoint:128"

```
- oneD 파일의 헤더 부분의 내용을 입력해주는 부분이다. [oneD 데이터 구조](output/oneDplot.md)에 대한 자세한 설명은 해당 페이지 참조.
- 필드가 1개이며, x라벨이 time y라벨이 a*sine(x+b)이고 필드의 이름은 사용자가 입력한 a,b 값을 나타내고 있다.

```fortran
      PI = 3.140592

      do t=1, 129, 1
            x = (4*PI * t )/128 -2*PI
            y = INT1*sin( x - REAL1 )
            write(2,'(F10.3, F10.3)') x, y
      enddo
```
 - PI값을 정의하고, t=1 부터 129 까지 for문을 수행한다. 있대 $$-2*pi$$에서 $$2*pi$$ 까지 128등분으로 일정하게 나눈 값을 x에 저장하고, 이 x값에 대한 $$a*sin(t+b)$$ 결과 값을 y에 저장한 뒤 각각 파일에 써준다.
- 이때 저장하는 데이터의 규칙은 10진수 형태로 총 10자리를 가지고, 소수점 아래로는 3자리를 가지도록 저장한다.


[예제 다운 받기](../code/fortran/sample5.f)






