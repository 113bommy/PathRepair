n,t=map(int,input().split())
a=list(map(int,input().split()))
mx=0
partialsum=[0]*n
partialsum[0]=a[0]
for i in range(1,n):
	partialsum[i]+=partialsum[i-1]+a[i]
for i in range(n):
	s=i
	e=n-1
	while s!=e:
		g=(s+e+1)//2
		if s>0:
			ps=partialsum[g]-partialsum[s-1]
		else:
			ps=partialsum[g]
		if ps>t:
			e=g-1
		else:
			s=g
	mx=max(mx,s-i+1)
if t<min(a):
	mx=0
print(mx)