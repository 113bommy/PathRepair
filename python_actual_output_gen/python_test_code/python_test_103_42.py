no_poly=int(input())
count=0
for i in range(no_poly):
    shape_name=input()
    if shape_name=='Tetrahedron':
        count+=4
    if shape_name=='Cube':
        count+=3
    if shape_name=='Octahedron':
        count+=8
    if shape_name=='Dodecahedron':
        count+=12
    if shape_name=='Icosahedron':
        count+=20
print(count)