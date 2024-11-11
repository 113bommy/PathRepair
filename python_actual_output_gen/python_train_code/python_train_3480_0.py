n=int(input())
a=list(map(int,input().split()))
req=[]
ans=[0]*n
for i in range(n):
    req.append([n-1-a[i],i])
req.sort()

val=0
i=0
f=1
while(i<n):
    val+=1 
    x=req[i][0]
    if i+x+1>=n:
        f=0
        break
    for j in range(i,i+x+1):
        
        
        if req[j][0]!=x:
            f=0
            break
        else:
            ans[req[j][1]]=val
    if f==0:
        break
    i+=(x+1)
if f==0:
    print("Impossible")
else:
    print("Possible")
    print(*ans)
    
            
    
    