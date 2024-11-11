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
def dfs():
	stk=[0]
	for i in stk:
		for el in a[i]:
			val[el]+=val[i]
			p[el]=i
			del a[el][a[el].index(i)]
			stk+=el,
	for i in stk[1:][::-1]:
		valn[p[i]]-=val[i]
n,k=R()
a=[[] for i in range(n)]
p=[i for i in range(n)]
val=[1]*n
valn=[-1]*n
for i in range(n-1):
	x,y=R()
	a[x-1]+=y-1,
	a[y-1]+=x-1,
dfs()
print(sum(sorted([val[i]+valn[i] for i in range(1,n)],reverse=True)[:k]))