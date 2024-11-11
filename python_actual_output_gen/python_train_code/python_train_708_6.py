n, m = map(int, input().split())
l = sorted([int(i) for i in input().split()])

if len(set(l)) == 1 and 0<n<m:
	print('NO')
	exit()
for i in range(n):
	for j in range(i, n):
		if not sum(l[i:j+1]) % m:
			print('YES')
			exit()
		if sum(l[:i]) and sum(l[j+1:]):
			if not sum(l[:i] + l[j+1:]) % m:
				print('YES')
				exit()
else:
	print('NO')