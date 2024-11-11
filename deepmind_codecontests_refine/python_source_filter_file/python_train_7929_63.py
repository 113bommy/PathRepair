# ANSHUL GAUTAM
# IIIT-D

from math import *
from copy import *
from string import *				# alpha = ascii_lowercase
from random import *
from sys import stdin
from sys import maxsize
from operator import *				# d = sorted(d.items(), key=itemgetter(1))
from itertools import *
from collections import Counter		# d = dict(Counter(l))

'''
1
20
2
10 20
'''

N1 = int(stdin.readline())
a = list(map(int, stdin.readline().rstrip().split()))
N2 = int(stdin.readline())
b = list(map(int, stdin.readline().rstrip().split()))

f = "a"
for i in range(N1):
	if(f == "b"):
		break
	for j in range(N2):
		s = a[i] + b[j]
		if(s not in a and s not in b):
			print(a[i],b[i])
			f = "b"
			break