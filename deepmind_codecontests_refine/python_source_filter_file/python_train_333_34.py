n, k = map(int, input().split())
a = list(map(int, input().split()))

min_ = float("inf")
for x in range(200001):
    c1, c2, f = 0, 0, False
    for y in a:
        c3 = 0
        while x < y:
            y //= 2
            c3 += 1
        if x == y:
            c1 += c3
            c2 += 1
        if c2 >= k:
            f = True
            break
    if f and c1 < min_:
        min_ = c1

print(min_)
