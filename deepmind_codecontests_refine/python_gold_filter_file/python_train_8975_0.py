# from debug import debug

inf = int(1e10)
n, m = map(int, input().split())
trans = [[] for i in range(n)]
graph = [[] for i in range(n)]

for i in range(m):
	a,b = map(int, input().split())
	trans[b-1].append(a-1)
	graph[a-1].append(b-1)

k = int(input())
lis = [x-1 for x in map(int, input().split())]

s, d = lis[0], lis[-1]
v = [0]*n
dis = [inf]*n

v[d] = 1
dis[d] = 0
q = [d]
while q:
	node = q.pop(0)
	for i in trans[node]:
		if not v[i] and dis[i] > dis[node]+1:
			dis[i] = dis[node] + 1
			q.append(i)

reb, ad = 0, 0
prev = s
for i in range(1, k-1):
	if dis[lis[i]] + 1 > dis[prev]:
		reb+=1
	for j in graph[prev]:
		if j != lis[i] and dis[j] + 1 == dis[prev]:
			ad+=1
			break
	prev = lis[i]
print(reb, ad)

