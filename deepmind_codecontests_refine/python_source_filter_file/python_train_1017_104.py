n, k, s = map(int, input().split())
if s == 1:
	a = [2] * n
else:
	a = [1] * n


for i in range(k):
	a[i] = s

print (*a)