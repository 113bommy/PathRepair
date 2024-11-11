n,m,k = map(int,input().split())
ans = -1
if n>=k+1:
    ans = max(ans,n//(k+1)*m)
elif m>=k-n+2:
    ans=max(ans,m//(k-n+2))

n,m = m,n

if n>=k+1:
    ans = max(ans,n//(k+1)*m)
elif m>=k-n+2:
    ans=max(ans,m//(k-n+2))

print(ans)
