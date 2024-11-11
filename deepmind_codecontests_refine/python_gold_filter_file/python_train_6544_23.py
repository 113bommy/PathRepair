class BIT:
    def __init__(self, n):
        self.size = n
        self.tree = [0]*(n+1)
 
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

n = int(input())
a = [[int(x),i] for i,x in enumerate(input().split())]
a.sort()
bit = BIT(n)

ans = 0

for i in range(n):
    x,ind = a[i]
    s = bit.sum(ind)
    if s == 0:
        l = 0
    else:
        l = bit.bsearch(s)
    s2 = s+1
    if s2 > i:
        r = n
    else:
        r = bit.bsearch(s2)-1
    ans += x*(r-ind)*(ind-l+1)
    bit.add(ind,1)
    
print(ans)