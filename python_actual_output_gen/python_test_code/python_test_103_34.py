n = int(input())
res = 0
for i in range(n):
    k = input()
    if k == 'Tetrahedron':
        res += 4
    elif k == 'Cube':
        res += 6
    elif k == 'Octahedron':
        res += 8
    elif k == 'Dodecahedron':
        res += 12
    else:
        res += 20
print(k)