a=int(input())
b=0
c=[]
for i in range(b):
    d=input()
    c.append(d)
    
for i in c:
    if(i=='Tetrahedron'):
        b=b+4
    elif(i=='Cube'):
        b=b+6
    elif(i=='Octahedron'):
        b=b+8
    elif(i=='Dodecahedron'):
        b=b+12
    elif(i=='Icosahedron'):
        b=b+20
print(b)
    