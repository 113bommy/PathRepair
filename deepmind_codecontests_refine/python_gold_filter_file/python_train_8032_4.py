import sys

n, m = map(int, input().split())

grid = []

stars = []

for r in range(n):
	grid.append([])
	for c in range(m):
		if sys.stdin.read(1) == "*":
			stars.append((r, c))
			grid[-1].append(1)
		else:
			grid[-1].append(0)
	sys.stdin.read(1)

rc = {}
cc = {}

for r, c in stars:
	rc[r] = rc.get(r, 0) + 1
	cc[c] = cc.get(c, 0) + 1

if len(rc) != 1 + list(rc.values()).count(1):
	print("NO")
elif len(cc) != 1 + list(cc.values()).count(1):
	print("NO")
else:
	x = [i for i in rc if rc[i] > 1][0]
	y = [i for i in cc if cc[i] > 1][0]
	center = (x, y)
	try:
		if not (grid[x - 1][y] and grid[x + 1][y] and grid[x][y - 1] and grid[x][y + 1]):
			print("NO")
		else:
			count = 0
			for delta in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
				cx, cy = center
				while 0 <= cx < n and 0 <= cy < m and grid[cx][cy]:
					cx, cy = cx + delta[0], cy + delta[1]
					count += 1
			if len(stars) == count - 3:
				print("YES")
			else:
				print("NO")
	except:
		print("NO")