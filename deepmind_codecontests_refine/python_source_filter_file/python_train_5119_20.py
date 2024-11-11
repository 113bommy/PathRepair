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
    
    def count(self, i):
        #i(Bの元)以下の個数を取得
        i = self.comp[i]
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
 
    def add(self, i, x):
        #iをx個入れる,負のxで取り出す,iの個数以上取り出すとエラーを出さずにバグる
        i = self.comp[i]
        while i <= self.size:
            self.tree[i] += x
            i += i & -i

    def get(self, v):
        # v番目の値を取得
        if v <= 0:
            return -1
        s = 0
        k = self.p
        for _ in range(self.dep):
            if s + k <= self.size and self.tree[s+k] < v:
                s += k
                v -= self.tree[s]
            k //= 2
        return self.X[s]
    
    def gets(self, v):
        v1 = v
        if v <= 0:
            return -1
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
        #sumを扱いたいときにaddと併用
        self.add(i, x)
        x *= i
        i = self.comp[i]
        while i <= self.size:
            self.sumtree[i] += x
            i += i & -i
    
    def countsum(self, i):
        #i(Bの元)以下のsumを取得
        i = self.comp[i]
        s = 0
        while i > 0:
            s += self.sumtree[i]
            i -= i & -i
        return s
    
    def getsum(self, v):
        #v番目までのsumを取得
        x = self.get(v)
        return self.countsum(x) - x*(self.count(x) - v)


N, M = map(int, input().split())
T = list(map(int, input().split()))

S = PMS([T[0]], T, True)
print(0)
for i in range(1, N):
    print(i - S.gets(M - T[i]))
    S.addsum(T[i], 1)
