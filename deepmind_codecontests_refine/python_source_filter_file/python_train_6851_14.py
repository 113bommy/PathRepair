L = int(input())
B = [int(input()) for _ in range(L)]

A = []
for b in B:
    if b % 2:
        A.append(1)
    else:
        A.append(0 if b == 0 else 2)

dpLBack = [10**10] * (L + 1)
dpLBack[0] = 0
cnt = 0
for i, a in enumerate(A, start=1):
    cnt += B[i - 1]
    dpLBack[i] = min(dpLBack[i - 1] + 2 - a, cnt)

dpL = [10**10] * (L + 1)
dpL[0] = 0
cnt = 0
for i, a in enumerate(A, start=1):
    cnt += B[i - 1]
    dpL[i] = min(dpL[i - 1] + (a != 1), dpLBack[i - 1] + (a == 0), cnt)

dpRBack = [10**10] * (L + 1)
dpRBack[0] = 0
cnt = 0
for i, a in enumerate(A[:: -1], start=1):
    cnt += B[-i]
    dpRBack[i] = min(dpRBack[i - 1] + 2 - a, cnt)

dpR = [10**10] * (L + 1)
dpR[0] = 0
cnt = 0
for i, a in enumerate(A, start=1):
    cnt += B[-i]
    dpR[i] = min(dpR[i - 1] + (a != 1), dpRBack[i - 1] + (a == 0), cnt)

dpR = dpR[:: -1]
dpRBack = dpRBack[::-1]

ans = min(dpL[L], dpR[0])
for mid in range(L + 1):
    ans = min(ans, dpL[mid] + dpRBack[mid], dpLBack[mid] + dpR[mid], dpLBack[mid] + dpRBack[mid])

print(ans)
