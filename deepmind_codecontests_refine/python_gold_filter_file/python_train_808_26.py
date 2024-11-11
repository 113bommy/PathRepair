n = int(input())
a = list(map(int,input().split()))
cnt = [0]*(66)
for num in a:
    for j in range(60):
        cnt[j] += (num >> j)%2
ans = 0
for b in range(60):
    ans += (cnt[b]*(n-cnt[b])) << b
    ans %= 10**9+7
print(ans)