import math
from collections import defaultdict

def input_ints():
    return list(map(int, input().split()))

def solve():
    n = int(input())
    a = input_ints()
    a = list(set(a))
    a.sort()
    if len(a) <= 2 or (len(a) == 3 and a[1] - a[0] == a[2] - a[1]):
        print('YES')
    else:
        print('NO')

if __name__ == '__main__':
    solve()
