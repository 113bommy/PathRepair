def solve() :
	n, k = map(int, input().split())
	a = [int(i) for i in input().split()]
	cnt = [0] * (2 * k + 2)
	for i in range(n // 2) :
		sum = a[i] + a[n - i - 1]
		cnt[2] += 2
		cnt[sum - max(a[i], a[n - i - 1]) + 1] -= 1
		cnt[sum] -= 1
		cnt[sum + 1] += 1
		cnt[sum + k - min(a[i], a[n - i - 1]) + 1] += 1
	ans = n
	for i in range(2, 2 * k + 1) :
		cnt[i] += cnt[i - 1]
		ans = min(ans, cnt[i])
	print(ans)
t = int(input())
while t > 0:
	t -= 1
	solve()