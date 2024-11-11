n1=int(input())
s=0
for i in range(n1):
     n=input()
     
     if(n=="Tetrahedron"):
          s+=4
     if(n=="Cube"):
          s+=6
     if(n==" Octahedron"):
          s+=8
     if(n=="Dodecahedron"):
          s+=12    
     if(n=="Icosahedron"):
          s+=20
print(s)          