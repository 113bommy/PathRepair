n = int(input())
a = [0]
a.extend([tuple(map(int, input().split())) for i in range(n)])
ans = [1]
i = 1
# print(a)
while len(ans) < n:
	if a[i][0] != 1 and a[i][1] in a[a[i][0]]:
		ans.append(a[i][0])
		i = a[i][0]
	else:
		ans.append(a[i][1])
		i = a[i][1]
	print(*ans)
