Na, Nb = map(int,input().split())

k,m = map(int,input().split())

lista_a = list(map(int,input().split()))
lista_b = list(map(int,input().split()))

if lista_a[k-1] < lista_b[m-1]:
    print("YES")
else:
    print("NO")
