n=int(input())
l=[]
for i in range(n):
    s=input()
    l.append(s)
c=0
for i in l:
    if(i=='Tetrahedron'):
        c=c+4
    elif(i=='Octahedron'):
        c=c+8
    elif(i=='Cube'):
        c=c+6
    elif(i=='Dodecahedron'):
        c=c+12
    else:
        c=c+22
print(c)
    