import sys
import os
from math import*
input=sys.stdin.buffer.readline

n,a,b,c=map(int,input().split())
k=4-n%4
if k==4:
	print("0")
elif k==1:
	print(min(a,b+c,3*c))
elif k==2:
	print(min(2*a,b,2*c))
else:
	print(min(3*a,c))