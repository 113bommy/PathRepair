dias = int(input())
total = 0
preco = 101

for i in range(dias):
    a, preco_dia = map(int, input().split())
 
    preco = min(preco, preco_dia)
 
    total += (a * preco + 1)


print(total)