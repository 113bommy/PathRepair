def f(x, y):
    if x == y:
        return 0
    if x > y:
        if (x - y) % 2 == 0:
            return 1
        else:
            return 2
    else:
        if (y - x) % 2 == 1:
            return  1
        else:
            return 2


t = int(input())
for i in (0, t):
    n , k = map(int, input().split())
    print(f(n , k))
