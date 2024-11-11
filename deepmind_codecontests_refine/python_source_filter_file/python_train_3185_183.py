

"""  *** Author--Saket Saumya ***
            IIITM
"""

import math
import os
import random
import re
from sys import stdin, stdout
from collections import Counter
from itertools import permutations


def si():
	return str(stdin.readline())
def ii():
    return int(stdin.readline())
def mi():
    return map(int, stdin.readline().split())
def li():
    return list(mi())
def debug(x):
	return stdout.write(str(x))

a,b=mi()
c=0
while a<b:
	a=3*a
	b=2*b
	c+=1
#print(a,b)
print(c+1)

















