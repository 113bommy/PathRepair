n, a = list(map(int, input().split()))
t = list(map(int, input().split()))
a -= 1
r = t[a]
for i in range(1, n):
	if a - i >= 0 and a + i < n:
		r += 2 * (t[a - i] and t[a + i])
	elif a - i >= 0:
		r += t[a - i]
	elif a + i < n:
		r += t[a + i]
print(r)