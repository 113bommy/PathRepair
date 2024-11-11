N,K= map(int, input().split())
P = list(map(int, input().split()))
C = list(map(int, input().split()))
ans = -1000000000

for i in range(N):
    S = []
    j = P[i]-1
    S.append(C[j])

    while i != j:
        j = P[j]-1
        S.append(S[-1] + C[j])

    if K <= len(S):
        score = max(S[:K])

    elif S[-1] <= 0:
        score = max(S)
    
    else:
        score1 = K//len(S) * S[-1]
        r = K%len(S)
        if r != 0:
            score1 += max(0, max(S[:r]))
        score2 = (K//len(S)-1)*S[-1] + max(S)
        score = max(score1, score2)
    ans = max(ans, score)
print(ans)