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
N=10**10+7
for _ in range(I()):
	n,x=R()
	mx=0
	mx_d=[]
	for i in range(n):
		d,h=R()
		mx=max(d,mx)
		mx_d=d-h,
	mx_d=max(mx_d)
	if x>mx and mx_d<=0:print(-1)
	elif mx>=x:print(1)
	else:print((x-mx+mx_d-1)//mx_d+1)