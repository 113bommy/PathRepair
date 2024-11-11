a, b = map(int, input().split())
c = 0
if a != b:
    while a < b:
        a += a * 3
        b += b * 2
        c += 1
    print(c)
elif a == b:
    print(1)
