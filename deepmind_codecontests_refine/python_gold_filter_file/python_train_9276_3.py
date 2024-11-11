def prog():
    from sys import stdin
    n = int(stdin.readline())
    s = set(map(int,stdin.readline().split()[1:]))
    for i in range(n-1):
        d = set(map(int,stdin.readline().split()[1:]))
        s = s&d
    print(*s)
prog()