N, K = map(int, input().split())
P = [0] + list(map(int, input().split()))
C = [0] + list(map(int, input().split()))

ans = -10 ** 9
for i in range(1, N + 1):
    start = i
    next_ = start
    loop_score = 0
    loop_count = 0
    while True:
        loop_count += 1
        loop_score += C[next_]
        next_ = P[next_]
        if next_ == start:
            break
    in_score = 0
    in_count = 0

    for k in range(K):
        in_count += 1
        in_score += C[next_]

        loop_num = (K - in_count) // loop_count
        score = in_score + max(0, loop_score) * loop_num
        ans = max(ans, score)

        next_ = P[next_]
        if next_ == start:
            break

print(ans)
