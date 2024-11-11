p = 10 ** 9 + 7
n, k = map(int, input().split())
g = [[] for _ in range(n)]
# print(g)
for _ in range(n - 1):
	a, b, x = map(int, input().split())
	if(x != 0):
		continue
	g[a - 1].append(b - 1)
	g[b - 1].append(a - 1)
# print(g)

visited = [False] * n
# g = sorted(g, key = lambda x : len(x), reverse = True)
print(g)
m = 0
for i in range(len(g)):
	if(visited[i] == True):
		continue
	d = []
	visited[i] =True
	d.append(i)
	c = 0
	while(d):
		o = d.pop()
		for j in g[o]:
			if(visited[j] == True):
				continue
			visited[j] = True
			d.append(j)
		c += 1
	m += pow(c, k, p)

print((pow(n, k, p) + p - m) % p)	
		
		
		