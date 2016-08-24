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
