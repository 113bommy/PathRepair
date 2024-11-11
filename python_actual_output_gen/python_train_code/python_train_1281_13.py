R = lambda: map(int, input().split())
n, p, q, r = R()
arr = list(R())
lmi, lmx, rmi, rmx = arr[:], arr[:], arr[:], arr[:]
for i in range(1, n):
    lmi[i] = min(lmi[i], lmi[i - 1])
    lmx[i] = max(lmx[i], lmi[i - 1])
for i in range(n - 2, -1, -1):
    rmi[i] = min(rmi[i], rmi[i + 1])
    rmx[i] = max(rmx[i], rmx[i + 1])
print(max(max(lmi[i] * p, lmx[i] * p) + arr[i] * q + max(rmi[i] * r, rmx[i] * r) for i in range(n)))