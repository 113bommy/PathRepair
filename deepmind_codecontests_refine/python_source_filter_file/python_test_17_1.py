import sys
#sys.setrecursionlimit(10**6)
INF = float('inf')
#mod = 10**9 + 7
mod = 998244353
input = lambda: sys.stdin.readline().rstrip()
def li(): return list(map(int, input().split()))
class BIT:
    # 1-indexed
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)
  
    def sum(self, i):
        # i番目の要素までの総和を返す
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s

    def range_sum(self, l, r):
        if l == 1:
            return self.sum(r)
        else:
            return self.sum(r) - self.sum(l-1)
  
    def add(self, i, x):
        # i番目の要素にxを足す
        while i <= self.size:
            self.tree[i] += x
            i += i & -i

from collections import deque
T = int(input())
for _ in range(T):
    N = int(input())
    A = li()
    sortedA = set(sorted(A))
    dic = {a: e+2 for e, a in enumerate(sortedA)}
    bit = BIT(N+5)
    dq = deque()
    dq.append(dic[A[0]])
    bit.add(dic[A[0]], 1)

    for i in range(1, N):
        a = dic[A[i]]
        upper = bit.range_sum(a+1, N+3)
        lower = bit.sum(a-1)
        #print(dq, a, upper, lower)
        if upper > lower:
            dq.appendleft(a)
        else:
            dq.append(a)
        bit.add(a, 1)
    
    bit2 = BIT(N+5)
    ans = 0
    for i in range(N):
        x = dq.popleft()
        ans += i - bit2.sum(x+1)
        bit2.add(x+1, 1)

    print('YES',ans)






