from sys import stdin,stdout
from math import gcd,sqrt
from collections import deque
input=stdin.readline
R=lambda:map(int,input().split())
I=lambda:int(input())
S=lambda:input().rstrip('\n')
L=lambda:list(R())
P=lambda x:stdout.write(x)
hg=lambda x,y:((y+x-1)//x)*x
pw=lambda x:1 if x==1 else 1+pw(x//2)
chk=lambda x:chk(x//2) if not x%2 else True if x==1 else False
N=10**6+7
v=[(i+1)*100 for i in range(5000)]
ans=0
n=I()
a=L()
for i in range(n):
	s=0
	for j in range(i,n):
		s+=a[j]
		if s>v[j-i]:ans=max(ans,j+1)
print(ans)	