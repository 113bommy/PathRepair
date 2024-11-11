def solve():
    l, r = list(map(int, input().split()))
    if 2*l <= r:
        print('{} {}'.format(l, 2*l))
    else:
        print('-1 -1')

t = int(input())
for test in range(t):
    solve()

