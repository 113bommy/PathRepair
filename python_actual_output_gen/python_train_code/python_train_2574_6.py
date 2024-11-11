n,m,k = map(int,input().split())
a = [int(x) for x in input().split()]
a.sort()
remain = 0
ans = 0
for i in range(n):
	t = remain + a[i] - m
	if (t <= 0):
		remain += a[i]
	else:
		if (t % k == 0):
			times = t // k
		else : times = t // k + 1
		ans += times
		remain -= times * k
		remain = max(remain,0)
		remain += a[i]

if (remain % k == 0): ans += remain // k
else : ans += (remain // k + 1)
print(ans)