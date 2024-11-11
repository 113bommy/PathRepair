n,m = map(int, input().split())
a = [[*map(int, input().split())] for _ in range(n)]

for b in range(10):
	inds = []
	for r in range(n):
		i = [-1, -1]
		for c in range(m):
			i[(a[r][c] >> b) & 1] = c
		inds.append(i)
	tot = 0
	opt = -1
	for r in range(n):
		if -1 not in inds[r]:
			opt = r
		tot += inds[r][0] == -1

	tot &= 1
	if tot == 0 and opt == -1:
		continue

	print("TAK")
	ans = []
	for r in range(n):
		if opt == r and tot == 0:
			ans.append(inds[r][1])
		else:
			ans.append(inds[r][inds[r][0] == -1] + 1)
		
	print(*ans)
	break
else:
	print("NIE")