n,m,K = map(int,input().split())
ans = "No"

for k in range(n):
    for l in range(m):
        if k*(m-l)+(n-k)*l == K: 
            ans = "Yes"  
            break

print(ans)