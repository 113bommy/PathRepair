from heapq import heappush, heappop, heappushpop
N = int(input())
*A, = map(int, input().split())

def update(v, que):
    p, q = que
    if v == p or v == q:
        return
    heappushpop(que, v)

memo = [None]*(2**N)
memo[0] = [(0, -1), (A[0], 0)]
ma = 0; ans = []
for i in range(1, 2**N):
    res = [(0, -1), (A[i], i)]
    for j in range(N):
        if (i >> j) & 1 == 0:
            continue
        p, q = memo[i ^ (1 << j)]
        update(p, res)
        update(q, res)
    p, q = memo[i] = res
    ma = max(ma, p[0] + q[0])
    ans.append(ma)
print(*ans, sep='\n')
