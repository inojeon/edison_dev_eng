# ImageViewer 사용하기


##Gnuplot 

C 나 Fortran을 이용하여 그림 파일을 생성 시 Gnuplot를 사용하면 쉽게 그림으로 된 그래프를 그릴 수 있다. 

EDISON Bulb 머신에서 Gnuplot를 사용하기 위해서는 Gnuplot 명령어의 path를 잡아주어야 한다. 

``` 
 export PATH=/SYSTEM/gnuplot-4.6.3/bin/bin:$PATH
```
리눅스 ssh 상에서 위에 커맨드를 입력하면 gnuplot을 사용할 수 있으며, 코드안에서 system 명령어를 이용해 gnuplot에서 제공하는 명령어를 사용하면 된다. 

export가 필요한 실행 파일의 경우 export 커멘드 라인을 ```simrc```라는 파일을 만들어  해당 내용을 넣어준다.


