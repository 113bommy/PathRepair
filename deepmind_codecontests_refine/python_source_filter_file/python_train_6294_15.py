lista = [["A",[],[]],
         ["B",[],[]],
         ["C",[],[]]]
# entrada_1 = "A>B"
# entrada_2 = "C>A"
# entrada_3 = "B>C"
entrada_1 = input()
entrada_2 = input()
entrada_3 = input()
x = 3
inposible = False
A = []

while x != 0:
	palabra = "entrada_" + str(x)
	prim = eval(palabra)[0]
	ecu = eval(palabra)[1]
	segun = eval(palabra)[2]
	A.append(prim)
	
	A.append(segun)
	if prim == segun :
		print(4444444444444)
		inposible = True
		break
	if ecu == ">":
		lista[ord(prim)-65][2].append(segun)
		lista[ord(segun)-65][1].append(prim)
	else:
		lista[ord(segun)-65][2].append(prim)
		lista[ord(prim)-65][1].append(segun)
	x-=1

A.sort()
#print("inpo", inposible)
if A[:2] != ["A","A"] or A[2:4] != ["B","B"] or A[4:] != ["C","C"]:
	print(A[:2], A[2:4], A[4:],77777777777)
	inposible = True
final = ""
# print(A,inposible)
if not inposible:
#	print(2345)
	hay = False
	vacio_mayores = False
	vacio_menores = False
	for x in lista:
		letra = x[0]
		primero = x[1]
		segundo = x[2]
		
		if primero == segundo:
			inposible = True
			break 
		if len(primero) == len(segundo) and len(primero) == 1:
			if hay:
				inposible =True
			final = segundo[0] + letra + primero[0]
			hay = True
		elif not primero and len(segundo) == 2:
			if vacio_menores:
				inposible = True
			else:
				vacio_menores = True
		elif not segundo and len(primero) == 2:
			if vacio_mayores:
				inposible = True
			else:
				vacio_mayores = True
		else:
			inposible = True
#print(inposible,lista,111111111)
#bprint(final,vacio_menores)
if final and not inposible and vacio_menores and vacio_mayores:
	print(final)
else:#	inposible or vacio_mayores and vacio_menores:
	# print("dddddd")
	print ("Impossible.")


# else:
# 	print("Impossible")
