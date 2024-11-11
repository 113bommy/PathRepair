import sys

input = sys.stdin.readline
# fin = open('input.txt', 'r')
# input = fin.readline


def solve():
    u, v = map(int, input().split())

    if u == 0:
        if v == 0:
            print(0)
            return
        if v % 2 == 1:
            print(-1)
            return
        print(2)
        print(v // 2, v // 2)
        return

    if u > v:
        print(-1)
        return

    if u == v:
        print(1)
        print(u)
        return

    if u < v:
        if v - u % 2 == 1:
            print(-1)
            return
        vu = (v - u) // 2
        if u + vu == u ^ vu:
            print(2)
            print(u + vu, vu)
            return
        print(3)
        print(u, vu, vu)
        return


solve()
