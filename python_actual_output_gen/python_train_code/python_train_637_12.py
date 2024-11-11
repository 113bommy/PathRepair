import sys

input = sys.stdin.readline


tc = int(input())

for _ in range(tc):
    n, k = list(map(int, input().split()))
    nc = 'odd' if n%2 == 1 else 'even'
    kc = 'odd' if k%2 == 1 else 'even'
    if nc == 'even' and kc == 'odd':
        if n//2 > k-1:
            print('YES')
            print(('2 ' * (k-1)) + str(n-2*k))
        else:
            print('NO')
    elif nc == 'odd' and kc == 'even':
        print('NO')
    elif nc == kc:
        if n > k-1:
            print('YES')
            print(('1 '* (k-1)) + str(n-(k-1)))
        else:
            print('NO')
