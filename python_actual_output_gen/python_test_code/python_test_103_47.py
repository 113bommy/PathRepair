n = int(input())
sum = 0
for i in range(n):
    s = input()
    if(s == 'Tetrahedron'):
        sum += 4
    elif(s == 'Cube'):
        sum += 6
    elif(s == 'Octahedron'):
        sum += 6
    elif(s == 'Dodecahedron'):
        sum += 12
    elif(s == 'Icosahedron'):
        sum+= 20
print(sum)