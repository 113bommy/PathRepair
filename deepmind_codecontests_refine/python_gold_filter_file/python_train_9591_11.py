n, k = map(int, input().split())
arr = list(map(int, input().split()))

e = 0
for i in range(n):
	if arr[i] == 1:
		e += 1
s = n - e
ans = 0

for i in range(k):
	ec = 0
	sc = 0
	for j in range(i, n, k):
		if arr[j] == 1:
			ec += 1
		else:
			sc += 1
	ans = max(abs(e-ec-s+sc), ans)
print(ans)
