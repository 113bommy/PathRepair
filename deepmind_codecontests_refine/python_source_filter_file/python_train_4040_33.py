from heapq import*
(N,M),*t=[map(int,s.split())for s in open(0)]
q=[0]*99*M
v=[[]for _ in q]
z=0
for a,b in t:v[a]+=[b]
for i in v[:M]:
	for j in i:heappush(q,-j)
	z-=heappop(q)
print(z)