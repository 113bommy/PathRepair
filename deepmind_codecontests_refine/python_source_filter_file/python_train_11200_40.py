a = int(input())
res = 0
for x in range (a):
    s = str(input())
    if(s == "Icosahedron"):
        res = res + 4
    elif(s == "Cube"):
        res = res + 6
    elif(s == "Octahedron"):
        res = res + 8
    elif(s == "Dodecahedron"):
        res = res + 12
    else:
        res = res + 20
print(res)