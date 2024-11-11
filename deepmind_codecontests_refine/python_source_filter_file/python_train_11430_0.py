import sys
from itertools import permutations
readline = sys.stdin.readline

from itertools import accumulate
from collections import Counter
from bisect import bisect as br, bisect_left as bl
class PMS:
    #1-indexed
    def __init__(self, A, B, issum = False):
        #Aに初期状態の要素をすべて入れる,Bは値域のリスト
        self.X, self.comp = self.compress(B)
        self.size = len(self.X)
        self.tree = [0] * (self.size + 1)
        self.p = 2**(self.size.bit_length() - 1)
        self.dep = self.size.bit_length()
        
        CA = Counter(A)
        S = [0] + list(accumulate([CA[self.X[i]] for i in range(self.size)]))
        for i in range(1, 1+self.size):
            self.tree[i] = S[i] - S[i - (i&-i)]
        if issum:
            self.sumtree = [0] * (self.size + 1)
            Ssum = [0] + list(accumulate([CA[self.X[i]]*self.X[i] for i in range(self.size)]))
            for i in range(1, 1+self.size):
                self.sumtree[i] = Ssum[i] - Ssum[i - (i&-i)]
    
    def compress(self, L):
        #座圧
        L2 = list(set(L))
        L2.sort()
        C = {v : k for k, v in enumerate(L2, 1)}
        # 1-indexed
        return L2, C
    
    def leng(self):
        #今入っている個数を取得
        return self.count(self.X[-1])
    
    def count(self, v):
        #v(Bの元)以下の個数を取得
        i = self.comp[v]
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
    
    def less(self, v):
        #v(Bの元である必要はない)未満の個数を取得
        i = bl(self.X, v)
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
    
    def leq(self, v):
        #v(Bの元である必要はない)以下の個数を取得
        i = br(self.X, v)
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
 
    def add(self, v, x):
        #vをx個入れる,負のxで取り出す,iの個数以上取り出すとエラーを出さずにバグる
        i = self.comp[v]
        while i <= self.size:
            self.tree[i] += x
            i += i & -i

    def get(self, i):
        # i番目の値を取得
        if i <= 0:
            return -1
        s = 0
        k = self.p
        for _ in range(self.dep):
            if s + k <= self.size and self.tree[s+k] < i:
                s += k
                i -= self.tree[s]
            k //= 2
        return self.X[s]
    
    def gets(self, v):
        #累積和がv以下となる最大のindexを返す
        v1 = v
        s = 0
        k = self.p
        for _ in range(self.dep):
            if s + k <= self.size and self.sumtree[s+k] < v:
                s += k
                v -= self.sumtree[s]
            k //= 2
        if s == self.size:
            return self.leng()
        return self.count(self.X[s]) + (v1 - self.countsum(self.X[s]))//self.X[s]
    
    def addsum(self, i, x):
        #sumを扱いたいときにaddの代わりに使う
        self.add(i, x)
        x *= i
        i = self.comp[i]
        while i <= self.size:
            self.sumtree[i] += x
            i += i & -i
    
    def countsum(self, v):
        #v(Bの元)以linema下のsumを取得
        i = self.comp[v]
        s = 0
        while i > 0:
            s += self.sumtree[i]
            i -= i & -i
        return s
    
    def getsum(self, i):
        #i番目までのsumを取得
        x = self.get(i)
        return self.countsum(x) - x*(self.count(x) - i)


N = int(readline())

A = list(map(int, readline().split()))
if N <= 8:
    ans = True
    for k in permutations(range(1, N+1)):
        for i in range(N-1):
            if k[i+1] == A[k[i]-1]:
                break
        else:
            break
    else:
        ans = False
    if not ans:
        print(-1)
    else:
        print(*k)
else:
    dim = [0]*(N+1)
    for i in range(N):
        a = A[i]
        dim[a] += 1
    T = PMS(list(range(2, N+1)), list(range(2, N+1)))
    L = [1]
    for i in range(N-7):
        k = T.get(1)
        if A[L[-1]-1] == k:
            k = T.get(2)
        L.append(k)
        T.add(k, -1)
    rem = [T.get(i) for i in range(1, 7)]
    for k in permutations(rem):
        if A[L[-1]-1] == k[0]:
            continue
        for i in range(5):
            if k[i+1] == A[k[i]-1]:
                break
        else:
            ans = L + list(k) 
            break
    else:
        L = L + list(k)
        ok = 0
        ng = N-5
        while abs(ok-ng) > 1:
            med = (ok+ng)//2
            C = Counter()
            for l in L[med:]:
                C[A[l-1]] += 1
            k, v = C.most_common()[0]
            if v == N-med-1 and k in L[med:]:
                ng = med
            else:
                ok = med
        C = Counter()
        for l in L[ng:]:
            C[A[l-1]] += 1
        k, _ = C.most_common()[0]
        L = L[:ng] + [k]
        
        
        
        S = set(range(1, N+1)) 
        for l in L:
            S.remove(l)
        S = list(S)
        T = PMS(S, S)
        LS = len(S)
        for _ in range(LS):
            k = T.get(1)
            if A[L[-1]-1] == k:
                k = T.get(2)
            L.append(k)
            T.add(k, -1)
            
        ans = L
    print(*ans)
