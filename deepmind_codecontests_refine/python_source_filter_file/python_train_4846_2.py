import sys
from functools  import reduce
from math import gcd
I=sys.stdin.readline

ans=""

n,k=map(int,I().split())

c=list(map(int,I().split()))


i=0
x=1
while i<n-1:
	g=gcd(c[i],k)
	x=(x*g)//gcd(g,x)
	i+=1




if x==k:
	ans+="Yes\n"
else:
	ans+="No\n"


print(ans)