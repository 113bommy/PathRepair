import math
from sys import stdin
from sys import setrecursionlimit
setrecursionlimit(100000)
def put():  return  map(int, stdin.readline().split())
for _ in range(int(input())):
	n=int(input())
	if(n%3==0):
		print(n//3,0,0)
	elif(n%3==1):
		if(n//3>1):
			print((n//3)-2,0,1)
		else:
			print(-1)
	else:
		if(n//3>1):
			print((n//3)-1,1,0)
		else:
			print(-1)

