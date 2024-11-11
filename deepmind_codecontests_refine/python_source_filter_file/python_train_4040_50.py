from heapq import*
(N,M),*t=[map(int,s.split())for s in open(0)]
q=[0]*50*M
v=[[]for _ in q]
z=0
for a,b in t:v[a-1]+=[b]
for i in v[:M]:
	for j in i:heappush(q,-j)
	z-=heappop(q)
print(z)