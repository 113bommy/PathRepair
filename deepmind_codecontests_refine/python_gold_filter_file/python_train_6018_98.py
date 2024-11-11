S = input()
N = len(S)
su = 0
L = [0]*13
L[0] = 1
M = [1, 10, 9, 12, 3, 4]
mod = 10**9+7
for i, c in enumerate(S[::-1]):
    m = M[i % 6]
    if c=="?":
        Lc = L[:]
        for j in range(m, m*10, m):
            for k in range(13):
                idx = (k+j)%13
                L[idx] = (L[idx] + Lc[k]) % mod
    else:
        su += int(c) * m
print(L[(-su+5)%13])
