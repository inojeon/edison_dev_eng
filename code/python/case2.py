#!/usr/local/bin/python

import sys
import getopt
 
try:
	opts, args = getopt.getopt(sys.argv[1:],"i:m:" ,["inp=","mesh="])
except getopt.GetoptError as err:
	print str(err)
	sys.exit(1)

for opt,arg in opts:
	if  opt in ("-i", "--inp"):
		f_inputdeck = open(arg, "r")
	elif opt in ("-m", "--mesh"):
		f_inputmesh = open(arg, "r")


print "inputdeck file = " + f_inputdeck.name
inputdeck_lines = f_inputdeck.readlines()

print "inputmesh file = " + f_inputmesh.name
inputmesh_lines = f_inputmesh.readlines()


f_inputdeck.close()
f_inputmesh.close()




