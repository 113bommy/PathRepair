from collections import Counter
N, P = map(int, input().split())
S = input()

if 10 % P == 0:
    ans = 0
    for i, s in enumerate(S, start=1):
        if int(s) % P != 0:
            continue
        ans += i
    print(ans)

else:
    X = [0]
    for i, s in enumerate(S[::-1]):
        X.append((X[-1] + pow(10, i, P) * int(s)) % P)

    C = Counter(X)
    ans = 0
    for v in C.values():
        ans += v * (v - 1) // 2
    print(ans)
