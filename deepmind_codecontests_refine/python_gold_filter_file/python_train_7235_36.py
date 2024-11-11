n = int(input())
ms = 0
x = list(map(int, input().split()))
for i in range(n):
	if i > 0:
		ms += abs(x[i] - x[i-1])
	else:
		ms += abs(x[i])
print(ms)