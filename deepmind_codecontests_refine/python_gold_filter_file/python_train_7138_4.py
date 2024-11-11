def f(n):
    x = 0
    for i in range(n):
        c, d = input().split()
        if x == 0 and d != 'South' or x == 20000 and d != 'North':
            return False
        if d in ('East', 'West'):
            continue
        x += (1 if d == 'South' else -1) * int(c)
        if x < 0 or x > 20000:
            return False
    return x == 0
print('YES' if f(int(input())) else 'NO')