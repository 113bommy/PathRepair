n, k = map(int, input().split())

jump = 2 * k + 1

for i in range(1, n + 1):
    offset = i
    while offset + jump <= n:
        offset += jump
    if offset + k >= n:
        ans = []
        for idx in range(i, n + 1, jump):
            ans.append(idx)
        print(len(ans))
        print(*ans)
        exit(0)
