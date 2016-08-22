# 입력 프로그래밍

### 입력 프로그래밍

EDISON에서 시뮬레이션 SW 실행 시 1개 이상의 파일을 입력 받을 수 있고, 이를 구분하기 위해 각각 다른 커맨드 옵션(포트 명)을 통해 입력 파일을 받을 수 있도록 프로그래밍 되어야 한다. 

C나 FORTRAN으로 작성된 코드는 컴파일 과정을 통해 실행파일을 만들어야 한다. 리눅스의 [gcc](http://ibabo.tistory.com/87) 명령어나 [gfortran](https://gcc.gnu.org/wiki/GFortranUsage) 명령어를 사용하면 된다. 

Python의 경우 Script를 실행하는 형태로 별다른 컴파일 과정이 필요 없다. 하지만 리눅스 명령어 [chmod](https://ko.wikipedia.org/wiki/Chmod) 명령어를 이용해 그룹과 일반 사용자에게 읽기와 실행 권한을 주어야 한다. 일반적으로 755 퍼미션을 주면 되며, ```run.py```가 실행 파일인 경우 ```chmod 755 run.py``` 를 리눅스 상에서 실행하면 된다.

