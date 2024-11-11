n = int(input())
s = [input() for _ in range(n)]
x, nx = s[0][0], s[0][1]

ok = x != nx
for i in range(n):
	for j in range(n):
		if(i == j or i == n - j - 1):
			if(s[i][j] != x):
				ok = 0
		else:
			if(s[i][j] != nx):
				ok = 0

print("YES" if ok else "NO")
