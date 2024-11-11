from itertools import combinations,permutations
from collections import defaultdict
import math
import sys
import os


def zeror():
    return 0


prefix_sums = []
ftree = []


class FenwickTree(object):

    def __init__(self, n):
        self.tree = [0] * (n + 1)

    def update(self, i, v):
        i += 1
        while i < len(self.tree):
            self.tree[i] += v
            i = i + (((~i) + 1) & i)

    def query(self, l, r):
        lt = 0
        i = l
        while i != 0:
            lt += self.tree[i]
            i = i - (((~i) + 1) & i)
        rt = 0
        i = r + 1
        while i != 0:
            rt += self.tree[i]
            i -= (((~i) + 1) & i)
        return rt - lt



def solution(n,a):

    onetoi = []
    seen1i = defaultdict(int)

    for i in range(n):
        seen1i[a[i]] += 1
        onetoi.append(seen1i[a[i]])

    print(onetoi)
    print(seen1i)

    jton = []
    seenjn = defaultdict(int)
    for j in range(n - 1, -1, -1):
        seenjn[a[j]] += 1
        jton.append(seenjn[a[j]])

    print(jton)
    print(seenjn)

    jton = jton[::-1]

    fw = FenwickTree(1000000)


    for v in jton:
        fw.update(v, 1)
    t = 0
    for i in range(n):
        fw.update(jton[i], -1)
        t += fw.query(0, onetoi[i] - 1)
        print(t)

    return t



def main():


    """a=[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
    ft = FenwickTree(len(a)*3)
    for i,v in enumerate(a):
        ft.update(i,v)
    print(ft.tree)
    print(ft.query(0,10))
    exit()"""

    n=int(input())
    arr=list(map(int,input().strip().split()))
    print(solution(n,arr))


if __name__ == '__main__':
    main()


"""

7
1 2 1 1 2 2 1


"""