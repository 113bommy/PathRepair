n, a, b = map(int, input().split())
c = list(map(int, input().split()))
cost = min(a, b) * 2
counts = 0
for i in range(n//2):
	x = c[i]^c[-1-i]
	if x == 1:
		print(-1)
		exit()
	elif x == 2:
		counts += a
	elif x == 3:
		counts += b
	elif c[i] == 2:
		counts += cost
if 1 & n and c[n//2] == 2:
	counts += min(a, b)
print(counts)