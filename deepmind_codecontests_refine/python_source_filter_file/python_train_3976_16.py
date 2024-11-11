cases = int(input())
from math import ceil

for _ in range(cases):
    x = [int(i) for i in input().split()]

    diff = x[0] - x[1]

    # allocate such that diff >= 1
    # s + i = points
    # (s - i) + diff >= 1
    # (s - i) >= 1 - diff

    # s >= 1 - diff + i
    # s >= 1 - diff + (points - s)
    # 2 * s >= 1 - diff + points
    # s >= (1 - diff + points)//2
    s = ceil((1 - diff + x[-1])/2)
    # print('-----------')
    # print(s)
    print(max(x[-1] - s + 1, 0))