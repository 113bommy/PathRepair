import sys
input = sys.stdin.readline
read_tuple = lambda _type: map(_type, input().split(' '))
from collections import Counter


def can_cook(n, recipe, n_b, n_s, n_c, p_b, p_s, p_c, r):
    b, s, c = n * recipe.get('B', 0), n * recipe.get('S', 0), n * recipe.get('C', 0)
    diff_b, diff_s, diff_c = n_b - b, n_s - s, n_c - c
    if diff_b < 0:
        r -= -diff_b * p_b
    if diff_s < 0:
        r -= -diff_s * p_s
    if diff_c < 0:
        r -= -diff_c * p_c
    return r >= 0


def solve():
    recipe = dict(Counter(input().replace('\n', '')))
    n_b, n_s, n_c = read_tuple(int)
    p_b, p_s, p_c = read_tuple(int)
    r = int(input())
    lb, ub = 0, 10 ** 12
    while ub - lb > 1:
        mid = (lb + ub) // 2
        if can_cook(mid, recipe, n_b, n_s, n_c, p_b, p_s, p_c, r):
            lb = mid
        else:
            ub = mid
    if can_cook(ub, recipe, n_b, n_s, n_c, p_b, p_s, p_c, r):
        print(ub)
    else:
        print(lb)


if __name__ == '__main__':
    solve()