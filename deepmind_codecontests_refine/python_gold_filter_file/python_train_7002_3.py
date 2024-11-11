#!/usr/bin/env python3
import io
import os
import heapq
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
def get_str():
    return input().decode().strip()
def rint():
    return map(int, input().split())
def oint():
    return int(input())

def dfs(cur):
    stack = [cur]
    while stack:
        cur = stack[-1]
        if v[cur] == 0:
            v[cur] = 1
            for ni, nw, _ in adj[cur]:
                if v[ni]:
                    continue
                stack.append(ni)
        else:
            if cur != 1 and len(adj[cur]) == 1:
                ret = 1
            else:
                ret = 0
            for ni, nw, cc in adj[cur]:
                if v[ni] == 1:
                    w[cur] = nw
                    c[cur] = cc
                    continue
                ret += lc[ni]
            lc[cur] = ret
            if c[cur] == 1:
                if w[cur]:
                    sl1.append(((lc[cur] * (w[cur] // 2) - lc[cur] * w[cur]), cur))
            else:
                if w[cur]:
                    sl2.append(((lc[cur] * (w[cur] // 2) - lc[cur] * w[cur]), cur))
            v[cur] = 2
            stack.pop()



t = oint()

for _ in range(t):
    n, s = rint()
    adj = [[] for i in range(n + 1)]
    v = [0] * (n + 1)
    lc = [0] * (n + 1)
    w = [0] * (n + 1)
    c = [1] * (n + 1)
    sl1 = []
    sl2 = []
    for i in range(n - 1):
        vv, uu, ww, cc = rint()
        adj[vv].append((uu, ww, cc))
        adj[uu].append((vv, ww, cc))
    dfs(1)
    sum_ = 0
    for item in sl1:
        i = item[1]
        mul = lc[i]
        sum_ += mul * w[i]
    for item in sl2:
        i = item[1]
        mul = lc[i]
        sum_ += mul * w[i]

    heapq.heapify(sl1)
    heapq.heapify(sl2)
    cost = 0
    while sum_ > s:
        if not sl1:
            item = heapq.heappop(sl2)
            i = item[1]
            mul = lc[i]
            cost += 2
            sum_ = sum_ + item[0]
            w[i] //= 2
            if w[i] != 0:
                heapq.heappush(sl2, ((mul * (w[i] // 2) - mul * w[i]), i))
            continue
        if not sl2:
            item = heapq.heappop(sl1)
            i = item[1]
            mul = lc[i]
            cost += 1
            sum_ = sum_ + item[0]
            w[i] //= 2
            if w[i] != 0 or len(sl1) == 0:
                heapq.heappush(sl1, ((mul * (w[i] // 2) - mul * w[i]), i))
            continue

        if sl1[0][0] + sum_ <= s:
            cost += 1
            break
        if sl2[0][0] + sum_ <= s:
            cost += 2
            break

        item1 = heapq.heappop(sl1)
        i = item1[1]
        mul = lc[i]
        diff2 = mul* ((w[i]//2)//2) - mul*(w[i]//2)
        if sl1:
            diff = min(diff2, sl1[0][0])
        else:
            diff = diff2

        item2 = sl2[0]

        if item2[0] < item1[0] + diff:
            cost += 2
            heapq.heappush(sl1, item1)
            i = item2[1]
            mul = lc[i]
            sum_ = sum_ + item2[0]
            w[i] //= 2
            heapq.heappop(sl2)
            if w[i] != 0:
                heapq.heappush(sl2, ((mul*(w[i]//2)- mul*w[i]), i))
        else:
            cost += 1
            sum_ = sum_ + item1[0]
            w[i] //= 2
            if w[i] != 0:
                heapq.heappush(sl1, (diff2, i))
    print(cost)