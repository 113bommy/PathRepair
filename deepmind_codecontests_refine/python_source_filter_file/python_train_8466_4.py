I=lambda:map(int,input().split())
n,c=I()
a,b=[],[]
for _ in range(n):x,y=I();a.append(x);b.append(y)
f=lambda x:sum(1+a[i]*x//b[i]for i in range(n))
l=-1
r=10**15
while l<r-1:
	m=(l+r)//2
	if f(m)<c:l=m
	else:r=m
L=r
l=-1
r=10**9
while l<r-1:
	m=(l+r)//2
	if f(m)<=c:l=m
	else:r=m
while f(r)>c:r-=1
if r<1:r=1
if L<1:L=1
if f(r)!=c:print(0)
else:print(r-L+1)