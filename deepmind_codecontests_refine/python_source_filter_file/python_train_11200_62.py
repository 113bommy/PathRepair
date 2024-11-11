totalFaces = 0
n = int(input())
for i in range(n):
    polygon = input()
    if polygon == 'Tetrahedron':
        totalFaces += 3
    elif polygon == 'Cube':
        totalFaces += 6
    elif polygon == 'Octahedron':
        totalFaces += 8
    elif polygon == 'Dodecahedron':
        totalFaces += 12
    elif polygon == 'Icosahedron':
        totalFaces += 20

print(totalFaces)
