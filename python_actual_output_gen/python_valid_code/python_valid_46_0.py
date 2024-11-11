n,m,ta,tb,k = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
if min(n,m)<=k:
    print(-1)
else:
    j=ans=0
    for i in range(k+1):
        while j<m and a[i]+ta>b[j]:
            j+=1
        if j+k-i>=m:
            print(-1)
            exit()
        ans = max(ans,b[j+k-1]+tb)
    print(ans)





