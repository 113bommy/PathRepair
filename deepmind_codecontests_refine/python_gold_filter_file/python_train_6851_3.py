L = int(input())
A = [int(input()) for i in range(L)]

Asum = [0]
for i, a in enumerate(A):
    Asum.append(Asum[i] + a)

Emin = [0 for i in range(L + 1)]
Zmin = [0 for i in range(L + 1)]

for i in range(L)[:: -1]:
    a = A[i]
    if a == 0:
        Emin[i] = 2 + Emin[i + 1]
        Zmin[i] = 1 + min(Emin[i + 1], Zmin[i + 1])
    elif a % 2 == 0:
        Emin[i] = Emin[i + 1]
        Zmin[i] = 1 + min(Emin[i + 1], Zmin[i + 1])
    else:
        Emin[i] = 1 + Emin[i + 1]
        Zmin[i] = min(Emin[i + 1], Zmin[i + 1])
    Emin[i] = min(Emin[i], Asum[L] - Asum[i])
    Zmin[i] = min(Zmin[i], Asum[L] - Asum[i])


A.reverse()

Asum = [0]
for i, a in enumerate(A):
    Asum.append(Asum[i] + a)

Emin2 = [0 for i in range(L + 1)]
Zmin2 = [0 for i in range(L + 1)]

for i in range(L)[:: -1]:
    a = A[i]
    if a == 0:
        Emin2[i] = 2 + Emin2[i + 1]
        Zmin2[i] = 1 + min(Emin2[i + 1], Zmin2[i + 1])
    elif a % 2 == 0:
        Emin2[i] = Emin2[i + 1]
        Zmin2[i] = 1 + min(Emin2[i + 1], Zmin2[i + 1])
    else:
        Emin2[i] = 1 + Emin2[i + 1]
        Zmin2[i] = min(Emin2[i + 1], Zmin2[i + 1])
    Emin2[i] = min(Emin2[i], Asum[L] - Asum[i])
    Zmin2[i] = min(Zmin2[i], Asum[L] - Asum[i])

ans = 3000000
for i in range(L):
    ans = min(ans, min(Emin[i], Zmin[i]) + min(Emin2[L - i], Zmin2[L - i]))

print(ans)