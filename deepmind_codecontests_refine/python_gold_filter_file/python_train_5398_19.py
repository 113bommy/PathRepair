N,K = map(int,input().split())
a = [int(i) for i in input().split()]
ans = float("INF")
for i in range(1<<N):
    cnt = 0
    tmp = a[:]
    m = tmp[0]
    for j in range(1,N):
        if i >> j & 1 and m >= tmp[j]:
            cnt += m - tmp[j] + 1
            tmp[j] = m + 1
        m = max(m,tmp[j])
    color = 1
    m = tmp[0]
    for j in range(1,N):
        if tmp[j] > m:
            color += 1
            m = tmp[j]
    if color >= K: ans = min(ans,cnt)
print(ans)