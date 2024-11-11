n=int(input());t=0
for i in range(n):
    s=input()
    if s=='Tetrahedron':t+=4
    elif s=='Cube':t+=6
    elif s=='Octahedron':t+=8
    elif s=='Dodecahedron':t+=12
    else:t+=20
