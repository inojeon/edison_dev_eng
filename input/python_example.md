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