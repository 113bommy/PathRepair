#codeforces 48c: the race: math
import math

def readGen(trans):
	while 1:
		for x in input().split():
			yield(trans(x))
readint=readGen(int)

n=next(readint)
a=[0]+[next(readint) for i in range(n)]

p=max((n+1)*a[i]/i-1 for i in range(1,n+1))
q=min((n+1)*(a[i]+1)/i for i in range(1,n+1))

eps=1e-8
u=math.floor(q-eps)
l=math.ceil(p+eps)
#print(p,q,l,u)
if (l<u): print("not unique")
else: print("unique\n%d"%l)
