import sys
input = sys.stdin.readline
I = lambda : list(map(int,input().split()))

n,=I()
x1,x2,y1,y2=[],[],[],[]
rt=[]
for i in range(n):
	rt.append(I())
	x1.append(rt[-1][0])
	y1.append(rt[-1][1])
	x2.append(rt[-1][2])
	y2.append(rt[-1][3])
x=y=-1
x1.sort();x2.sort();y1.sort();y2.sort()
a,b,c,d=x1[-1],x2[0],y1[-1],y2[0]

if a<=c and b<=d:
	print(a,b)
else:
	for i in range(n):
		t=rt[i]
		a,b,c,d=x1[-1],x2[0],y1[-1],y2[0]
		if a==t[0]:
			a=x1[-2]
		if b==t[2]:
			b=x2[1]
		if c==t[1]:
			c=y1[-2]
		if d==t[3]:
			d=y2[1]
		if a<=c and b<=d:
			x,y=a,b;break
	print(x,y)