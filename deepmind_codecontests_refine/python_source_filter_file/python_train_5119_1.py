n, m = map(int, input().strip().split())
arr = list(map(int, input().strip().split()))
cnt = [0]*101
curr = 0
for i in range(n):
	res = 0
	val = (curr+arr[i])-m
	t = 100
	while t > 0 and val > 0:
		d = min(cnt[t], (val)//t)
		res += d
		val -= d*t
		t -= 1
	print(res, end=" ")
	curr += arr[i]
	cnt[arr[i]] += 1