n, m = [int(x) for x in input().split(' ')]
prices = [int(x) for x in input().split(' ')]

prices.sort()
res = 0
while True:
	if m < 0 or len(prices) <= 0:
		break
	if prices[0] > 0:
		break
	res += prices.pop(0)
	m -= 1
print(-1 * res)

