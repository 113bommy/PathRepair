
from math import ceil

for _ in range(int(input())):
	n,x=map(int,input().split())
	d=[]
	mx=0;
	for i in range(n):
		a=list(map(int,input().split()))
		d.append(a)
		mx=max(mx,a[0])

	d=sorted(d,key=lambda  x1: (x1[1]-x1[0]))
	x-=mx

	if(x<=0):
		print(1)
	elif(d[0][0]-d[0][1]<=0):
		print(-1)
	elif(x%(d[0][0]-d[0][1])==0):
		print(1+(x//(d[0][0]-d[0][1])))
	else:
		print(2+x//(d[0][0]-d[0][1]))




