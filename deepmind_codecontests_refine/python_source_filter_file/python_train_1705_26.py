import math
n, m = list(map(int, input().split()))
print(min(n, m) + 1)
for x in range(n + 1):
		print(x, m - x)