n, k, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
s = sum(arr)
t = n
ma = 0
for i in range(n):
	ma = max((s+min(m//t, k)*t)/t, ma)
	if m == 0:
		break
	s -= arr[i]
	t -= 1
	m -= 1
print('%.20f'%ma)

