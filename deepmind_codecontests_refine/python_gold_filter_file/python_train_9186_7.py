from sys import stdin,stdout
from math import gcd,sqrt
from collections import deque
input=stdin.readline
R=lambda:map(int,input().split())
I=lambda:int(input())
S=lambda:input().rstrip('\n')
P=lambda x:stdout.write(x)
hg=lambda x,y:((y+x-1)//x)*x
cu=lambda x:max(0,x-1)
cd=lambda x:min(r-1,x+1)
cl=lambda x:max(0,x-1)
cr=lambda x:min(c-1,x+1)
n=I()
a=list(R())
ans=0
for i in range(n):
	for j in range(i,n):
		for k in range(j,n):
			ans=max(ans,(a[i] | a[j] | a[k]))
print(ans)