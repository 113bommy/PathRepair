import sys
import math
import os
from collections import Counter
# To store no of test cases here (2).
#t=int(sys.stdin.readline()) #
# To store input here (0 1 1)  and (0 1 2).
a_1 = list(sys.stdin.readline())

a_2 = a_1.copy()

setes = Counter(a_1)

if setes['0']==0:
	print(''.join(a_1[:-2]))
else:
	for x in a_1:
		if x == '0':
			a_2.remove(x)
			break
	print(''.join(a_2))