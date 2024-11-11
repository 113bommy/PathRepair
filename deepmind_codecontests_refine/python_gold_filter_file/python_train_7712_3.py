import itertools

def f(n, arr):
    d = dict((j,i) for (i,j) in enumerate(itertools.accumulate(reversed(arr))))
    res = 0
    for i,j in enumerate(itertools.accumulate(arr)):
        if j in d and i + d[j] < n - 1:
            res = max(res, j)
    return res
    
n = int(input())
arr = [int(i) for i in input().split()]
print(f(n, arr))