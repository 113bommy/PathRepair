def solve(n, m, p):
    tot = 0
    a = 0
    for i in range(n):
        x = int(input())
        tot += 100 * x
        if i == m-1: a = x

    if a == 0:
        print(0)
        return

    tot = tot * (100-p) / 100.0
    ans = int(tot / a)
    print(ans)


while 1:
    n, m, p = map(int, input().split())
    if n == 0: break
    solve(n, m, p)