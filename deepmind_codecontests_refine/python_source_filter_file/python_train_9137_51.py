from collections import Counter

N, P = map(int, input().split())
S = input()

ans = 0

if P == 2 or P == 5:
    for i in range(N):
        if int(S[-1 - i]) % 2 == 0:
            ans += N - i
else:
    M = []
    cum = [0]

    for i in range(N):
        M.append(pow(10, i, P) * int(S[-1 - i]) % P)

    for i in range(N):
        cum.append((cum[-1] + M[i]) % P)

    C = Counter(cum)

    for v in C.values():
        ans += v * (v - 1) // 2

print(ans)