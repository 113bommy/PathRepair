
n,m = map(int,input().split())
lp = []
dg = [0]*(n+1)
for _ in range(m):
    a,b = map(int,input().split())
    lp.append((a,b))
    dg[a] +=1
    dg[b] += 1
ans = 0
while True:
    
    z = 0
    q = []
    for i in lp:
        if dg[i[0]]==1 or dg[i[1]]==1:
            q.append(i)
            z =1
    if z==0:
        break
    else:
        ans+=1
        for x in q:
            lp.remove(x)
            dg[x[0]] = 0
            dg[x[1]] -= 1
           
    
    
print(ans)

    
    
    
    

    
    
    
        
