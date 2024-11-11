def solve(n):
    t, f, s = n // 3, 0, 0
    if n % (3 * t) == 1:
        if t < 2:
            return -1, -1, -1
        else:
            return t - 2, 0, 1
    elif n % (3 * t) == 2:
        if t < 1:
            return -1, -1, -1
        else:
            return t - 1, 1, 0
    else:
        return t, 0, 0

t = int(input())
for i in range(t):
    n = int(input())
    if n in [1, 2, 4]:
        print(-1)
    else:
        k,m,n = solve(n)
        if k == -1:
            print(-1)
        else:
            print(f"{k} {m} {n}")
    
    