from heapq import*
N,M,*t=map(int,open(0).read().split())
v=[[]for _ in'_'*M]
for i in range(N):M<t[2*i]or v[t[2*i]-1].append(t[2*i+1])
z=0
q=[]
for i in v:
	for j in i:heappush(q,-j)
	z-=q[0]and heappop(q)
print(z)