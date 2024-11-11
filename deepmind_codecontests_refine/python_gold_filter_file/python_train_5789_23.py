lista = []
for i in range(4):
	st = input()
	lista.append(st.split(" "))


def ff(n):
	if n ==0 :
		return 2
	elif n ==1 :
		return 3
	elif n == 2:
		return 0
	elif n == 3:
		return 1


def rec(lista):
	lolo = 0 
	for i in range(len(lista)):
		for j in range(len(lista[i])-1):
			if lista[i][3] == lista[i][j] == '1' :
				lolo = 1 
				break
		momo = ff(i)
		
		if momo ==3 :
			hoho = 0
		else:
			hoho =momo + 1

		if momo ==0:
			hoho2 = 3
		else :
			hoho2 = momo -1

		if lista[i][0] == lista[hoho][3] == '1':
			lolo = 1
			break
		elif lista[i][1] == lista[momo][3]=='1':
			lolo = 1
			break
		elif lista[i][2] == lista[hoho2][3]=='1':
			lolo = 1
			break


	if lolo ==1 :
		print("YES")
	else:
		print("NO")

rec(lista)


#0 1 1 0
#1 0 1 0
#1 1 0 0
#0 0 0 1
