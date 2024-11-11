import sys
import math
import string
import fractions
import random
from operator import itemgetter
import itertools
import collections
from collections import deque
import copy
import heapq
from bisect import bisect, bisect_left, bisect_right

MOD = 10 ** 9 + 7
INF = float('inf')
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)


def func(a, b):
    return a + b


class SegmentTree:
    """
    各ノードが半開区間に対応した完全二分木。
    子は親を半分にした区間を持つ。
    構築O(n), 区間に対する操作O(logn), 値の更新O(logn)
    区間に対する操作は最小値, 最大値, 区間に対する和など柔軟に変更して用いよう！
    """

    def __init__(self, x, init_val):  # 構築, init_valは配列の初期値(最小値のクエリならINF, 和なら0)
        self.init_val = init_val
        self.length = 2 ** ((len(x) - 1).bit_length())
        self.data = [init_val] * (2 + 1) * self.length
        for i in range(len(x)):
            self.data[i + self.length - 1] = x[i]
        for i in range(self.length - 2, -1, -1):
            self.data[i] = func(self.data[2 * i + 1], self.data[2 * i + 2])

    def teach_current_val(self, index):
        return self.data[index + self.length - 1]

    def replace(self, index, val):  # indexの値をvalに更新
        index += self.length - 1
        self.data[index] = val
        while index:
            index = (index - 1) // 2
            self.data[index] = func(self.data[2 * index + 1], self.data[2 * index + 2])

    def query(self, left, right):  # 半開区間の最小値等を求める, 葉からさかのぼっていくイメージ。
        if right <= left:
            return self.init_val
        left += self.length - 1  # self.dataの位置に合わせる。
        right += self.length - 2  # self.dataの位置に合わせる。半開区間
        ans = self.init_val
        while right > left + 1:
            if left & 1 == 0:  # if left_index%2 == 0:
                ans = func(ans, self.data[left])
            if right & 1 == 1:  # if right_index%2 == 1:
                ans = func(ans, self.data[right])
                right -= 1
            left //= 2
            right = (right - 1) // 2
        if left == right:
            ans = func(ans, self.data[left])
        else:
            ans = func(func(ans, self.data[left]), self.data[right])
        return ans


N, K = map(int, input().split())
a = [0] * (N + 1)
for i in range(N):
    a[i + 1] = int(input()) - K
a = list(itertools.accumulate(a))
cc = sorted(list(dict.fromkeys(a)))
c = collections.Counter(a)
for i in range(len(a)):
    if type(c[a[i]]) == int:
        c[a[i]] = [i]
    else:
        c[a[i]].append(i)
seg = SegmentTree([0] * (N + 1), 0)
ans = 0
for i in cc:
    for l in c[i]:
        ans += seg.query(0, l)
        seg.replace(l, 1)
print(ans)