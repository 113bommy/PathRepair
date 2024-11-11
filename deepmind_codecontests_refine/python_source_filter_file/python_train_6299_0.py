import sys

# there is always a railway or a road connecting 1 and n
# so we just need to figure out the shortest route of the other transport

n,m = map(int,input().split())
railways = [[False]*n for _ in range(n)]
railways_list = [[] for _ in range(n)]
for _ in range(m):
	u,v = map(int,input().split())
	u,v = u-1,v-1
	railways[u][v] = railways[v][u] = True
	railways_list[u].append(v)
	railways_list[v].append(u)
if railways[0][n-1]:
	for i in range(n):
		railways_list[i] = [j for j in range(n) if i != j and not railways[i][j]]
		for j in range(n):
			railways[i][j] = not railways[i][j]

# Dijkstra's algorithm
# find the shortest route from 0 to n-1
shortest = [n]*n
shortest[0] = 0
eunda = [0]
ita = set()
while eunda:
	eunda.sort(key=shortest.__getitem__)
	curr = eunda.pop()
	ita.add(curr)
	for eundum in railways_list[curr]:
		if eundum not in ita:
			if eundum not in eunda:
				eunda.append(eundum)
			shortest[eundum] = min(shortest[eundum],shortest[curr]+1)
if shortest[n-1] == n:
	print(-1)
else:
	print(shortest[n-1])