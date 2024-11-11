import sys
def input(): return sys.stdin.readline().strip()

n, m = map(int, input().split())
visited = [0 for i in range(n)]
edges = [[] for i in range(n)]

for i in range(m):
	x, y = map(int, input().split())
	edges[x-1].append(y-1)
	edges[y-1].append(x-1)

part = [[], []]
i = 0
outside = 0
for j in range(n):
	if not visited[j]:
		part[i].append(j)
		i = i^1
		visited[j] = 1
		cur = edges[j]
		while len(cur) > 0:
			temp = edges[cur[0]]
			notfound = True
			for k in part[i]:
				for l in temp:
					if k == l:
						notfound = False
						break
			if notfound:
				part[i].append(cur[0])
			else:
				notfound = True
				i = i^1
				for k in part[i]:
					for l in temp:
						if k == l:
							notfound = False
							break
				if notfound:
					part[i].append(cur[0])
				else:
					outside += 1

			visited[cur[0]] = 1
			for k in temp:
				cur.append(k)
			cur = [i for i in cur if not visited[i]]
			i = i^1
# print(part)
print(outside+abs(len(part[0]) - len(part[1])))