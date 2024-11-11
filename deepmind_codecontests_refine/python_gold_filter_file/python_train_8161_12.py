n,k = [int (x) for x in input().split()]
tabla = []
resto = 0

for x in range(n):
    row = []
    for y in range(n):
        row.append(0)
    tabla.append(row)
for x in range(n):

    for y in range(n):   
        if(x == y):
            tabla[x][y] = k
        
for x in tabla:
    print(*x)