MOD = 1000000007

n = int(input())
a = list(map(int,input().split()))

ans = 0
for k in range(60):
    mask = 1<<k
    cnt1 = sum(1 for x in a if x&mask != 0)
    ans += cnt1*(n-cnt1)*(1<<k)
print(ans)