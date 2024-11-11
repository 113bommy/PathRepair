t=int(input())
for _ in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    l.sort()
    k=[]
    for i in range(n):
        k.append([0]*201)
    for i in range(n-1,-1,-1):
        if i==n-1:
            for j in range(n,201-n+(i+1)):
                k[i][j]=abs(l[i]-j)
            for j in range(201-n+(i+1)-2,n-1,-1):
                k[i][j] =min(k[i][j],k[i][j+1])
                
        else:
            for j in range(i+1,201-n+(i+1)):
                k[i][j] = abs(l[i]-j)+k[i+1][j+1]
            
            for j in range(201-n+(i+1)-2,i,-1):
                k[i][j] =min(k[i][j],k[i][j+1])
    ans=1000000000000000
    for i in range(1,202-n):
        ans=min(ans,k[0][i])
    print(ans)
        
