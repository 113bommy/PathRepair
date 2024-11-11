from collections import defaultdict as dd
from sys import stdin
input = stdin.readline
for _ in range(int(input())):
    n = int(input())
    a = [];m = 0
    dic = dd(int)
    for el in map(int, input().split()):
        dic[el] += 1
        a.append(el)
        m = max(m, el)
    l = -1;ans = 0
    while l < n - 1:
        s = a[l+1];l += 1;r = l+1
        while s < m and r < n:
            s += a[r]
            if dic[s]:ans += dic[s];dic[s]=0
            r += 1
    print(ans)