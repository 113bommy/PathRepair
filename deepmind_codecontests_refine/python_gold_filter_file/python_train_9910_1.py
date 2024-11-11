"""
    > File Name: c.py
    > Author: Code_Bear
    > Mail: secret 
    > Created Time: Thu Oct 17 16:34:03 2019
"""
from collections import OrderedDict
def SortPoint(p, ids, k, D):
    if k == D:
        return ids[0]
    maps = OrderedDict()
    for i in ids:
        if p[i][k] not in maps:
            maps[p[i][k]] = []
        maps[p[i][k]].append(i)
    a = []
    for i in sorted(maps.keys()):
        cnt = SortPoint(p, maps[i], k + 1, D)
        if cnt != -1: a.append(cnt)
    for i in range(0, len(a), 2):
        if i + 1 < len(a):
            print(a[i] + 1, a[i + 1] + 1)
    return -1 if len(a) % 2 == 0 else a[-1]
            

def solver():
    n = int(input())
    p = []
    ids = [i for i in range(n)]
    for i in range(n):
        point = list(map(int, input().split()))
        p.append(point)
    SortPoint(p, ids, 0, 3)
    
def main():
    while 1:
        try:
            solver()
        except EOFError:
            break

if __name__ == '__main__':
    main()