
n,t=map(int,input().split())
a=list(map(int,input().split()))

bit=[0 for i in range(n+2)]

def qq(i):
	ans=0
	i=i+1
	while i>0:
		ans+=bit[i]
		i-=i&-i
	return(ans)

def u(i):
	i+=1
	while i<=n+1:
		bit[i]+=1
		i+=i&-i

q=[]

c=[0]
for i in range(n):
	c.append(c[-1]+a[i])
	q.append((i+1,t+c[i]))



c=[(c[i],i) for i in range(n+1)]
c.sort()

q.sort(key=lambda x:x[1])
ans=0

i=0
j=0
while j<len(q):
	l,x=q[j]
	while i<n and c[i][0]<x:
		u(c[i][1])
		i+=1
	ans+=qq(n)-qq(l-1)
	j+=1
print(ans)


