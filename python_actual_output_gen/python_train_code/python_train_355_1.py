n, m = map(int, input().split())
mx = [list(input()) for i in range(n)]
s = set()
for i in range(n):
	if i in s:
		continue
	for j in range(m):
		if mx[i][j] == '#':
			s.add(i)
			for k in range(i + 1, n):
				if mx[k][j] == '#':
					if mx[k] != mx[i]:
						print('No')
						exit(0)
					s.add(k)
			break
print('Yes')