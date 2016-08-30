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




C나 FORTRAN으로 작성된 코드는 컴파일 과정을 통해 실행 파일을 만들어야 한다. 리눅스의 [gcc](http://ibabo.tistory.com/87) 명령어나 [gfortran](https://gcc.gnu.org/wiki/GFortranUsage) 명령어를 사용하면 된다. 

Python의 경우 Script를 실행하는 형태로 별다른 컴파일 과정이 필요 없다. 하지만 리눅스 명령어 [chmod](https://ko.wikipedia.org/wiki/Chmod) 명령어를 이용해 그룹과 일반 사용자에게 읽기와 실행 권한을 주어야 한다. 일반적으로 755 퍼미션을 주면 되며, ```run.py```가 실행 파일인 경우 ```chmod 755 run.py``` 를 리눅스 상에서 실행하면 된다.


[예제 파일 다운 받기](https://github.com/inojeon/edison_dev)