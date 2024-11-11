N, K = map(int, input().split())
P = [x-1 for x in map(int, input().split())]
C = list(map(int, input().split()))

ans = -100_000_000_000
for i in range(N):
    n = 0
    socre_sum = 0
    now = i
    while True:
        n += 1
        socre_sum += C[now]
        now = P[now]
        if i == now:
            break
    score = 0
    now = i
    for j in range(1, n+1):
        score += C[now]
        now = P[now]
        if j > K:
            break
        ans = max(ans, score+max(0, socre_sum)*(K-j)//n)
print(ans)