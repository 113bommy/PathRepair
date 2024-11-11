n=int(input())
sum1=0
for _ in range(n):
    s=input()
    if(s=="Tetrahedron"):
        sum1+=4
    if(s=="Cube"):
        sum1+=6
    if(s=="Octahedron"):
        sum1+=8
    if(s=="Dodecahedron"):
        sum1+=12
    else:
        sum1+=20
print(sum1)

    
        
        