N, M = map(int, input().split())
A = sorted(list(map(int, input().split())), reverse=True)

nA, sA, i = [N, N], [0],  N - 1
for a in range(1, A[0] * 2):
    di = 0
    while i - di >= 0 and A[i - di] == a:
        di += 1
    nA.append(nA[-1] - di)
    i -= di
for a in A:
    sA.append(sA[-1] + a)

L, R, ans = 0, A[0] * 2, 0
while R - L > 1:
    mid = L + (R - L) // 2
    mA = [nA[max(mid - A[i], 0)] for i in range(N)]
    sM = sum(mA)
    if M <= sM:
        L = mid
        ans = sum([A[i] * mA[i] + sA[mA[i]]
                   for i in range(N)]) - mid * (sM - M)
    else:
        R = mid

print(ans)
