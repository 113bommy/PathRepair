N,K = map(int,input().split())
a = list(map(int,input().split()))

ans = 10**9
for i in range(2**N):
    if bin(i).count('1')!=K:
        continue
    cost = 0
    now = 0
    for j in range(N):
        if i>>j&1:
            if now>=a[j]:
                cost += now-a[j]+1
                now += 1
            else:
                now = a[j]
        else:
            now = max(now,a[j])
    ans = min(ans,cost)
print(ans)

