n=int(input())
l=[]
for i in range(0,n):
    a=input()
    l.append(a)
print(l)
f=0
for i in l:
    if i=="Tetrahedron":f=f+4
    elif i=="Cube":f=f+6
    elif i=="Octahedron":f=f+8
    elif i=="Dodecahedron":f=f+12
    elif i=="Icosahedron":f=f+20
print(f)    
