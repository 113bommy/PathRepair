N, K = map(int, input().split())
P = list(map(int, input().split()))
C = list(map(int, input().split()))
 
ans = -float('inf')
for s in range(N):
    S = [] 
    i = P[s] - 1
    S.append(C[i])
    while i != s:
        i = P[i] - 1
        S.append(S[-1] + C[i])
 
    if K <= len(S):
        score = max(S[:K])
    elif S[-1] <= 0:
        score = max(S)
    else:
        score1 = S[-1] * (K // len(S) - 1)
        score1 += max(S)
        score2 = S[-1] * (K // len(S))
        r = K % len(S)
        if r != 0:
            score2 += max(0, max(S[:r]))
        score = max(score1, score2)
 
    ans = max(ans, score)
 
print(ans)