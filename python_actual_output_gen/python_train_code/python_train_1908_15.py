n,m,K = map(int,input().split())
ans = "No"

for k in range(1,n+1):
    for l in range(1,m+1):
        if k*(m-l)+(n-k)*l == K: 
            ans = "Yes"  
            break

print(ans)