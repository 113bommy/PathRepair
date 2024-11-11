from sys import stdin,stdout
from math import gcd,sqrt,inf
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
N=inf
n=I()
a=S()
b=S()
x=[]
y=[]
d={'a':0,'b':0}
for i in range(n):
	if 'a'==a[i]!=b[i]:x+=i+1,
	elif 'b'==a[i]!=b[i]:y+=i+1,
	d[a[i]]+=1
	d[b[i]]+=1
if not d['a']%2==d['b']%2==0:exit(print(-1))
op=0
ans=[]
ln_x=len(x)
ln_y=len(y)
for i in range(0,ln_x-ln_x%2,2):
	ans+=(x[i],x[i+1]),
	op+=1
for i in range(0,ln_y-ln_y%2,2):
	ans+=(y[i],y[i+1]),
	op+=1
if ln_x&1:
	ans+=(x[-1],x[-1]),
	ans+=(x[-1],y[-1]),
	op+=1
print(op)
for i in ans:print(*i)