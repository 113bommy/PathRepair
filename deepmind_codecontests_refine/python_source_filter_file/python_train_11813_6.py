#fin, fout = open("input.txt"), open("output.txt", "w")
n, m = map(int, input().split())
#n, m = map(int, fin.readline().split())
A = [list(map(int, input().split())) for i in range(n)]
#A = [list(map(int, fin.readline().split())) for i in range(n)]
I, J = [0] * n, [0] * m
IS, JS = [0] * n, [0] * m
CountI, CountJ = 0, 0
for i in range(n):
	IS[i] = sum(A[i])
	if (IS[i] == m):
		I[i] = 1
		CountI += 1
for j in range(m):
	JS[j] = sum([A[i][j] for i in range(n)])
	if (JS[j] == n):
		J[j] = 1
		CountJ += 1
flag = True
i = 0
while i < n and flag:
	if (IS[i] != m and IS[i] != CountJ):
		flag = False
	i += 1
j = 0
while j < m and flag:
	if (JS[j] != n and JS[j] != CountI):
		flag = False
	j += 1
if (flag or sum(I) + sum(J) > 0 and sum(I) * sum(J) == 0):
	print("YES")
	for i in range(n):
		for j in range(m):
			print(I[i] * J[j], end = " ")
		print()
else:
	print("NO")
#fout.close()
#fin.close()