n, x = map(int, input().split())

r = 0
for d1 in range(1, int(x ** 0.5) + 1):
    if not x % d1:
        d2 = x / d1
        if x / d2 > n:
            continue
        
        if d2 == d1:
            r += 1
        else:
            r += 2

print(r)
