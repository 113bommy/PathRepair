"""
Author: Q.E.D
Time: 2020-06-07 10:37:46
"""
T = int(input())
for _ in range(T):
    n, m = list(map(int, input().split()))
    a = [list(map(int, input().split())) for _ in range(n)]
    r, c = set(), set()
    for i in range(n):
        for j in range(m):
            if a[i][j] == 1:
                r.add(i)
                c.add(i)
    k = min(n - len(r), m - len(c))
    print('Ashish' if k % 2 == 1 else 'Vivek')
                