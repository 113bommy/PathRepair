from collections import Counter

n = int(input())
arr = list(map(int, input().split()))
sted = sorted(arr)
dd = [0] * (n-1)
for i in range(n-1):
    dd[i] = arr[i+1]-arr[i]
c = Counter(dd)

def indexit(num):
    for i in range(n):
        if arr[i] == num:
            return i + 1

def could(i):
    b = dd[i-1]
    a = dd[i]
    su = a + b
    c[a] -= 1
    c[b] -= 1
    c[su] += 1
    if c[a] == 0:
        del c[a]
    if c[b] == 0:
        del c[b]
    ans = len(c) == 1
    c[a] += 1
    c[b] += 1
    c[su] -= 1
    if c[su] == 0:
        del c[su]
    return ans

def solution():
    if len(c) == 1:
        return indexit(sted[-1])
    else:
        for i in range(1, n-1):
            if could(i):
                return indexit(sted[i])
        f = dd[0]
        c[f] -= 1
        if c[f] == 0:
            del c[f]
        if len(c) == 1:
            return indexit(sted[0])
        c[f] += 1
        l = dd[-1]
        c[l] -= 1
        if c[l] == 0:
            del c[l]
        if len(c) == 1:
            return indexit(sted[-1])
        return -1

print(solution())

