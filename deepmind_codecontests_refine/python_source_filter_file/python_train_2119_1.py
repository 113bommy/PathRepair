n,d=map(int,input().split())
a,b=map(int,input().split())
req=[] 
for i in range(n):
    x,y=map(int,input().split())
    req.append([x,y,i])
ans=[]
req.sort(key=lambda x:[x[1],x[0]])
for i in range(n):
    curr= req[i][0]*a+req[i][1]*b 
    if d>=curr:
        ans.append(req[i][2]+1)
        d-=curr 
    else:
        break 
print(len(ans))
print(*ans)
