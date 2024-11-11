from collections import defaultdict
from sys import stdin
input = stdin.readline
def check(mid, m):
    d = defaultdict(int)
    for idx, i in enumerate(a):
        string = ''
        for j in i:
            if j >= mid:
                string+='1'
            else:
                string+='0'
        d[int(string, 2)] = idx
    for i in d.keys():
        for j in d.keys():
            if i|j == 2**m - 1:
                 return [d[i], d[j]]
    return []
def binarySearch(lo, hi, m):
    ans = []
    while lo < hi:
        mid = lo + (hi-lo+1)//2
        x = check(mid, m)
        if x:
            lo = mid
            ans = [x[0]+1, x[1]+1]
        else:
            hi = mid-1
    return ans
n, m = map(int, input().split())
a = []
for i in range(n):
    a.append(list(map(int, input().split())))
print(*binarySearch(0, 10**9, m))