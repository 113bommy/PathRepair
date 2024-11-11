h1, h2 = map(int, input().split())
a, b = map(int, input().split())
d = 0
r = h1
while(True):
    h1 += 8 * a
    if h1 >= h2:
        print(d)
        exit(0)
    d += 1
    h1 = max(0, h1 - 12 * b) + 4 * a
    if d > 1 and h1 <= r:
        print("-1")
        exit(0)