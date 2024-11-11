def solve(n, d, a):
	result = a[0]
	idx = 1
	multiplier = 1
	while idx < n and d >= multiplier:
		current_stock = a[idx]
		while current_stock > 0 and d >= multiplier:
			result += 1
			current_stock -= 1
			d -= multiplier*1
		idx += 1
		multiplier += 1
	return result


t = int(input())
for _ in range(t):
	n, d = map(int, input().split())
	a = list(map(int, input().split()))
	result = solve(n, d, a)
	print(result)