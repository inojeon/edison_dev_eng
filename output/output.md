# 출력 프로그래밍

EDISON에서 데이터를 출력하기 위해서는 실행파일에서 result 폴더를 생성하고 결과 파일을 result 폴더 안에 생성해야 한다. 이를 위해 코드 상에서 리눅스 쉘 명령어를 사용해야 한다.


### C 
 C 언어의 경우 ``` #include <stdlib.h>``` 헤더를 선언하고 ``` int system (const char * string);``` 함수를 이용하면 되며, result 폴더를 생성하는 예제는 아래와 같다. 
 
 ```C
 #include <stdlib.h>
 
 int main (int argc, char* argv[])
 {
 ...
   system("rm -rf result");
   system("mkdir result");
 ...
   return 0
 }
 
 ```


### FORTRAN 

 FORTRAN의 경우 ``` CALL SYSTEM(COMMAND [, STATUS]) ```를 이용하면 되며, result 폴더를 생성하는 예제는 아래와 같다. 
 
 ```fortran
      program sample
      
      ...
      CALL SYSTEM("rm -rf result")
      CALL SYSTEM("mkdir result")
      ...

      end program      
 
 ```
 
 ### Python
 Python의 경우 ``` import os ``` 를 선언하고 ``` os.system (const char * string);``` 함수를 이용하면 되며, result 폴더를 생성하는 예제는 아래와 같다. 
 
 ```python
 import os
 
 ...
   os.system("rm -rf result");
   os.system("mkdir result");
 ...
 
 
 ```

 
 