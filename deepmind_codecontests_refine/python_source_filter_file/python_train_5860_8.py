import sys;import math;from collections import deque;from bisect import bisect_left,bisect_right;I=sys.stdin.readline;IN=lambda x:map(int,x.split());L=lambda x:list(IN(x))
def P(*x,end="\n"):
	print(*x,end=end)
M=1000000007
def npr(n,r):
	c=1;i=n-r+1
	while(i<=n):
		c=(c*i)%M
		i+=1
	return c
n,x,pos=IN(I())
left=0;right=n;f=False;smallmax=x-1;largemax=n-x;small=large=0
while(left<right):
	middle=(left+right)/2
	if(middle<pos):
		small+=1
		if(small>smallmax):
			f=True
			break
		left=middle+1
	elif(middle==pos):
		left=middle+1
	else:
		large+=1
		if(large>largemax):
			f=True
			break
		right=middle
if(f):
	P(0)
	exit()
a=npr(smallmax,small)
b=npr(largemax,large)
c=npr(n-small-large-1,n-small-large-1)
res=(a*b)%M
res=(res*c)%M