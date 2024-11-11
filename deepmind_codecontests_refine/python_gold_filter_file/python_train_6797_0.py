import sys, math, itertools, collections, copy

input = sys.stdin.readline

def combine(arr: list, ans: set) -> set:
    ans.add(sum(arr))
    if (arr[0] == arr[-1]):
        return ans
    mid = arr[0] + arr[-1] >> 1
    lo, hi = 0, len(arr) - 1
    while lo + 1 < hi:
        m = lo + hi >> 1
        if arr[m] <= mid:
            lo = m
        else:
            hi = m
    new1, new2 = [], []
    for i in range(len(arr)):
        if i <= lo:
            new1.append(arr[i])
        else:
            new2.append(arr[i])
    s1, s2 = set(), set()
    s1 = combine(new1, s1)
    s2 = combine(new2, s2)
    ans = ans.union(s1, s2)
    return ans

for _ in range(int(input())):
    n, q = map(int, input().split())
    a = [int(x) for x in input().split()]
    a.sort()
    tmp = set()
    ans = combine(a, tmp)
    for i in range(q):
        x = int(input())
        if x in ans:
            print("Yes")
        else:
            print("No")
     
