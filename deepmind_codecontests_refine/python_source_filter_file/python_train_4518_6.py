a,b,n=input().split()
import math
a=int(a)
b=int(b)
n=int(n)
c=1
d=1

if b==0 and a==0:
	ans=0
elif a*b==0:
	if a==0:
		d=0
	else:
		ans=0
else:
	if a*b<0:
		c=-1
		a=abs(a)
		b=abs(b)

	ans=pow(b/a,1/n)
if d:
	if ans-int(ans)<1e-8:
		ans = int(ans+1e-8)*c
	else:
		ans="No solution"
else:
	ans="No solution"
print(ans)