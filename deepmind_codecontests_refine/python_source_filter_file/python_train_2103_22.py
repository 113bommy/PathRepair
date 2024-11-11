import math
t=int(input())
while(t):
	m=list(map(int,input().split()))
	a=math.ceil(m[0]/m[2])
	b=math.ceil(m[1]/m[1])
	c=a+b
	if (c<=m[4]):
		print(a,b)
	else:
		print(-1)
	t-=t
	
