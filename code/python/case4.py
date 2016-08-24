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

for line in inputdeck_lines:
	opt  = line.split()[0]
	if opt in "INT1":
		int1 = int(line.split('=')[1].split(';')[0])
		print "init1 : " + str(int1)
	elif opt in "REAL1":
		real1 = float(line.split('=')[1].split(';')[0])
		print "real1 : " + str(real1)
	elif opt in "LIST1":
		list1 = line.split('=')[1].split(';')[0]
		print "list1 : " + list1
	elif opt in "VECTOR1":
		vector1 = map(int,line.split("[")[1].split(']')[0].split())
		print "vector1 :" + str(vector1)
	else:
		print "error"
		sys.exit(1)	

f_inputdeck.close()
 




