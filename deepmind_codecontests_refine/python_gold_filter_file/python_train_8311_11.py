import sys
sys.setrecursionlimit(10 ** 7)

N = int(input())
A = [0, 0] + [int(input()) for _ in range(N - 1)]

child = [[] for _ in range(N + 1)]
for i, a in enumerate(A):
    child[a].append(i)

def depth(i):
    if not child[i]:
        return 0

    childDepth = [depth(to) for to in child[i]]
    childDepth.sort(reverse=True)
    ret = 0
    for j, d in enumerate(childDepth, start=1):
        ret = max(j + d, ret)
    return ret

ans = depth(1)
print(ans)