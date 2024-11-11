N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

v = [[0, 0] for _ in range(N)]
s = []
ans = 500

for i in range(1<<N):
    tmp = 0
    for j in range(N):
        if ((i>>j)&1): v[j] = [B[j], j]
        else:          v[j] = [A[j], j]
    for j in range(N):
        p = j
        while (p and v[p][0] < v[p-1][0]):
            v[p], v[p-1] = v[p-1], v[p]
            tmp += 1
            p -= 1
    for j in range(N):
        if (((i>>v[j][1])+v[j][1]-j)&1):
            s.append(v[j][0]*500+j)
    if (len(s)&1):
        tmp = 500
        s.pop()
    while s:
        p = s.pop()
        q = s.pop()
        if ((p-q)&1): tmp += p-q
        else:         tmp += 500
    ans = min(ans, tmp)

if ans < 500:
    print(ans)
else:
    print(-1)
