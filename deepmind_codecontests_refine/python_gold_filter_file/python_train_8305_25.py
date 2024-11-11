def examA():
    N = I()
    ans = 0
    print(ans)
    return

def examB():
    ans = 0
    print(ans)
    return

def examC():
    ans = 0
    print(ans)
    return

def examD():
    ans = 0
    print(ans)
    return

def examE():
    class Bit():
        def __init__(self, n):
            self.size = n
            self.tree = [0] * (n + 1)
            return

        def sum(self, i):
            s = 0
            while i > 0:
                s += self.tree[i]
                i -= i & -i
            return s

        def add(self, i, x=1):
            # i==0 はだめ => 全部+1するとか
            while i <= self.size:
                self.tree[i] += x
                i += i & -i
            return

        def search(self, x):
            # 二分探索。和がx以上となる最小のインデックス(>= 1)を返す
            # maspyさんの参考
            i = 0
            s = 0
            step = 1 << ((self.size).bit_length() - 1)
            while step:
                if i + step <= self.size and s + self.tree[i + step] < x:
                    i += step
                    s += self.tree[i]
                step >>= 1
            return i + 1

        def debug(self, k):
            return [self.sum(i) for i in range(k)]

    N = I()
    P = LI()
    Order = [[i+1] for i in range(N)]
    for i,p in enumerate(P):
        Order[i].append(p)
    Order.sort(key=lambda x:x[1],reverse=True)
    #print(Order)
    ans = 0
    bit = Bit(N+2)

    for i,p in Order:
        L = bit.sum(i)
        R = bit.sum(N)-L
        bit.add(i)
        l0, l1, r0, r1 = 0, 0, N+1, N+1
        if L>=2:
            l0 = bit.search(L-1)
        if L>=1:
            l1 = bit.search(L)
        if R>=1:
            r0 = bit.search(L+2)
        if R>=2:
            r1 = bit.search(L+3)
        #print(L,R)
        #print(l0,l1,r0,r1)
        #print(bit.debug(N+2))
        cnt = 0
        if l1>0:
            cnt += (l1-l0)*(r0-i)
        if r0>0:
            cnt += (i-l1)*(r1-r0)
        ans += cnt * p
        #print(ans)
    print(ans)
    return

def examF():
    def bfs(n, e, S):
        W = [0]*(2**n)
        cur = 1
        que = deque()
        que.append(e)
        while cur<2**n:
            now = que.popleft()
            depth = W[now]
            if S[now]<=S[cur]:
                return "No"
            for ne in range(n-depth):
                cur +=1
                W[now+1+ne] = depth+1
                que.append(now+1+ne)
        return "Yes"
    N = I()
    S = LI(); S.sort(reverse=True)
    ans = bfs(N,0,S)
    print(ans)
    return


import sys,copy,bisect,itertools,heapq,math
from heapq import heappop,heappush,heapify
from collections import Counter,defaultdict,deque
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))
def LSI(): return list(map(str,sys.stdin.readline().split()))
def LS(): return sys.stdin.readline().split()
def SI(): return sys.stdin.readline().strip()
global mod,mod2,inf,alphabet
mod = 10**9 + 7
mod2 = 998244353
inf = 10**18
alphabet = [chr(ord('a') + i) for i in range(26)]

if __name__ == '__main__':
    examE()

"""

"""