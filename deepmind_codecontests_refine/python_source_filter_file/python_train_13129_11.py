t = int(input())
INF = 10000000000
for t_num in range(t):
    n, start, end, d = map(int, input().split())
    ans = INF
    if (end - start) % d == 0:
        ans = min(ans, (end - start) // d)
    if (n - end) % d == 0:
        ans = min(ans, (n - end) // d + (n - start + d - 1) // d)
    if (end - 1) % d == 0:
        ans = min(ans, (end - 1) // d + (start - 1 + d - 1) // d)

    if (ans == INF):
        print(-1)
    else:
        print(ans)
