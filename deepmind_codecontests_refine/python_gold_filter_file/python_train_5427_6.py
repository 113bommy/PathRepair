# -*- coding: utf-8 -*-
# @Time    : 2019/1/6 1:37
# @Author  : LunaFire
# @Email   : gilgemesh2012@gmail.com
# @File    : D. Sum in the tree.py

from collections import deque


def main():
    n = int(input())
    p = list(map(int, input().split()))
    s = list(map(int, input().split()))

    s.insert(0, 0)
    a = [0] * len(s)
    a[1] = s[1]

    child_dict, parent_dict = {}, {}
    for i in range(len(p)):
        if p[i] not in child_dict:
            child_dict[p[i]] = []
        child_dict[p[i]].append(i + 2)
        parent_dict[i + 2] = p[i]

    q = deque()
    q.append(1)
    while q:
        node = q.popleft()
        if s[node] == -1:
            if node not in child_dict or not child_dict[node]:
                s[node] = s[parent_dict[node]]
            else:
                s[node] = s[child_dict[node][0]]
                for x in child_dict[node]:
                    s[node] = min(s[node], s[x])
        if node in child_dict:
            for x in child_dict[node]:
                q.append(x)

    for i in range(2, n + 1):
        a[i] = s[i] - s[parent_dict[i]]
        if a[i] < 0:
            print(-1)
            return
    print(sum(a))


if __name__ == '__main__':
    main()
