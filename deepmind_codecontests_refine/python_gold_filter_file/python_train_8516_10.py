N = int(input())
S = list(input())
Q = int(input())
K = list(map(int,input().split()))
DP = [[0,0,0]]
C = []
for i in range(N):
    q = DP[i][:]
    if S[i] == "D":
        q[0] += 1
    elif S[i] == "M":
        q[1] += 1
        q[2] += q[0]
    elif S[i] == "C":
        C.append(i+1)
    DP.append(q)

for k in K:
    ans = 0
    for c in C:
        if c < k:
            ans += DP[c][2]
        else:
            ans += DP[c][2] - DP[c-k][2] - DP[c-k][0]*(DP[c][1] - DP[c-k][1])
    print(ans)