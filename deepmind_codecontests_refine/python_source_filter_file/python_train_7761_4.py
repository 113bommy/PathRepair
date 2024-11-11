import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**2
mod = 10**9 + 7

def f():
    n,m,k = list(map(int, input().split()))
    a = [[inf]*(m+2)]
    g = []
    for _ in range(n):
        a.append([inf] + [_ for _ in input()] + [inf])
        g.append([False]*m)
    a.append([[inf]*(m+2)])

    c = 0
    for i in range(1,n+1):
        if a[i][1] == '.':
            a[i][1] = -1
        if a[i][-2] == '.':
            a[i][-2] = -1
    for j in range(1,m+1):
        if a[1][j] == '.':
            a[1][j] = -1
        if a[-2][j] == '.':
            a[-2][j] = -1

    def ff(n1,n2):
        for i in range(1,n+1):
            for j in range(1,m+1):
                if a[i][j] == n1:
                    a[i][j] = n2
    ff('*', inf)

    for i in range(1,n+1):
        for j in range(1,m+1):
            if a[i][j] == '.':
                mc = [inf]
                if a[i-1][j] != '.': mc.append(a[i-1][j])
                if a[i+1][j] != '.': mc.append(a[i+1][j])
                if a[i][j+1] != '.': mc.append(a[i][j+1])
                if a[i][j-1] != '.': mc.append(a[i][j-1])
                mm = min(mc)
                if mm < inf:
                    a[i][j] = mm
                    for t in [_ for _ in mc if _ < inf and _ != mm]:
                        ff(t,mm)
                else:
                    a[i][j] = c
                    c += 1
    cnt = [0] * c
    for i in range(1,n+1):
        for j in range(1,m+1):
            if -1 < a[i][j] < c:
                cnt[a[i][j]] += 1
    cnt2 = [_ for _ in cnt if _ > 0]
    r = 0
    for _i in range(len(cnt2) - k):
        cnt2 = [_ for _ in cnt if _ > 0]
        mm = min(cnt2)
        ind = cnt.index(mm)
        cnt[ind] = 0
        r += mm
        for i in range(1,n+1):
            for j in range(1,m+1):
                if a[i][j] == ind:
                    a[i][j] = '*'

    print(r)

    for i in range(1,n+1):
        s = ''
        for j in range(1,m+1):
            c = a[i][j]
            if c == '*':
                s += c
            elif c == inf:
                s += '*'
            else:
                s += '.'
        print(s)

f()
