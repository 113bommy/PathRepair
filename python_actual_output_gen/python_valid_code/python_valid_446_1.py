t = int(input())

for _ in range(t):
	n, c = input().split()
	n = int(n)
	s = input().strip()

	if all(s[i] == c for i in range(n)):
		print(0)
	else:
		if c in s:
			lastc = n - s[::-1].index(c) - 1

			if lastc < n/2:
				print(2)
				print(n-1, n)
			else:
				print(1)
				print(lastc+1)
		else:
			print(2)
			print(n-1, n)
