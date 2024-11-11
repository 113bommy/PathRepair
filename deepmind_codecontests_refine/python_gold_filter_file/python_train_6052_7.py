import sys
# from prg import *
from math import *
from copy import copy
import pdb
import itertools
from pprint import pprint


ver = 0
hor = 0
s = input()

for i in s:
	if(i=='0'):
		if(ver==1):
			print(1,1)
			ver = 0
		else:
			print(3,1)
			ver = 1
	else:
		if(hor==1):
			print(1,1)
			hor = 0
		else:
			print(1,3)
			hor = 1
