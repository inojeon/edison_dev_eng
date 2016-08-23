## Python Code

```python
#!/usr/local/bin/python

import sys, os
import getopt
import math
import numpy as np

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

for line in inputdeck_lines:
      opt  = line.split()[0]
      if opt in "INT1":
            int1 = int(line.split('=')[1].split(';')[0])
            print "init1 : " + str(int1)
      elif opt in "REAL1":
            real1 = float(line.split('=')[1].split(';')[0])
            print "real1 : " + str(real1)
      else:
            print "Inputdeck value read error. your input key is " + str(opt)
            sys.exit(1)

f_inputdeck.close()

os.system("rm -rf result")
os.system("mkdir result")


f_out = open("result/result.oneD","w")

times = np.arange(-2.0*math.pi, 2.0*math.pi, 0.1)

f_out.write("#NumField: 1\n")
f_out.write("#LabelX: time, LabelY: a*sine(x+b) \n")
f_out.write("#Field1: a=%d b=%f,NumPoint:%i\n" % (int1, real1, len(times)))

for time in times :
      y = int1*math.sin(time+real1)
      f_out.write("%10.3f     %10.3f\n" % (time, y))

f_out.close()

```


####주요 코드 설명

입력 파일을 읽고 이를 각각의 변수로 저장하는 부분은 [Inputdeck 프로그래밍](../input/python_example3.md) 예제에서 가져왔다.

```Python
import sys, os
import getopt
import math
import numpy as np
...
```
- [os.system()](https://wikidocs.net/33), [sin()](https://docs.python.org/2/library/math.html), [arange()](http://docs.scipy.org/doc/numpy/reference/generated/numpy.arange.html)을 사용하기 위해 ```math```와 ```numpy```를 import 하였다.

```Python
...
os.system("rm -rf result")
os.system("mkdir result")
...

```
- 결과 데이터를 저장할 ```result```  폴더를 생성하는 부분이다.


```python
f_out = open("result/result.oneD","w")

times = np.arange(-2.0*math.pi, 2.0*math.pi, 0.1)
```
- result.oneD 파일을 result 폴더에 쓰기 모드로 오픈하였으며, 이를 f_out에 저장하였다.
- numpy에서 제공하는 [arange()](http://docs.scipy.org/doc/numpy/reference/generated/numpy.arange.html) 함수를 이용해 -2*pi 부터 2*pi까지 0.1 간격의 배열인 ```times```을 생성하였다.

```python

f_out.write("#NumField: 1\n")
f_out.write("#LabelX: time, LabelY: a*sine(x+b) \n")
f_out.write("#Field1: a=%d b=%f,NumPoint:%i\n" % (int1, real1, len(times)))

```
- oneD 파일의 헤더 부분의 내용을 입력해주는 부분이다. [oneD 데이터 구조](output/oneDplot.md)에 대한 자세한 설명은 해당 페이지 참조.
- 필드가 1개이며, x라벨이 time y라벨이 a*sine(x+b)이고 필드의 이름은 사용자가 입력한 a,b 값을 나타내고 있다.

```python
for time in times :
      y = int1*math.sin(time+real1)
      f_out.write("%10.3f     %10.3f\n" % (time, y))

f_out.close()
```
- for문을 이용해 앞서 생성한 ```times```의 배열 값을 하나씩 읽고 이를 이용하여 $$a*sin(t+b)$$ 에 대한 결과 y를 계산한다. 이후 x에 저장할 값인 time과 y에 저장할 값인 y를 각각 파일에 써준다.
- 이때 저장하는 데이터의 규칙은 exponential 형태로 총 10자리 소수점 아래로 3자리를 가지도록 저장한다. 
  

