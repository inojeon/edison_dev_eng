# Code example

```Python
#!/usr/local/bin/python

import sys
import getopt

def main():
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
      return

if __name__ == '__main__':
      main()



```


### 주요 코드 설명
```python
#!/usr/local/bin/python

import sys
import getopt

```
- ```#!``` 을 통해 이 스크립트를 실행시켜줄 파이썬 프로그램의 경로를 지정
- 필요한 모듈을 불러온다
   - sys 모듈은 파이썬 인터프리터와 관련된 정보와 기능을 제공하는 모듈이며, main 함수의