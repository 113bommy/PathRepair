for i in range(int(input())):
    input()
    x = 10**7
    d = 0
    for a in reversed(list(map(int, input().split()))):
        d = d+a > x
        x = min(x, a)
    print(d)
