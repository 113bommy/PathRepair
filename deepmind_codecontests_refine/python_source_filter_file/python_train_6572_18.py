a = int(input())
l = []
ans = 0
for i in range(a):
	b = input()
	l.append(b)
if a < 3 :
	print(0)
	exit()
for i in range(1, a - 1):
	for j in range(a - 1):
		if l[i][j] == l[i - 1][j - 1] and l[i][j] == l[i + 1][j - 1] and l[i][j] == l[i - 1][j + 1] and l[i ][j ] == l[i + 1][j + 1] and l[i][j] != ".":
			ans += 1
print(ans)
