lista = list(map(int, input().split()))
k = lista[0]
d = lista[1]

if d != 0:
	print(d*(10**(k-1)))
else:
	if k == 1:
		print(0)
	else:
		print("No solution")