from heapq import*
(N,M),*t=[map(int,s.split())for s in open(0)]
z,*q=[0]*99*M
v=[[]for _ in q]
for a,b in t:v[a-1]+=b,
for i in v[:M]:
 for j in i:heappush(q,-j)
 z-=heappop(q)
print(z)