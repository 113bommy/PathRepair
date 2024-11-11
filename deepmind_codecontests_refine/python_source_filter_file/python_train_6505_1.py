# -*- coding: utf-8 -*-
# @Time    : 2021/1/15 5:25 下午
# @Author  : qu
# @Email   : quzhenqing@zju.edu.cn
# @File    : C. GukiZ hates Boxes.py

from sys import stdin

#
n, m = map(int, stdin.buffer.readline().split())
a = list(map(int, stdin.buffer.readline().split()))
max_not_zero = 0
for index, value in enumerate(a):
    if value > 0:
        max_not_zero = index
total = sum(a)


def remove(t):
    boxes = 0
    s = m
    for i in range(max_not_zero):
        boxes += a[i]
        # 够一个人用的了
        while boxes + (i + 1) >= t:
            boxes -= (t - i - 1)
            s -= 1
            if s < 0:
                return False
    if s == 0:
        if boxes > 0:
            return False
    return True


def binary_search(left, right):
    mid = int((left + right) // 2)
    if right - left <= 1 and remove(left):
        return left
    if remove(mid):
        return binary_search(left, mid)
    else:
        return binary_search(mid + 1, right)


print(binary_search(2, total + n))
