n,k=map(int,input().split())
ans = 0
anss = 1
if (n == k) and ( k == 0):
    anss = 0
    ans = 0
else:
    if (3*k <= n):
        anss =1
        ans = 2*k
    else:
        anss = 1
        ans = n-k
    
print(anss,ans)
