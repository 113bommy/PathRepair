lista = list(map(int, input().split()))
k = lista[0]
d = lista[1]

if k != 0:
	print(d*(10**(k-1)))
else:
	if d == 1:
		print(0)
	else:
		print("No solution")