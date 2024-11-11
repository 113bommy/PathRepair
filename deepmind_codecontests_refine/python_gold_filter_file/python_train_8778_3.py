n, m = map(int, input().split())
lst = []
for _ in range(m):
	a, b = map(int, input().split())
	lst.append([a, b])
lst.sort(key = lambda x: x[1], reverse = True)
ind = 0
ans = 0
while ind < m:
	if n >= lst[ind][0]:
		n -= lst[ind][0]
		ans += lst[ind][0] * lst[ind][1]
	else:
		ans += n * lst[ind][1]
		break
	ind += 1
print(ans)