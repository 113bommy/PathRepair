N, K = map(int, input().split())
A = list(map(int, input().split()))

mi = 1
ma = 10**9
while(ma - mi != 1):
    c = 0
    mid = (ma + mi) // 2
    for i in range(N):
        c += A[i] // mid - (A[i] % mid == 0)
    if c > K:
        mi = mid
    else:
        ma = mid
print(ma)