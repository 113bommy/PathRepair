N, M = map(int, input().split())
a, b, c = [0] * M, [0] * M, [0] * M
d = [-1e20] * N
for i in range(M):
    a[i], b[i], c[i] = map(int, input().split())
    a[i] -= 1
    b[i] -= 1

d[0] = 0
for i in range(N-1):
    for j in range(M):
        d[b[j]] = max((d[b[j]], d[a[j]] + c[j]))

isCycle = False
for i in range(N-1):
    if isCycle:
        break
    for j in range(M):
        if j == N-1 and d[b[j]] < d[a[j]] + c[j]:
            isCycle = True
            break
        d[b[j]] = max((d[b[j]], d[a[j]] + c[j]))
if isCycle:
    print('inf')
else:
    print(d[N-1])
