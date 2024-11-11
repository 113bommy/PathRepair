N = int(input())
P = 998244353

ANS = []
for i in range(1, N):
    a = 0
    if N - i >= 2: a += (N - i - 1) * 81 * pow(10, N-i-1, P)
    if N - i >= 1: a += 2 * 9 * pow(10, N-i, P)
    ANS.append(a)

ANS.append(10)
print(*ANS)
