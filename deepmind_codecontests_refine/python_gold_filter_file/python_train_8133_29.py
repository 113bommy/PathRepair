# ANSHUL GAUTAM
# IIIT-D

from math import *
from copy import *
from string import *
from random import *					# alpha = ascii_lowercase
from sys import stdin
from itertools import *
from collections import Counter			# z = dict(Counter(l))

N,K = map(int, stdin.readline().rstrip().split())
ans = 3*N
if(K == 1 or K == N):
	ans = 3*N
else:
	ans += min(N-K,K-1)
print(ans)