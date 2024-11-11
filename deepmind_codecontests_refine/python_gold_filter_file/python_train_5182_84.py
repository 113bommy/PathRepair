n, k = map(int, input().split())
p = [0] + list(map(int, input().split()))
c = [0] + list(map(int, input().split()))

score_cnt = [None] * (n + 1)
for i in range(1, n + 1):
    now = i
    cnt = 0
    score = 0
    for _ in range(n):
        now = p[now]
        score += c[now]
        cnt += 1
        if now == i:
            score_cnt[i] = [score, cnt]
            break

ans = - 10 ** 20
for i in range(1, n + 1):
    now = i
    score = 0
    left = k
    for j in range(n):
        now = p[now]
        score += c[now]
        left -= 1
        if left >= 0:
            times = left // score_cnt[now][1]
            score_loop = score + times * score_cnt[now][0]
            ans = max(ans, score, score_loop)

print(ans)
