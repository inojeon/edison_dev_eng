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
 




