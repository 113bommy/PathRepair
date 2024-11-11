N = int(input())
S = input()
Q = int(input())
K = [int(i) for i in input().split()]

for k in K:
    ans = 0

    d = m = dm = 0
    for i, si in enumerate(S):
        if 0 <= i - k:
            if S[i - k] == "D":
                d -= 1
                dm -= m
            elif S[i - k] == "M":
                m -= 1

        if si == "D":
            d += 1
        elif si == "M":
            m += 1
            dm += d
        elif si == "C":
            ans += dm

    print(ans)