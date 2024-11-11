n = int(input())
S = [int(x) for x in input().split()]
s = tuple(S)
c = tuple(int(x) for x in input().split())
S.sort()
def min(x, y):
    if x < y:
        return x
    else:
        return y
def rank(x):
    l = 0; r = n - 1
    while l < r:
        mid = (l + r) >> 1
        if S[mid] < x:
            l = mid + 1
        else:
            r = mid
    return l
rk = tuple(rank(x) for x in s)
Min = [10000000000 for i in range(30000)]
def insert(x, l, r, p, v):
    Min[x] = min(Min[x], v)
    if l == r:
        return
    mid = (l + r) >> 1
    if p > mid:
        insert(x << 1 | 1, mid + 1, r, p, v)
    else:
        insert(x << 1, l, mid, p, v)
def query(x, l ,r ,L ,R):
    if l >= L and r <= R:
        return Min[x]
    mid = (l + r) >> 1; ans = 10000000000
    if L <= mid:
        ans = min(ans, query(x << 1, l, mid, L, R))
    if R > mid:
        ans = min(ans, query(x << 1 | 1, l, mid, L, R))
    return ans
dp = list(c)
Min = [10000000000 for i in range(30000)]
for i in range(0, n):
    insert(1, 0, n - 1, rk[i], dp[i])
    dp[i] = c[i]
    if rk[i] == 0:
        dp[i] += 10000000000
    else:
        dp[i] += query(1, 0, n - 1, 0, rk[i] - 1)
Min = [10000000000 for i in range(30000)]
for i in range(0, n):
    insert(1, 0, n - 1, rk[i], dp[i])
    dp[i] = c[i]
    if rk[i] == 0:
        dp[i] += 10000000000
    else:
        dp[i] += query(1, 0, n - 1, 0, rk[i] - 1)
ans = 10000000000
for i in dp:
    ans = min(ans, i)
if ans > 3000000000:
    print(-1)
else:
    print(ans)