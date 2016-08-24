      program sample

      CHARACTER(len=8) :: cmd_option_name
      CHARACTER(len=256) :: inputdeck, inputmesh
      INTEGER :: num_of_args, i
      LOGICAL :: args_error_flag = .false.

      num_of_args = iargc()

      do i=1, num_of_args, 2
            call getarg(i,cmd_option_name)

            if( cmd_option_name .eq. "-inp") then
                  call getarg(i+1,inputdeck)
            else if ( cmd_option_name .eq. "-mesh") then
                  call getarg(i+1,inputmesh)
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

      write (*,*) "Input file path : ", inputdeck
        
      inputdeck=trim(inputdeck)
      inputmesh=trim(inputmesh)

      write (*,*) "Input file path : ", inputdeck
      write (*,*) "Input file path : ", inputmesh


      end program
