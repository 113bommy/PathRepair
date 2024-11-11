a=int(input())
s=0
for i in range(0,a):
    b=input()
    if(b=="tetrahedron"):
        s=s+4
    elif(b=="cube"):
        s=s+6
    elif(b=="octahedron"):
        s=s+8
    elif(b=="dodecahedron"):
        s=s+12
    elif(b=="icosahedron"):
        s=s+20
print(s)
        
