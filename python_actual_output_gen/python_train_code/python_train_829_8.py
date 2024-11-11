#!/usr/bin/env python3


def solve():
    n, m, k = map(int, input().split())
    houses = map(int, input().split())
    m -= 1

    cur_dist = n+1
    cur_price = 0

    for i, h in enumerate(houses):
        dist = abs(m-i)
        if h != 0:
            if h < k:
                if dist < cur_dist:
                    cur_dist = dist
                    cur_price = h
                elif dist == cur_dist:
                    cur_price = min(h, cur_price)

    print(cur_dist * 10)


if __name__ == '__main__':
    solve()
