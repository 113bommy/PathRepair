n, m = map(int, input().split())
c = 0
for _ in range(n):
	arr = list(map(int, input().split()))
	for i in range(0, 2*m, m):
		if arr[i] == 1 or arr[i+1] == 1:
			c += 1
print(c)