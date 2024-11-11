faces = 0
for i in range(int(input())):
    poly = input()
    if(poly == "Tetrahedron"):
        faces += 4
    elif(poly == "Icosahedron"):
        faces += 20
    elif(poly == "Cube"):
        faces += 6
    elif(poly == "Dodecahedron"):
        faces += 12
    elif(poly == "Octahedron"):
        faces == 8
print(faces)