n = int(input())
A = list(map(int, input().split()))
C = [0] * 8
free = 0
for a in A:
	if a >= 3200:
		free += 1
	else:
		C[a // 400] = 1
print(sum(C), sum(C) + free)