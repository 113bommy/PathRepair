n=int(input())
c=0
for i in range(0,n):
    s=input()
    if s=="Tetrahedron":
        c=c+4
    elif s=="cube":
        c=c+6
    elif s=="Octahedron":
        c=c+8
    elif s=="Dodecahedron":
        c=c+12
    elif s=="Icosahedron":
        c=c+20
    print(c)
