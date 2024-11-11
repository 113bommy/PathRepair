def solve():
    x = int(input())
    c = 0
    p = 1
    while (p * (p + 1)) / 2 <= x:
        x -= (p * (p + 1)) / 2
        c += 1
        p = p + p + 1
    print(c)


t = int(input())
i = 0
while i < t:
    solve()
    i += 1
