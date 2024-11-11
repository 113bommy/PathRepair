N, K = map(int, input().split())
A = sorted(list(map(int, input().split())))
F = sorted(list(map(int, input().split())), reverse=True)

minT, maxT = -1, max([A[i] * F[i] for i in range(N)])
while maxT - minT > 1:
    midT = minT + (maxT - minT) // 2
    if sum([A[i] - midT // F[i] for i in range(N)]) > K:
        minT = midT
    else:
        maxT = midT

print(maxT)
