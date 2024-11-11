from bisect import bisect_right
import sys
sys.setrecursionlimit(10 ** 7)

N = int(input())
A = list(map(int, input().split()))

edges = [[] for _ in range(N)]
for _ in range(N - 1):
    fr, to = map(lambda a: int(a) - 1, input().split())
    edges[fr].append(to)
    edges[to].append(fr)

ans = [0] * N
L = [-10**18]

def search(now, pr):
    a = A[now]
    i = bisect_right(L, a)
    isAppended = False
    prevValue = -1

    if i == len(L):
        L.append(a)
        isAppended = True
    else:
        prevValue = L[i]
        if L[i] > a:
            L[i] = a

    ans[now] = len(L) - 1

    for to in edges[now]:
        if to == pr:
            continue
        search(to, now)

    if isAppended:
        L.pop()
    else:
        L[i] = prevValue

search(0, -1)
print(*ans, sep='\n')
