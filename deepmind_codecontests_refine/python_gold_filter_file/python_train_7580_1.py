N = int(input())
L = []
C = []
A = []
b = w = 0
b_d = {}
w_d = {}
for i in range(2*N):
    c, a = input().split()
    a = int(a)
    n = 0
    for cc, aa in zip(C, A):
        if cc == c and aa > a:
            n += 1
    L.append([0] * (N + 1))
    cnt = 0
    for j in range(N, -1, -1):
        L[-1][j] = cnt+n
        if j in (b_d if c=="W" else w_d):
            cnt+=1

    if c=="B":
        b_d[a] = i
        b+=1
    else:
        w_d[a] = i
        w+=1
    C.append(c)
    A.append(a)
#print(L, b_d, w_d)

dp = [[0]*(N+2) for i in range(N+2)]
for i in range(N+1):
    for j in range(N+1):
        if i==j==0:
            continue
        if i==0:
            dp[i][j] = dp[i][j-1] + L[b_d[j]][i]
        elif j==0:
            dp[i][j] = dp[i-1][j] + L[w_d[i]][j]
        else:
            dp[i][j] = min(dp[i-1][j] + L[w_d[i]][j],
                           dp[i][j-1] + L[b_d[j]][i])
print(dp[-2][-2])
