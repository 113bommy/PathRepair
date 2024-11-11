pizzas = [(6, 15), (8, 20), (10, 25)]
ans = [1000 for _ in range(121)]
ans[0] = 0
for i in range(1, 121):
	for count, cost in pizzas:
		if i <= count:
			ans[i] = min(ans[i], cost)
		else:
			ans[i] = min(ans[i], ans[i - count] + cost)

t = int(input())
while t > 0:
	n = int(input())
	jwb = (n // 120) * ans[120] + ans[n % 120]
	for k in range(120):
		new_n = n - k
		jwb = min(jwb, (new_n // 120) * ans[120] + ans[new_n % 120] + ans[k])
	print(jwb)
	t -= 1