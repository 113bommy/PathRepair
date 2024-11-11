n, k = map(int, input().split())
a = list(map(int, input().split()))
t = list(map(int, input().split()))
c = [0 for _ in range(n + 1)]
b = sum([a[i] for i in range(n) if t[i] == 1])
for i in range(n):
	if t[i] == 0:
		c[i + 1] = a[i]
for i in range(1, n + 1):
	c[i] += c[i - 1]
m = 0
for i in range(n - k):
	if c[i + k] - c[i] + b > m:
		m = c[i + k] - c[i] + b
print(m)
