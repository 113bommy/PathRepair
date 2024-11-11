vstup = list(map(int,input().split()))
caja1 = vstup[0]
caja2 = vstup[1]

cena = vstup[2]
doplatok = 0

zostatokcaja1 = caja1%cena
zostatokcaja2 = caja2%cena

if zostatokcaja1+zostatokcaja2>=cena:
	doplatok = cena - max([zostatokcaja2,zostatokcaja1])
print(int((caja1+caja2)/cena), doplatok)


