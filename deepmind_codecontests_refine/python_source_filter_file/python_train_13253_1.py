def solution():
    inp = input().split()
    n,m,k = int(inp[0]), int(inp[1]), int(inp[2])
    mod = 10**9 + 7
    if k == 1 or k > n:
        sol = pow(m, n, mod)
    elif k == n:
        sol = pow(m, (n + 1) // 2, mod)
    elif k % 2 == 1:
        sol = pow(m, 2)
    elif k % 2 == 0:
        sol = m
    print(m)

solution()
