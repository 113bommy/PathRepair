class BIT:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n+10)
    def add(self,x,w):
        while x <= self.n:
            self.bit[x] += w
            x += (x&-x)
            
    def sum(self,x):
        cnt = 0
        while x > 0:
            cnt += self.bit[x]
            x -= (x&-x)
        return cnt

    def psum(self,a,b):
        return self.sum(b-1)-self.sum(a-1)

    def bisect(self, w):
        # 値がw以上となる最小のindex
        x = 0
        k = 1
        while k < self.n:
            k *= 2            
        while k > 0:
            # x+kの値がwより小さければ、treeの右側に移動
            if x+k<=self.n and self.bit[x+k] < w:
                w -= self.bit[x+k]
                x += k            
            k //= 2
        return x + 1
    
n = int(input())
ps = list(map(int, input().split()))

# 1-indexedにする
inds = [0]*(n+1)
for i, p in enumerate(ps):
    inds[p] = i+1
bit = BIT(n)
cnt = 0
# 大きい順に
for p in range(n,0,-1):
    ind = inds[p]
    nl = bit.sum(ind)   # 自分より左にあるやつの個数
    nr = (n-p) - nl     # 自分より左にあるやつの個数    
    bit.add(ind, 1)     # bitを1で埋めていく
    # 自分を含んで左右のインデックスを見る(端注意)
    ixl2 = bit.bisect(nl-1) if nl >= 2 else 0
    ixl1 = bit.bisect(nl)   if nl >= 1 else 0
    ixr1 = bit.bisect(nl+2) if nr >= 1 else n+1
    ixr2 = bit.bisect(nl+3) if nr >= 2 else n+1
    tmp = 0
    tmp += (ixl1-ixl2)*(ixr1-ind) #左側から1個取る
    tmp += (ixr2-ixr1)*(ind-ixl1) #右側から1個取る
    cnt += p*tmp    
    # print("p",p,nl,nr,"ind",ixl2,ixl1,ind,ixr1,ixr2,tmp,cnt)
print(cnt)