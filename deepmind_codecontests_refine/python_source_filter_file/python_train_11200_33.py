n = int(input())

polyhedron=[]
for i in range(n):

    polyhedron.append(input())

count=0

for poly in polyhedron:

    if poly=="Tetrahedron":
        count+=4
    
    elif poly=="Cube":
        count+=6
    
    elif poly=="Octahedron":
        count+=8

    elif poly=="Dodecahedron":
        count+=8
    
    else:
        count+=20



print(count)