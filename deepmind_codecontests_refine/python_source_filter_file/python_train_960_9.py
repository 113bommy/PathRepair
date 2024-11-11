from sys import stdin,stdout
from math import gcd,sqrt
from collections import deque
input=stdin.readline
R=lambda:map(int,input().split())
I=lambda:int(input())
S=lambda:input().rstrip('\n')
L=lambda:list(R())
P=lambda x:stdout.write(x)
lcm=lambda x,y:(x*y)//gcd(x,y)
hg=lambda x,y:((y+x-1)//x)*x
pw=lambda x:1 if x==1 else 1+pw(x//2)
chk=lambda x:chk(x//2) if not x%2 else True if x==1 else False
sm=lambda x:(x**2+x)//2
N=10**9+7
for _ in range(I()):
	a,b,q=R()
	lm=lcm(a,b)
	m=max(a,b)
	for i in range(q):
		l,r=R()
		u=(r//lm)*lm
		d=(l//lm)*lm
		if u==d:
			d=u
			u+=m-1
			if u>=r:P(str(max(l,d)-l)+' ')
			else:P(str(min(r-l+1,r-u))+' ')
		else:
			d=max(l-1,m-1+d)
			if u+m<=r:P(str(r-d-(r//lm-l//lm)*m)+' ')
			else:P(str(u-d-(r//lm-l//lm-1)*m)+' ')
	P('\n')