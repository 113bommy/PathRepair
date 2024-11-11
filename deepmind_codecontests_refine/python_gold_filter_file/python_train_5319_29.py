# -*- coding: utf-8 -*-
# @Time    : 2021/1/12 10:14 上午
# @Author  : qu
# @Email   : quzhenqing@zju.edu.cn
# @File    : A. Fly.py
from sys import stdin

EPS = 1e-6
n = int(stdin.readline())
m = int(stdin.readline())
a = list(map(int, stdin.readline().split()))
b = list(map(int, stdin.readline().split()))
b.append(b[0])


def check(f):
    fuel_left = f
    total_weight = float(m + fuel_left)
    for i in range(n):
        cost = total_weight / a[i]
        fuel_left = fuel_left - cost
        total_weight = total_weight - cost

        cost = total_weight / b[i + 1]
        fuel_left = fuel_left - cost
        total_weight = total_weight - cost
        if fuel_left < 0:
            return False
    return True


def binary_search(left, right):
    mid = (left + right) / 2
    if abs(left - right) < EPS:
        return mid
    if check(mid):
        return binary_search(left, mid)
    else:
        return binary_search(mid, right)


res = binary_search(0, 1e9 + 1)
if res - 1e9 > EPS:
    print(-1)
else:
    print("%.10f" % res)
