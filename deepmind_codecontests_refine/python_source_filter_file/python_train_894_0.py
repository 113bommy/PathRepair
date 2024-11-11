n = int(input())
lista = [i for i in range((n+1)//2, 0, -1)if i < n-i]
a,b = 0,0

def div(a,b):
    for i in range(2, a):
        if a % i == 0 and b % i == 0:
            return True
    return False

for i in range(len(lista)):
    a, b = lista[i], n-lista[i]
    if div(a,b) == False:
        break

print(a, b)