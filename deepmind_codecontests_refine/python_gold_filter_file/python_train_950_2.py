def read_line():
	return list(map(int, input().split()))

mod = 1000000007
g = {}
n,k = read_line()
done = set()

curr = 1
count = 0
for _ in range(n-1):
	u,v,x = read_line()
	if x == 0:
		li = g.get(u,[])
		li.append(v)
		g[u] = li

		li = g.get(v,[])
		li.append(u)
		g[v] = li

def width_search(n):
	comp = 0
	q = []
	q.append(n)
	done.add(n)
	while q:
		x = q.pop(0)
		comp += 1
		l = g.get(x,[])
		for i in l:
			if i not in done:
				q.append(i)
				done.add(i)
	return comp

answer = n**k
for i in range(1,n+1):
	if i not in done:
		answer -= width_search(i)**k


print(str(answer % mod))