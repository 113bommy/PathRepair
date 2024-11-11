p, n = [int(x) for x in input().split()]
s = set()
for i in range(n):
	x = int(input()) % p
	if x in s:
		print(i + 1)
		break
	s |= set([x])
else:
	print(-1)