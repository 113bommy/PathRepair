from heapq import*
(N,M),*t=[map(int,s.split())for s in open(0)]
q=[0]
v=[[]for _ in q]
z=0
for a,b in t:
	if a<=M:v[a-1]+=[b]
for i in v:
	for j in i:heappush(q,-j)
	z-=heappop(q)
print(z)