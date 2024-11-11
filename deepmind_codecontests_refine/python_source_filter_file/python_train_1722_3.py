N, K = map(int, input().split())
A = [int(n) for n in input().split()]
B = [int(n) for n in input().split()]
l = 1
r = max(A)*K
ans = 0

while l <= r:
    temp = K
    mid = (l + r) // 2
    for i in range(N):
        if B[i] < (mid * A[i]):
            temp -= (mid * A[i] - B[i])

    if temp < 0:
        r = mid - 1
    else:
        ans = mid
        l = mid + 1
print(ans)