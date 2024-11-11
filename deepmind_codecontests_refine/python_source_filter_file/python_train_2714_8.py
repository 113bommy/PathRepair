import sys
#stdin = sys.stdin
 
sys.setrecursionlimit(10**5) 
 
def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

class SegmentTree:
    def __init__(self, func, arr, default):
        self.func = func
        self.arr = arr
        self.default = default
        
        self.arrlen = len(self.arr)
        self.bitlen = (len(self.arr)-1).bit_length() + 1
        self.bottomlen = pow(2, self.bitlen-1)
        self.bottomst = pow(2, self.bitlen-1) - 1
        
        self.segtree = [self.default] * (2*self.bottomlen - 1)
        self.segtree[self.bottomst:self.bottomst+self.arrlen] = self.arr
        
        for idx in range(self.bottomst-1, -1, -1):
            self.segtree[idx] = self.func(self.segtree[2*idx+1],
                                          self.segtree[2*idx+2])
    
    # idx番目の値をxに変更(0-indexed)
    def update(self, idx:int, x:int):
        idx += self.bottomst
        self.segtree[idx] = x
        while idx > 0:
            idx = (idx-1)//2
            self.segtree[idx] = self.func(self.segtree[2*idx+1],
                                          self.segtree[2*idx+2])
        
    # [a,b) の値を取得(0-indexed)
    def query(self, a:int, b:int, idx:int, l:int, r:int):
        if r <= a or b <= l:
            return self.default
        
        elif a <= l and r <= b:
            return self.segtree[idx]
        
        else:
            return self.func(self.query(a,b, 2*idx+1, l, (l+r)//2),
                             self.query(a,b, 2*idx+2, (l+r)//2, r))

    # リセット
    def reset(self):
        self.segtree = [self.default] * (2*self.bottomlen - 1)
        self.segtree[self.bottomst:self.bottomst+self.arrlen] = self.arr
        
        for idx in range(self.bottomst-1, -1, -1):
            self.segtree[idx] = self.func(self.segtree[2*idx+1],
                                          self.segtree[2*idx+2])
            

n,q = li()
default = pow(2,31)-1
arr = [default]*n
segtree = SegmentTree(min, arr, default)
nbit = pow(2, (n-1).bit_length())

for _ in range(q):
    command, a, b = li()
    
    if command == 0:
        segtree.update(a,b)
    
    elif command == 1:
        print(segtree.query(a,b+1,0,0,nbit))
        

