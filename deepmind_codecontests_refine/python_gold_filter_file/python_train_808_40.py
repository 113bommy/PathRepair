n = int(input())
a = [int(i) for i in input().split()]
mod = 10**9+7
ans = 0
for i in range(60):
    cnt = 0
    for j in range(n):
        if a[j]>>i & 1 == 0: cnt += 1
    ans = (ans+pow(2,i,mod)*cnt%mod*(n-cnt)%mod)%mod
print(ans)