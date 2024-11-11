for _ in range(int(input())):
    n, r = map(int, input().split())
    tot = 0
    if r >= n:
        tot += 1
    m = min(r, n - 1)
    print(m * (m + 1) // 2 + tot)