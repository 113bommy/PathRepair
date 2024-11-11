from sys import stdin
from math import gcd,sqrt
from collections import deque
input=stdin.readline
R=lambda:map(int,input().split())
I=lambda:int(input())
S=lambda:input().rstrip('\n')
hg=lambda x,y:((y+x-1)//x)*x
for _ in range(I()):
	a,b=R()
	if a>b:a,b=b,a
	if b%a:print(-1)
	else:
		ans=0
		c=b//a
		while not c%8:ans+=1;c//=8
		while not c%4:ans+=1;c//=4
		while not c%2:ans+=1;c//=2
		if ans==0 and a!=b:print(-1)
		else:print(ans)