from sys import stdin
input = stdin.readline

t = int(input())
for _ in range(t):
    n, x = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    c = a.count(x)
    if c == n:
        print(0)
    elif c >= 1:
        print(0)
    else:
        d = 0
        for i in a:
            d += x - i
        if d == 0:
            print(1)
        else:
            print(2)