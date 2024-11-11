def arr_2d(n):
    return [[float(x) for x in stdin.readline().split()] for i in range(n)]


from sys import stdin
from operator import itemgetter

n = int(input())
a = sorted(list(set(map(tuple, arr_2d(n)))), key=itemgetter(0, 1))

ans = int(min(a[0][1], a[0][0]))

if len(a) == 1:
    print(ans)
else:
    for i in range(1, len(a)):
        if a[i][1] >= ans and a[i][1] <= a[i][0]:
            ans = a[i][1]
        else:
            ans = a[i][0]
    print(int(ans))
