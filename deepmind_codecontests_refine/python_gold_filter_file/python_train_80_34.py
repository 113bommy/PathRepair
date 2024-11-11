N, M = map(int,input().split())
a = [1] * (N+1)
for i in range(M):
    a[int(input())] = 0
mod = 1000000007
ans = [0] * (N+1)
ans[0] = 1
for i in range(1,N+1):
     ans[i] = (ans[i-2]*a[i-2] + ans[i-1]*a[i-1]) % mod
print(ans[N])