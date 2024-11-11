from itertools import accumulate 

N, K = list(map(int, input().split()))
P = list(map(lambda x: int(x) - 1, input().split()))
C = list(map(int, input().split()))

ans = -10**18-1
seen = [False]*N
for i in range(N):
    if seen[i]:
        continue
    loop = []
    now = i
    while seen[now] == False:
        seen[now] = True
        loop.append(C[now])
        now = P[now]
    loop_size = len(loop)
    loop_score = sum(loop)
    cumsum = [0]+list(accumulate(loop+loop))
    for j in range(1, loop_size+1):
        for l in range(loop_size+1):
            r = l+j
            subseq = cumsum[r] - cumsum[l]
            ans = max(ans, subseq, subseq+loop_score*((K-j)//loop_size))
print(ans)