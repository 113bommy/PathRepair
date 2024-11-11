formato = int(input())
horario = list(map(str,input().split(":")))
digitos = []

for i in horario[0]:
	digitos.append(int(i))
for i in horario[1]:
	digitos.append(int(i))

if formato == 12:
	if digitos[0] == 0 and digitos[1] == 0 and digitos[2] > 5:
		digitos[0] = 0
		digitos[1] = 1
		digitos[2] = 2
	elif digitos[0] >= 1 and digitos[1] > 2 and digitos[2] > 5:
		digitos[0] = 0
		digitos[2] = 0
	elif digitos[0] == 0 and digitos[1] == 0:
		digitos[0] = 1
	elif digitos[0] == 1 and digitos[1] > 2:
		digitos[0] = 0
	elif digitos[0] > 1 and digitos[2] > 5:
		digitos[0] = 0
		digitos[2] = 0
	elif digitos[0] > 1:
		digitos[0] = 0
	elif digitos[2] > 5:
		digitos[2] = 0

elif formato == 24:
	if digitos[0] == 2 and digitos[1] >= 4 and digitos[2] > 5:
		digitos[1] = 3
		digitos[2] = 0
	elif digitos[0] == 2 and digitos[1] >= 4:
		digitos[1] = 3
	elif digitos[0] > 2 and digitos[2] > 5:
		digitos[2] = 0
		digitos[0] = 0
	elif digitos[0] > 2 and digitos[2] > 5:
		digitos[0] = 0
		digitos[2] = 0
	elif digitos[0] > 2:
		digitos[0] = 0
	elif digitos[2] > 5:
		digitos[2] = 0

resposta = ("{}{}:{}{}".format(digitos[0], digitos[1], digitos[2], digitos[3]))
print(resposta)
