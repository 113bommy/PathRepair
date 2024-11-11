import math
import sys
input = sys.stdin.readline

k=int(input())

if k==0:
	print(1,1)
	print(1)
else:
	print(2,2)
	print(2**18-1,2**17-1,0)
	print(2**17,2**18-1,k)