import heapq
N, K, Q = [int(_) for _ in input().split()]
A = [int(_) for _ in input().split()]
sA = sorted(set(A))
A += [-1]
ans = float('inf')

for amin in sA:
    cand = []
    fr = 0
    to = -1
    for i in range(N + 1):
        a = A[i]
        if a >= amin:
            if fr == -1:
                fr = i
        elif a < amin and fr >= 0:
            cand += sorted(A[fr:i])[:max(0, i - fr - K + 1)]
            fr = -1
    if len(cand) < Q:
        break
    ans = min(ans, cand[Q - 1] - amin)
print(ans)
