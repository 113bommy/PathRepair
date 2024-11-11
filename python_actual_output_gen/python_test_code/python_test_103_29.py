Tetrahedron=4
Cube=4
Octahedron=8
Dodecahedron=12
Icosahedron=20
li=[]
x=int(input())
for i in range(x):
    z=input()
    li.append(z)

for i in range(x):
    if li[i]=='Tetrahedron':
        li[i]=4
    elif li[i]=='Octahedron':
        li[i]=8
    elif li[i]=='Cube':
        li[i]=4
    elif li[i] == 'Dodecahedron':
        li[i] = 12
    elif li[i] == 'Icosahedron':
        li[i] = 20


t=sum(li)
print(t)

