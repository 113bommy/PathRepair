N = int(input())
S = input()
Q = int(input())
query = tuple(map(int, input().split()))

for k in query:
    D = 0
    M = 0
    DM = 0
    res = 0
    for i, s in enumerate(S):
        if i >= k:
            if S[i - k] == "D":
                DM -= M
                D -= 1
            elif S[i - k] == "M":
                M -= 1
        if s == "D":
            D += 1
        elif s == "M":
            M += 1
            DM += D
        elif s == "C":
            res += DM
    print(res)