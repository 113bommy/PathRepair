import sys
from collections import Counter

sys.stdin = open('b1.in')


def read_int_list():
    return list(map(int, input().split()))


def read_int():
    return int(input())


def read_str_list():
    return input().split()


def read_str():
    return input()


yes, no = 'Yes', 'No'


def solve(n, a):
    s = set(a)
    c = Counter(a)
    if len(s) == 1:
        a = list(s)[0]
        n_colors = a + 1
        if n_colors == n:
            return yes
        n_colors = a
        if 2 * n_colors <= n:
            return yes
    if len(s) == 2:
        a, b = sorted(s)
        if a + 1 == b:
            n_colors = b
            appear_once = c[a]
            appear_twice_or_more = n_colors - appear_once
            if appear_once < n_colors:
                if c[b] >= 2 * appear_twice_or_more:
                    return yes
    return no

n = read_int()
a = read_int_list()
res = solve(n, a)
print(res)

