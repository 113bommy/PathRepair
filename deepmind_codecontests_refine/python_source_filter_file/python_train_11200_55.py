n = int(input())
##a = "Icosahedron"
##b = "Cube"
##c = "Tetrahedron"
##d = "Dodecahedron"

dic = {"Icosahedron":4,
"Cube":6,
"Octahedron":8,
"Tetrahedron":12,
"Dodecahedron":20}

res = 0
for i in range(n):
    x = str(input())
    res += dic[x]
    
    
print(res)
