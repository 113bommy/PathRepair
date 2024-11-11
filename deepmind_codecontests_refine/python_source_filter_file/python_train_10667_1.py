import bisect,sys
from collections import deque, namedtuple
sys.setrecursionlimit(20000)
N = 1050
par = [i for i in range(1050)]
siz = [1]*N

def find(i):
    if i == par[i]: return i
    par[i] = find(par[i])
    return par[i]

def merge(a,b):
    a = find(a)
    b = find(b)
    if siz[a] < siz[b]: a,b = b,a
    par[b] = a
    siz[a] += siz[b]

def main():
    n = int(input())
    l = [int(i) for i in input().split()]
    a = [ [ord(c)-ord('0') for c in input()] for j in range(n) ]
    for i in range(n):
        for j in range(n):
            if a[i][j]:
                merge(i,j)
    d = [[] for i in range(n)]
    cnt = [0]*n
    for i in range(n):
        a = find(i)
        d[a].append(l[i])

    for i in range(n):
        d[a] = sorted(d[a])

    for i in range(n):
        a = find(i)
        print(d[a][cnt[a]],end=" ")
        cnt[a] += 1

if __name__ == "__main__":
    main()