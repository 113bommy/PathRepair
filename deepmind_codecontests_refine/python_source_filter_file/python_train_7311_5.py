from collections import defaultdict
n=int(input())
li=[-1]
ar= list(map(int,input().split()))
dd=defaultdict(lambda:-1)
a=0
s=0
for j in range(n):
	a+=ar[j]
	if a==0:
		if len(li)==1:
			li.append(-1)
			s+=n-j
	if dd[a]!=-1:
		b=li[-1]
		i=dd[a]
		if i<=b:
			dd[a]=j
			continue
		y=(i-b)
		s+=y*(n-j)
		li.append(i)
	dd[a]=j
	
		
		
x=n*(n+1)/2

print(int(x)-s)
