n, k = map(int, input().split())
tmp = k
ans = 0
for _ in range(n):
	t, k = input().split()
	k = int(k)
	if t == '+':
		tmp += int(k)
	elif int(k) < tmp:
		tmp -= int(k)
	else:
		ans += 1
print(tmp, ans)