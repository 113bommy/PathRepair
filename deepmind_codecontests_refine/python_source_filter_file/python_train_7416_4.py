for _ in range(int(input())):
    n = int(input())
    s = 0
    while n > 2:
        px = 2
        py = 5
        while px < n:
            px += py
            py += 3
        py -= 3
        px -= py
        n -= px
        s += 1
    if n == 2:
        s += 1
    print(s)