def arr_2d(n):
    return [[int(x) for x in input().split()] for i in range(n)]


def euclidean(x1, x2, y1, y2):
    return sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)


def get_col(arr, i):
    return [row[i] for row in arr]


from math import *
from operator import *

n = int(input())
a = arr_2d(n)

if n == 1:
    print(-1)
elif n == 2 and (a[0][0] == a[1][0] or a[0][1] == a[1][1]):
    print(-1)
else:
    a = [list(set(get_col(a, 0))), list(set(get_col(a, 1)))]
    # print(a)
    print(abs(a[0][0] - a[0][1]) * abs(a[1][1] - a[1][0]))
