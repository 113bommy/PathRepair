qtd = int(input())

notas = [int(i) for i in input().split()]

def menor_soma(lista):
    lista.sort()
    if lista[0] == 1:
        return -1
    else:
        return 3

print(menor_soma(notas))
    