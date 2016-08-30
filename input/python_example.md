# Code example

### Case1.py
```Python
#!/usr/local/bin/python

import sys
import getopt

try:
      opts, args = getopt.getopt(sys.argv[1:],"i:" ,["inp="])
except getopt.GetoptError as err:
      print str(err)
      sys.exit(1)

for opt,arg in opts:
      if  opt in ("-i", "--inp"):
            f_inputdeck = open(arg, "r")

print "input file = " + f_inputdeck.name
inputdeck_lines = f_inputdeck.readlines()


f_inputdeck.close()
```


### 주요 코드 설명
```python
#!/usr/local/bin/python

import sys
import getopt

```
- ```#!``` 을 통해 이 스크립트를 실행시켜줄 파이썬 프로그램의 경로를 지정 [(참고링크)](http://blog.gaerae.com/2015/10/what-is-the-preferred-bash-shebang.html)
- 필요한 모듈을 불러온다
   - sys 모듈은 파이썬 인터프리터와 관련된 정보와 기능을 제공하는 모듈이며, 해당 스크립트로 넘어온 입력인자(argv)를 확인하기 위해 사용
   - getopt 입력인자를 보다 편리하기 처리하게 해주는 모듈 

```python
...

try:
      opts, args = getopt.getopt(sys.argv[1:],"i:" ,["inp="])
except getopt.GetoptError as err:
      print str(err)
      sys.exit(1)
...
```
- ```getopt.getopt()``` 함수를 이용해 입력 인자를 옵션과 옵션에 대한 추가 값으로 분류 해준다. 추가 옵션 값을 가지는 "-i", "--inp" 옵션을 받을 수 있으며, 이때 입력된 옵션 값은 ```opts```에 저장되고, 추가 옵션 값은 ```args```에 저장한다.
  - ```getopt.getopt(sys.argv[1:],"i:" ,["inp="])```에서 ```getopt.getopt()``` 함수의 첫 번째 인자는 입력되는 파라미터 문자열 입력 받는다. 기본적으로 실행 파일 이름을 제외한 문자열인 ```sys.argv[1:]``` 을 입력 받으며, 두 번째 인자는 입력 받을 단일 문자 옵션, 마지막 인자는 입력 받을 긴 문자 옵션이 입력된다. 
  - 옵션 뒤에 추가 옵션 값이 필요한 경우 단일 문자 옵션인 경우 옵션 명 뒤에 ```:```를 긴 문자 옵션인 경우 ```=```를 붙여 준다. 
  - ```./main.py --inp input.dat``` 로 실행 시 ```opts```에 옵션 명과 옵션 값이 저장된 튜플 형태의 배열인 ```[('--inp', 'input.dat')]```가 저장된다.
    - [튜플 자료형](https://wikidocs.net/15) 
  - [링크 : Python documentaion getopt](https://docs.python.org/2/library/getopt.html), [한글자료 getopt 함수 사용하기](http://kaspyx.kr/69) 
- 입력된 옵션 값 이외에 다른 옵션 값이 입력되는 경우 ```getopt.GetoptError``` 에러가 발생하며, 이에 대한 에러 메시지는 ```err```에 저장된다. 
  - ```try ... except ``` 구문을 이용해 잘못된 옵션 값이 입력된 경우 이에 대한 에러 값을 출력하고 프로그램을 종료한다.

```python
...
for opt,arg in opts:
      if  opt in ("-i", "--inp"):
            f_inputdeck = open(arg, "r")
...
```
- ```opts```에 저장된  옵션 명을 ```opt```에 옵션 값을 ```arg```에 저장하고 이를 체크하는 부분이다.
- 입력된 옵션 명이 ```-i``` 또는 ```--inp```이면 이때의 옵션 값을 입력 파일의 경로라 판단하여 [open()](https://wikidocs.net/26)함수를 통해 파일을 열고 이에 대한 정보를 ```f_inputdeck``` 이라는 파일 객체에 저장한다.

``` python
...
print "input file = " + f_inputdeck.name
inputdeck_lines = f_inputdeck.readlines()


f_inputdeck.close()

```
- 정상적으로 입력된 파일 경로를 출력해주고, 입력 받은 파일을 닫고 프로그램을 종료한다.
