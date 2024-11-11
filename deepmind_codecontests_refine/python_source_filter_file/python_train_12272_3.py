# -*- coding: utf-8 -*-
"""
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0135
WA
"""
import sys
from sys import stdin
from math import sqrt, acos, cos, sin, radians, degrees
input = stdin.readline


def solve(time):
    # 12????????????90???
    short_hand_angle = time[1] * -6 + 90
    x_s = cos(radians(short_hand_angle))
    y_s = sin(radians(short_hand_angle))

    long_hand_angle = (time[0]*60+time[1])/(12*60) * -360 + 90
    x_l = cos(radians(long_hand_angle))
    y_l = sin(radians(long_hand_angle))
    c = (x_s * x_l + y_s * y_l) / (sqrt(x_s**2 + y_s**2) * sqrt(x_l**2 + y_l**2))
    ans = degrees(acos(c))

    if ans < 30:
        return 'alert'
    elif ans >= 90:
        return 'safe'
    else:
        return 'warning'


def main(args):
    # n = int(input())
    n = 1
    for _ in range(n):
        time = [int(x) for x in input().split(':')]
        result = solve(time)
        print(result)


if __name__ == '__main__':
    main(sys.argv[1:])