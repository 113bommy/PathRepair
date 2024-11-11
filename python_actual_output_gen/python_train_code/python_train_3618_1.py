n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
di={}
for x in a:
    if x in di:
        di[x]+=1
    if x not in di:
        di[x]=1
ans=0
gb=[]
for k in di:
    if di[k]>1:
      gb.append(k)
for i in range(n):
    if di[a[i]]>1:
           ans+=b[i] 
           continue
    for k in gb:
        if a[i]<k:
            ans+=b[i]
            break
print(ans)
        
    
        
