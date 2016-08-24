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
	if opt in "int1":
		int1 = int(line.split('=')[1].split(';')[0])
		print "init1 : " + str(int1)
	elif opt in "real1":
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
	f_out.write("%10.3f	%10.3f\n" % (time, y))

f_out.close()


