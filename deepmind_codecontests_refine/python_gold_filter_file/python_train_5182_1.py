n, k = map(int, input().split())
P = list(map(lambda x:int(x)-1, input().split()))
C = list(map(int, input().split()))
D = [-1]*n
ans = -float("inf")
for i, p in enumerate(P):
    ans = max(ans, C[p])
    temp = p
    res = C[p]
    cnt = 1
    while temp != i and cnt < k:
        temp = P[temp]
        res += C[temp]
        cnt += 1
        ans = max(ans, res)
    D[i] = (cnt, res)
for i in range(n):
    a, b = D[i]
    ans = max(ans, b)
    if a == k:
        continue
    if b < 0:
        continue
    temp = b * (k//a-1)
    rest = k%a+a
    now = i
    for _ in range(rest):
        now = P[now]
        temp += C[now]
        ans = max(ans, temp)
print(ans)