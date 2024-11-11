A, B = list(map(int, input().split()))
for x in range(1001):
	if (x * 8) // 100 == A and x // 10 == B:
		print(x)
		break
else:
	print(-1)
