n = int(input())
lista = input()
lista = lista.split(" ")
for i in range(len(lista)):
    lista[i] = int(lista[i])
j = 0;
if (sum(lista))%2==1:
    print("first")
else:
    for i in lista:
        if i%2 == 1:
            print("first")
            j =1
            break
    if j!=1:
        print("secound")
