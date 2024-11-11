from functools import reduce
import math

nk=input().split()
n=int(nk[0])
k=int(nk[1])
L=list(map(int,input().split()))
s=reduce(lambda x,y:x+y,L)
if(round(s)==k):
	print(0)
else:
	z=2*n*k-2*s-n
	print(max(0,z))