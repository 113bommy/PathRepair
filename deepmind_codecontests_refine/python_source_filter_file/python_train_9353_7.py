n,l,t=map(int,input().split())
a,cs=[0]*n,0
for i in range(n):
	x,y=map(int,input().split())
	x+=(t if y==1 else -t)
	cs=(cs+x//l)%n
	x%=l
	a[i]=x
a.sort()
print('\n'.join([str(a[(i+cs)%n]) fori in range(n)]))
