import sys
from collections import defaultdict

input = sys.stdin.readline


def ri(): return [int(i) for i in input().split()]


def rs(): return input().split()[0]


def get_t(s: str, order):
    t = ''
    for c in order:
        t += s
        s = s.replace(c, '')
    return t


def get_order(s):
    done = [0] * 200
    order = ''
    for c in reversed(s):
        if done[ord(c)] == 0:
            order = c + order
            done[ord(c)] = 1
    return order


def main():
    t = ri()[0]

    for _ in range(t):
        T = rs()
        order = get_order(T)
        mi = 1
        mx = len(T)+1
        m = (mi + mx) // 2
        for i in range(30):
            t = get_t(T[:m], order)
            # print(f'mi:{mi} m:{m} mx:{mx}')
            # print(T)
            # print(t)
            if len(t) < len(T):
                mi = m
            elif len(t) > len(T):
                mx = m
            elif len(t) == len(T) and t == T:
                print(T[:m], order)
                break
            else:
                print(-1)
                break
            m = (mi + mx) // 2
            if mx - mi <= 1:
                print(-1)
                break


main()
