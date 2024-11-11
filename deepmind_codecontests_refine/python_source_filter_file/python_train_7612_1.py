n, L, R = map(int, input().split())
q = 10 ** 9 + 7
u0 = [0] * n
u1 = [0] * n
u2 = [0] * n
k = (R - L + 1) // 3
c0 = k; c1 = k; c2 = k
if (R - L + 1) % 3 != 0:
    if R % 3 == 0: c0 += 1
    elif R % 3 == 1: c1 += 1
    else: c2 += 1
    if (R - L + 1) % 3 == 0:
        if L % 3 == 0: c0 += 1
        elif L % 3 == 1: c1 += 1
        else: c2 += 1
u0[0] = c0; u1[0] = c1; u2[0] = c2
##print(u0)
##print(u1)
##print(u2)
for i in range(1, n):
    u0[i] = (u0[i-1] * c0 % q + u1[i-1] * c2 % q + u2[i-1] * c1 % q) % q
    u1[i] = (u0[i-1] * c1 % q + u1[i-1] * c0 % q + u2[i-1] * c2 % q) % q
    u2[i] = (u0[i-1] * c2 % q + u1[i-1] * c1 % q + u2[i-1] * c0 % q) % q
##    print(u0)
##    print(u1)
##    print(u2)
print(u0[n - 1])
