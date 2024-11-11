n, a, b = map(int, input().strip().split())
ans = list()
sum1 = 1
ans.append(1)
res = 1
for i in range(2, n+1):
	pass
	if b != 0:
		pass
		res = sum1 + 1
		b = b - 1
	elif a > 0 and i > 2:
		res = res + 1
		a = a - 1
	ans.append(res)
	sum1 += res
if a > 0 or b > 0:
	pass
	print(-1)
else:
	print(1, end = " ")
	for x in range(1,n):
		pass
		print(ans[x], end=" ")