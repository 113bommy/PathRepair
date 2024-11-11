n = int(input())
sum = 0

for i in range(n):
    a = input()
    b = a.lower()
    if a == 'tetrahedron':
        sum += 4
    elif a == 'cube':
        sum += 6
    elif a == 'octahedron':
        sum += 8
    elif a == 'dodecahedron':
        sum += 12
    elif a == 'icosahedron':
        sum += 20
print(sum)
