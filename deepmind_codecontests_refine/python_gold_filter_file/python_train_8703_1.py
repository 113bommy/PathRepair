lista = list(map(int, input().split()))
lista1 = list(range(lista[0], lista[1]+1))
lista2 = list(range(lista[2], lista[3]+1))
j = i = 0
resp = "NO"

while True:
	if j == lista[3] - lista[2] +1  or i == lista[1] - lista[0]+1:
		break
	if lista1[i] / lista2[j] == lista[4]:
		resp = "YES"
		break
	elif lista1[i] / lista2[j] < lista[4]:
		i += 1
	elif lista1[i] / lista2[j] > lista[4]:
		j += 1

print (resp)