N, K = map(int, input().split())
*A, = map(int, input().split())

L = []
for i in range(N):
    v = A[i]
    L.append(v)
    for j in range(i+1, N):
        v += A[j]
        L.append(v)
ans = 0
for i in range(32):
    b = 1 << (31-i)
    c = 0
    R = []
    for j in range(len(L)):
        if b & L[j]:
            R.append(L[j])
    if len(R) >= K:
        L = R
        ans |= b
print(ans)
