input()

D = [0, 0]
maxd = 0

for c in input():
	if c == '(':
		_, i = min((D[i], i) for i in range(2))
		print(i, end=' ')
		D[i] += 1
		maxd = max(maxd, D[i])
	else:
		_, i = max((D[i], i) for i in range(2))
		print(i, end=' ')
		D[i] -= 1
print()
