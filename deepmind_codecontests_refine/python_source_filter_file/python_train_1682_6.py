
from math import *

n,m=map(int,input().split(" "))

x=list(map(int,input().split(" ")))
p=list(map(int,input().split(" ")))

f=x[0]

for i in range(n):
	x[i]-=x[0]

gc=0

for i in x:
	gc=gcd(gc,i)



for i in range(m):
	if(gc%p[i]==0):
		print("YES")
		print(f,i+1)
		exit()
print("NO")


