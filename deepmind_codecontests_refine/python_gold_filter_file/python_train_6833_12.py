
import math
x1, x2 = map(int, input().split())
j=x1
t=0
# while(x1!=0):
# 	t=t+1
# 	x1=x1/2
# 	x1=math.floor(x1)

f=bin(x1)
# print(len(f))

t=len(f)-2
if(x2==1):
	print(j)
else:
	print(int(math.pow(2,t))-1)


