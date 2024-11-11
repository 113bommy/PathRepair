mod = 10**9 + 7
N = int(input())
T = list(map(int, input().split()))
A = list(map(int, input().split()))

Min = [1] * N
Max = [float("inf")] * N
tp = 0
for i, t in enumerate(T):
    if t != tp:
        Min[i] = max(Min[i], t)
    Max[i] = min(Max[i], t)
    tp = t
ap = 0
for i, a in zip(range(N-1, -1, -1), A[::-1]):
    if a != ap:
        Min[i] = max(Min[i], a)
    Max[i] = min(Max[i], a)
    ap = a
ans = 1
for mi, ma in zip(Min, Max):
    ans = ans * max(ma-mi+1, 0) % mod
print(ans)
