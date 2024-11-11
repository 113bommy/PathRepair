
n = int(input())

cnt = [0] * 1007
a = [ [0] * 20 for i in range(20)]

der = list(map(int, input().split()))
for i in der:
	cnt[i] += 1

cel = []

for i in range((n + 1) // 2):
	for j in range((n + 1) // 2):
		if i != n - i - 1 and j != n - j - 1:
			cel.append((4, (i, j)))
		elif (i != n - i - 1) ^ (j != n - j - 1):
			cel.append((2, (i, j)))
		else:
			cel.append((1, (i, j)))


for cur in [4, 2, 1]:
	lst = 1
	for it in cel:
		if it[0] != cur:
			continue
		i = it[1][0]
		j = it[1][1]
		while lst < 1007 and cnt[lst] < cur:
			lst += 1
		if lst == 1007:
			print("NO")
			exit(0)
		a[i][j] = a[n - i - 1][j] = a[i][n - j - 1] = a[n - i - 1][n - j - 1] = lst
		cnt[lst] -= cur

print("YES")

for i in range(n):
	print(*a[i][:n])
