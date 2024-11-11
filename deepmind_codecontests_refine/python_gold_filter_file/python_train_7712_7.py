n = int(input())
a = list(map(int, input().split()))

# n = 1
# a = [1]
l, r, lsum, rsum, ans = -1, n, 0, 0, 0
while l + 1 < r:
	l += 1
	lsum += a[l]
	while rsum + a[r - 1] <= lsum and r - 1 > l:
		r -= 1
		rsum += a[r]
		if lsum == rsum:
			ans = max(ans, lsum)
print(ans)
