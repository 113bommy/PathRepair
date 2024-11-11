n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

arr = sorted(list(zip(a, [1] * n)) + list(zip(b, [2] * m)))

ans = 10**18

less_sum, less_cnt = 0, 0
more_sum, more_cnt = sum(b), m
for x, y in arr:
	if y == 1:
		less_sum += x
		less_cnt += 1
	else:
		more_sum -= x
		more_cnt -= 1
	ans = min(ans, (less_cnt * x - less_sum) + (more_sum - more_cnt * x))

print(ans)
