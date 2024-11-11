
#Z[i]:length of the longest list starting from S[i] which is also a prefix of S
#O(|S|)
def Z_algorithm(s):
    N = len(s)
    Z_alg = [0]*N

    Z_alg[0] = N
    i = 1
    j = 0
    while i < N:
        while i+j < N and s[j] == s[i+j]:
            j += 1
        Z_alg[i] = j
        if j == 0:
            i += 1
            continue
        k = 1
        while i+k < N and k + Z_alg[k]<j:
            Z_alg[i+k] = Z_alg[k]
            k += 1
        i += k
        j -= k
    return Z_alg

class BIT():
    def __init__(self,n,mod=0):
        self.BIT = [0]*(n+1)
        self.num = n
        self.mod = mod

    def query(self,idx):
        res_sum = 0
        mod = self.mod
        while idx > 0:
            res_sum += self.BIT[idx]
            if mod:
                res_sum %= mod
            idx -= idx&(-idx)
        return res_sum

    #Ai += x O(logN)
    def update(self,idx,x):
        mod = self.mod
        while idx <= self.num:
            self.BIT[idx] += x
            if mod:
                self.BIT[idx] %= mod
            idx += idx&(-idx)
        return

class dancinglink():
    def __init__(self,n,debug=False):
        self.n = n
        self.debug = debug
        self._left = [i-1 for i in range(n)]
        self._right = [i+1 for i in range(n)]
        self.exist = [True for i in range(n)]

    def pop(self,k):
        if self.debug:
            assert self.exist[k]
        L = self._left[k]
        R = self._right[k]
        if L!=-1:
            if R!=self.n:
                self._right[L],self._left[R] = R,L
            else:
                self._right[L] = self.n
        elif R!=self.n:
            self._left[R] = -1
        self.exist[k] = False

    def left(self,idx,k=1):
        if self.debug:
            assert self.exist[idx]
        res = idx
        while k:
            res = self._left[res]
            if res==-1:
                break
            k -= 1
        return res

    def right(self,idx,k=1):
        if self.debug:
            assert self.exist[idx]
        res = idx
        while k:
            res = self._right[res]
            if res==self.n:
                break
            k -= 1
        return res

class SparseTable():
    def __init__(self,A,merge_func,ide_ele):
        N = len(A)
 
        self.merge_func = merge_func
 
        self.lg = [0]*(N + 1)
        for i in range(2, N+1):
            self.lg[i] = self.lg[i >> 1] + 1
        self.pow_2 = [pow(2,i) for i in range(20)]
 
        self.table = [None]*(self.lg[N] + 1)
        st0 = self.table[0] = [a for a in A]
        b = 1
        for i in range(self.lg[N]):
            st0 = self.table[i+1] = [self.merge_func(u,v) for u, v in zip(st0, st0[b:])]
            b <<= 1
 
    def query(self,s,t):
        b = t-s+1
        m = self.lg[b]
        return self.merge_func(self.table[m][s],self.table[m][t-self.pow_2[m]+1])
 

class BinaryTrie:
    class node:
        def __init__(self,val):
            self.left = None
            self.right = None
            self.max = val

    def __init__(self):
        self.root = self.node(-10**15)

    def append(self,key,val):
        pos = self.root
        for i in range(29,-1,-1):
            pos.max = max(pos.max,val)
            if key>>i & 1:
                if pos.right is None:
                    pos.right = self.node(val)
                    pos = pos.right
                else:
                    pos = pos.right
            else:
                if pos.left is None:
                    pos.left = self.node(val)
                    pos = pos.left
                else:
                    pos = pos.left
        pos.max = max(pos.max,val)

    def search(self,M,xor):
        res = -10**15
        pos = self.root
        for i in range(29,-1,-1):
            if pos is None:
                break

            if M>>i & 1:
                if xor>>i & 1:
                    if pos.right:
                        res = max(res,pos.right.max)
                    pos = pos.left
                else:
                    if pos.left:
                        res = max(res,pos.left.max)
                    pos = pos.right
            else:
                if xor>>i & 1:
                    pos = pos.right
                else:
                    pos = pos.left

        if pos:
            res = max(res,pos.max)
        return res

def solveequation(edge,ans,n,m):
    #edge=[[to,dire,id]...]
    def dfs(v):
        used[v]=True
        r=ans[v]
        for to,dire,id in edge[v]:
            if used[to]:
                continue
            y=dfs(to)
            if dire==-1:
                x[id]=y
            else:
                x[id]=-y
            r+=y
        return r
        
    x=[0]*m
    used=[False]*n
    for v in range(n):
        if used[v]:
            continue
        y = dfs(v)
        if y!=0:
            return False
    return x

    

class slope_trick():
    def __init__(self):
        self.L = [10**17]
        self.R = [10**17]
        self.min_f = 0

        self.x_left = 0
        self.x_right = 0

    def add_right(self,a):
        a -= self.x_left
        l0 = -self.L[0]
        self.min_f  = self.min_f + max(0,l0-a)
        if l0 <= a:
            a += self.x_left
            a -= self.x_right
            heappush(self.R,a)
        else:
            heappush(self.L,-a)
            a = -heappop(self.L)
            a += self.x_left
            a -= self.x_right
            heappush(self.R,a)

        #self.min_f  = self.min_f + max(0,l0-a)

    def add_left(self,a):
        a -= self.x_right
        r0 = self.R[0]
        self.min_f = self.min_f + max(0,a-r0)

        if a <= r0:
            a += self.x_right
            a -= self.x_left
            heappush(self.L,-a)
        else:
            heappush(self.R,a)
            a = heappop(self.R)
            a += self.x_right
            a -= self.x_left
            heappush(self.L,-a)

        #self.min_f = self.min_f + max(0,a-r0)

    def add_abs(self,a):
        self.add_left(a)
        self.add_right(a)

    def change_min_slide(self,a,b):
        self.x_left += a
        self.x_right += b
    
    def get_val(self,x):
        L = [-l+self.x_left for l in self.L]
        L.sort()
        R = [r+self.x_right for r in self.R]
        R.sort()

        res = self.min_f

        if 0 < L[-1]:
            L = L[::-1]
            n = len(L)
            for i in range(n):
                c0 = L[i]
                c1 = L[i+1]
        
                if c1 <= x <= c0:
                    res += (i+1) * (c0-x)
                    break
                else:
                    res += (i+1) * (c0-c1)
            return res
        elif L[-1] <= x <= R[0]:
            return res
        else:
            n = len(R)
            for i in range(n):
                c0 = R[i]
                c1 = R[i+1]
                if c0 <= x <= c1:
                    res += (i+1) * (x-c0)
                    break
                else:
                    res += (i+1) * (c1-c0)
            return res

class SegmentTree:
    def __init__(self, init_val, segfunc, ide_ele):
        n = len(init_val)
        self.segfunc = segfunc
        self.ide_ele = ide_ele
        self.num = 1 << (n - 1).bit_length()
        self.tree = [ide_ele] * 2 * self.num
        self.size = n
        for i in range(n):
            self.tree[self.num + i] = init_val[i]
        for i in range(self.num - 1, 0, -1):
            self.tree[i] = self.segfunc(self.tree[2 * i], self.tree[2 * i + 1])

    def update(self, k, x):
        k += self.num
        self.tree[k] = x
        while k > 1:
            k >>= 1
            self.tree[k] = self.segfunc(self.tree[2*k], self.tree[2*k+1])

    def query(self, l, r):
        if r==self.size:
            r = self.num

        res = self.ide_ele

        l += self.num
        r += self.num
        right = []
        while l < r:
            if l & 1:
                res = self.segfunc(res, self.tree[l])
                l += 1
            if r & 1:
                right.append(self.tree[r-1])
            l >>= 1
            r >>= 1

        for e in right[::-1]:
            res = self.segfunc(res,e)
        return res

    def bisect_l(self,l,r,x):
        l += self.num
        r += self.num
        Lmin = -1
        Rmin = -1
        while l<r:
            if l & 1:
                if self.tree[l] <= x and Lmin==-1:
                    Lmin = l
                l += 1
            if r & 1:
                if self.tree[r-1] <=x:
                    Rmin = r-1
            l >>= 1
            r >>= 1

        if Lmin != -1:
            pos = Lmin
            while pos<self.num:
                if self.tree[2 * pos] <=x:
                    pos = 2 * pos
                else:
                    pos = 2 * pos +1
            return pos-self.num
        elif Rmin != -1:
            pos = Rmin
            while pos<self.num:
                if self.tree[2 * pos] <=x:
                    pos = 2 * pos
                else:
                    pos = 2 * pos +1
            return pos-self.num
        else:
            return -1

import sys,random,bisect
from collections import deque,defaultdict
from heapq import heapify,heappop,heappush
from itertools import permutations
from math import gcd,log

input = lambda :sys.stdin.buffer.readline()
mi = lambda :map(int,input().split())
li = lambda :list(mi())

N = int(input())
slot = []
for i in range(N):
    c,*a = li()
    slot.append(a)

m = int(input())
ban = set()
for i in range(m):
    b = li()
    for j in range(N):
        b[j] -= 1
    ban.add(tuple(b))

score = sum(max(a) for a in slot)
b = [len(a)-1 for a in slot]
b = tuple(b)

#print()
que = [(-score,b,0)]
while que:
    score,b,idx = heappop(que)
    score *= -1
    #print(*b)
    if b not in ban:
        #print("ANS")
        b = [b[i]+1 for i in range(N)]
        exit(print(*b))
    
    for i in range(idx+1,N):
        tmp_b = [b[j] for j in range(N)]
        tmp_b[i] = b[i] - 1
        if tmp_b[i]!=-1:
            continue
        for j in range(i+1,N):
            tmp_b[j] = len(slot[j]) - 1
        
        next_score = sum(slot[i][tmp_b[i]] for i in range(N))
        heappush(que,(-next_score,tuple(tmp_b),i))
    
    tmp_b = [b[j] for j in range(N)]
    tmp_b[idx] -= 1
    if tmp_b[idx]!=-1:
        next_score = sum(slot[i][tmp_b[i]] for i in range(N))
        heappush(que,(-next_score,tuple(tmp_b),idx))

        


