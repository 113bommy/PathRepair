N = int(input())
mod = 10**9+7
ans = 1
num = [0]*N
for i in range(1,N+1):
    for j in range(2,i+1):
        while i % j == 0:
            i //= j
            num[j-1] += 1
for i in range(N):
    if num[i] == 0:
        continue
    else:
        ans = ans * (num[i]+1) % mod
print(ans)