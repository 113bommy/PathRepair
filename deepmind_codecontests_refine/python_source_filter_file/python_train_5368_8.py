n, m, k = map(int, input().split())
graph = [input().split() for i in range(m)]
if k == 0:
	print(-1)
	exit(0)
l = set(input().split())
amt = 10 ** 9 + 1
for g in graph:
	if g[0] in l or g[1] in l:
		amt = min(amt, int(g[2]))
print(-1) if amt > 10 ** 9 else print(amt)