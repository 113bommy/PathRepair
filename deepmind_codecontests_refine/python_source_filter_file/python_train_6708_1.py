x,y = map(int, input().split())
matriz = [[0 for i in range(y)] for i in range (x)]
lista = []
if y <= 1:
	for c in range(x):
		z = int(input())
		if c > 0:
			matriz[c][0] = matriz[c-1][0] + z
		else:
			matriz[c][0] = z
else:
	for c in range(x):
		z = list(map(int, input().split()))
		lista.append(z)
		if c == 0:
			matriz[c][0] = z[0]
		else:
			matriz[c][0] = matriz[c-1][0] + z[0]

	for c in range(1, y):
		matriz[0][c] = lista[0][c] + matriz[0][c-1]
msg = ""

if y != 1:
	for i in range(1, x):
		for j in range(1, y):
			if matriz[i][j] != 0:
				pass
			else:
				if matriz[i-1][j] > matriz[i][j-1]:
					matriz[i][j] =  matriz[i-1][j] + lista[i][j]
				elif matriz[i-1][j] < matriz[i][j-1]:
					matriz[i][j] = matriz[i][j-1] + lista[i][j]
for c in range(x):
	msg += str(matriz[c][-1]) + " "
print(msg.strip())