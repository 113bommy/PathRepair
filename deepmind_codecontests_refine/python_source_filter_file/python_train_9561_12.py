N, K = map(int, input().split())
S = []
T = []
A = []
for i in range(N):
    x, y = map(int, input().split())
    S.append(x)
    T.append(y)
    A.append([x, y])

S.sort()
T.sort()
ans = float("inf")
for i in range(N):
    for j in range(i+1, N):
        for k in range(N):
            for l in range(i+1, N):
                c = 0
                for x, y in A:
                    if S[i] <= x <= S[j]:
                        if T[k] <= y <= T[l]:
                            c += 1
                if c >= K:
                    ans = min(ans, (S[j] - S[i])*(T[l] - T[k]))
print(ans)