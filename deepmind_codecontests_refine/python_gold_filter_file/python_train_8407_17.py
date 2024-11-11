class BIT:
    def __init__(self, n):
        self.size = n
        self.tree = [0]*(n+1)
    
    def make(self, list):
        self.tree[1:] = list.copy()
        for i in range(self.size+1):
            j = i + (i & (-i))
            if j < self.size+1:
                self.tree[j] += self.tree[i]
 
    def sum(self, i):
        # [0, i) の要素の総和を返す
        s = 0
        while i>0:
            s += self.tree[i]
            i -= i & -i
        return s
    # 0 index を 1 index に変更  転倒数を求めるなら1を足していく
    def add(self, i, x):
        i += 1
        while i <= self.size:
            self.tree[i] += x
            i += i & -i

    # 総和がx以上になる位置のindex をbinary search
    def bsearch(self,x):
        le = 0
        ri = 1<<(self.size.bit_length()-1)
        while ri > 0:
            if le+ri <= self.size and self.tree[le+ri]<x:
                x -= self.tree[le+ri]
                le += ri
            ri >>= 1
        return le+1

n,q = map(int,input().split())
a = list(map(int,input().split()))
bit = BIT(n)
bit.make(a)
for i in range(q):
    t,l,r = map(int,input().split())
    if t == 0:
        bit.add(l,r)
    else:
        print(bit.sum(r)-bit.sum(l))