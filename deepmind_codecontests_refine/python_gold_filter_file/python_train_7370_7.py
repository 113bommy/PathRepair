n = int(input())
xy = [tuple(map(int, input().split())) for _ in range(n)]
pq = []
for i in range(n):
	for j in range(i+1,n):
		if i==j:
			continue
		xi, yi = xy[i]
		xj, yj = xy[j]
		pq.append((xi - xj, yi - yj))
ans = n
for p, q in pq:
	cost = 0
	for x, y in xy:
		if (x + p, y + q) in xy:
			pass
		else:
			cost += 1
	ans = min(ans, cost)
print(ans)