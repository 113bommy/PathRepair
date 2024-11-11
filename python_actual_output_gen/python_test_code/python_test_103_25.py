n=int(input())
f=0
for i in range(n):
    x=input()
    if x=='tetrahedron':  
        f=4+f
    elif x=='cube':
        f=6+f
    elif x=='octahedron':
        f=8+f
    elif x=='dodecahedron':
        f=12+f
    elif x=='icosahedron':
        f=20+f
print(f)    
    