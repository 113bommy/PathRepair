n=int(input())
s=list(map(int,input().split()))
k=sorted(s)
nod=0
i=0
while(i<n and nod<=2):
    if s[i]!=k[i]:
        nod+=1
    i+=1
if nod<=2:
    print("YES")
else:
    print("NO")
    

    
            
        
        
        
