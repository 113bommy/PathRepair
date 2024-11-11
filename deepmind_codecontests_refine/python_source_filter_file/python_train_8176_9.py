from sys import stdin,stdout
from math import gcd,sqrt,factorial
from collections import deque,defaultdict
input=stdin.readline
R=lambda:map(int,input().split())
I=lambda:int(input())
S=lambda:input().rstrip('\n')
L=lambda:list(R())
P=lambda x:stdout.write(x)
lcm=lambda x,y:(x*y)//gcd(x,y)
hg=lambda x,y:((y+x-1)//x)*x
pw=lambda x:0 if x==1 else 1+pw(x//2)
chk=lambda x:chk(x//2) if not x%2 else True if x==1 else False
sm=lambda x:(x**2+x)//2
N=10**9+7
def fill(v):
	p=[1]*26
	for i in v:
		if i>=0:p[i]=0
	p=[i for i in range(26) if p[i]]
	for i in range(26):
		if v[i]<0:v[i]=p.pop()
	return v
s=list(map(lambda x:ord(x)-65,S()))
ln=len(s)
a=[0]*26
if ln<26:print(-1)
cnt=0
for i in s[:26]:
	if i>=0:
		a[i]+=1
		if a[i]==2:cnt+=1
flg=False
for i in range(ln-26+1):
	if i:
		m=s[i-1]
		if m>=0:
			if a[m]==2:cnt-=1
			a[m]-=1
		m=s[i+25]
		if m>=0:
			if a[m]==1:cnt+=1
			a[m]+=1
	if not cnt:
		flg=True
		s=s[:i]+fill(s[i:i+26])+s[26+i:]
		for i in range(ln):
			if s[i]<0:s[i]=25
		break
if flg:print(*[chr(i+65) for i in s],sep='')
else:print(-1)