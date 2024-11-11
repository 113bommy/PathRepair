n, p = map(int, input().split())
s = input()

if 10%p==0:
    ans = 0
    for r in range(n):
        if int(s[r])%p == 0:
            ans += r+1
    print(ans)
    exit()

d = [0]*(n+1)
ten = 1

for i in range(n-1, -1, -1):
    a = int(s[i])*ten%p
    d[i] = (d[i+1]+a)%p
    ten *= 10
    ten %= p

cnt = [0]*p
ans = 0
for i in range(n, -1, -1):
    ans += cnt[d[i]]
    cnt[d[i]] += 1
print(ans)