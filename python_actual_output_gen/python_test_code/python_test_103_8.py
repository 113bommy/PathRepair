n=int(input())
c=0
for i in range(n):
    n=input()
    if(n=="Tetrahedron"):
        c=c+4
    elif(n=="Cube"):
        c+=3
    elif(n=="Octahedron"):
        c+=8
    elif(n=="Dodecahedron"):
        c+=12
    elif(n=="Icosahedron"):
        c+=20
print(c)
