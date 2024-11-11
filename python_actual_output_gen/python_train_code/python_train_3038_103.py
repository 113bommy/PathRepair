A, B = map(int, input())

for p in range(13, 1250):
	if int(p * 0.08) == A and int(p * 0.1) == B:
		print(p)
		exit()

print(-1)
