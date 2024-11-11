from functools import reduce
from operator import *
from math import *
from sys import *
setrecursionlimit(10**7)
RI=lambda: list(map(int,input().split()))
RS=lambda: input().rstrip().split()
#################################################
a,b,n=RI()
for i in range(9):
	if (a*10+i)%b==0:
		print(str(a*10+i)+'0'*(n-1))
		exit(0)
print(-1)
