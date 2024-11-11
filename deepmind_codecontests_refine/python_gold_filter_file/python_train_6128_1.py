from collections import deque
N = int(input())
C = []
M = {}
for i in range(N):
    *c, = map(int, input().split())
    c = tuple(min(c[j:] + c[:j] for j in range(1, 5)))
    C.append(c)
    if c not in M:
        M[c] = deque([i])
    else:
        M[c].append(i)
def count(p, q, r, s):
    if p == q == r == s:
        return 4
    if p == r and q == s:
        return 2
    return 1
def solve(ci, cj, k):
    R = {}
    for l in range(4):
        #  [l]   [l-1]
        # [l+k] [l+k+1]
        c = ci[l], ci[l-1], cj[k-l], cj[k-l-1]
        c = tuple(min(c[j:] + c[:j] for j in range(1, 5)))
        if c not in M:
            return 0
        R[c] = R.get(c, 0) + 1
    res = 1
    for c in R:
        m = M[c]
        cnt = len(m)
        if c == cj:
            cnt -= 1
        if cnt < R[c]:
            return 0
        k = count(*c)
        for p in range(cnt-R[c]+1, cnt+1):
            res *= p * k
    return res

ans = 0
for i in range(N):
    ci = C[i]
    q = M[ci]; q.popleft()
    if not q:
        del M[ci]
    for j in range(i+1, N):
        cj = C[j]
        for k in range(4):
            ans += solve(ci, cj, k)
print(ans)
