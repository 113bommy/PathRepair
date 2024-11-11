from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,copy,time
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_str(): return list(sys.stdin.readline().split())


N = inp()
AA = inpl()
BB = inpl()

# In[]:
# N = 3
# AA = [3, 4, 3]
# BB = [3, 2, 3]

cards = []
for i,(a,b) in enumerate(zip(AA,BB)):
    if i%2 == 0:
        cards.append((a, b, i))
    else:
        cards.append((b, a, i))


n = (N+1)//2

# In[]:
def solve(ii):
    tmp = 0
    # print(ii)
    for _ in range(3):
        next = []
        for k, i in enumerate(ii):
            if i == 0:
                tmp += k
            else:
                next.append(i-1)
        ii = next[:]
    # print(tmp)
    return tmp



# In[]:
ans = INF
for Acards in itertools.combinations(cards, n):
    Ais = sorted([(Acard[0], Acard[2]) for Acard in Acards])

    ii = set([i for A,i in Ais])
    Bis = []
    for a,b,i in cards:
        if i not in ii:
            Bis.append((b,i))
    Bis.sort()

    nums = []
    ii = []
    for i in range(N):
        if i%2 == 0:
            n,i = Ais[i//2]
        else:
            n,i = Bis[i//2]
        nums.append(n)
        ii.append(i)

    # print(nums,ii)
    if nums != sorted(nums):
        continue
    else:
        ans = min(ans,solve(ii))


if ans == INF:
    print(-1)
else:
    print(ans)
