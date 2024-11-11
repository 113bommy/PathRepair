Na, Nb = map(int,input().split())

k,m = map(int,input().split())

lista_a = list(map(int,input().split()))
lista_b = list(map(int,input().split()))

if lista_a[-1] < lista_b[0]:
    print("YES")
else:
    print("NO")
