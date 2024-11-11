import math
n,x,y=map(int,input().split())

p=math.ceil((y*n)/100)

ans=abs(p-x)
if ans<x:
	print(0)
else:
	print(ans)