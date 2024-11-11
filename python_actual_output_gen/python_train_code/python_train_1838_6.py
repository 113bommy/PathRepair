n = int(input())
for i in range(n // 7 + 1):
	if (n - i * 7) % 4 == 0:
		print('4' * ((n - i * 7) // 4) + '7' * i)
		break
else:
	print(-1)
