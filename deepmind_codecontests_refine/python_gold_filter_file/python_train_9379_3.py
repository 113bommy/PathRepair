import sys
import collections as cc
import bisect as bi
input=sys.stdin.readline
I=lambda:list(map(int,input().split()))
n,=I()
a=[]
b=[]
c=[]
d=[]
aa=[]
bb=[]
cc=[]
dd=[]
for i in range(n):
	x,y,xx,yy=I()
	a.append(x)
	b.append(y)
	c.append(xx)
	d.append(yy)
	aa.append(x)
	bb.append(y)
	cc.append(xx)
	dd.append(yy)
	
a.sort()
b.sort()
c.sort()
d.sort()
x,y=a[-1],b[-1]
xx,yy=c[0],d[0]
ans=-1
if xx>=x and yy>=y:
	ans=[x,y]
else:		
	for i in range(n):
		x,y=a[-1],b[-1]
		xx,yy=c[0],d[0]
		if aa[i]==x:
			x=a[-2]
		if bb[i]==y:
			y=b[-2]
		if cc[i]==xx:
			xx=c[1]
		if dd[i]==yy:
			yy=d[1]
		if xx>=x and yy>=y:
			ans=[x,y]
			break
print(*ans)