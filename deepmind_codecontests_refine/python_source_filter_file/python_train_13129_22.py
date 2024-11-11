import sys, math
t = int(sys.stdin.readline())
INF = 1e10
for i in range(t):
    [n, x, y, d] = map(int, sys.stdin.readline().split())
    if (y - x) % d == 0:
        print ((y - x) // d)
    else:
        [_1_to_y, n_to_y] = [(y - 1) // d if (y - 1) % d == 0 else INF, (n - y) // d if (n - y) % d == 0 else INF]
        #print ([_1_to_y, n_to_y])
        if [_1_to_y, n_to_y] == [INF, INF]:
            print (-1)
        else:
            print (min(_1_to_y + math.ceil((x - 1) / d), n_to_y + math.ceil((n - x) / d)))