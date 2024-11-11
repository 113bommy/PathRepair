#単体変更, 区間取得

class RMQ:
    #INF = int(1e18)
    INF = int((1<<31)-1)
    n = 0
    n_ = 0
    val = []
    def __init__(self, n_):
        n = 1
        while n < n_:
            n = n * 2
        self.n = n
        self.n_ = n_
        self.val = [self.INF] * (2 * n - 1)

    @staticmethod
    def merge(a, b):
        return min(a, b)
        
    def update(self,k, x):
        k = k + self.n - 1
        self.val[k] = x
        while k:
            k = k//2
            self.val[k] = self.merge(self.val[k*2+1], self.val[k*2+2])

    def dfs(self, a, b, k, l, r):
        if r <= a or b <= l:
            return self.INF
        if a <= l and r <= b:
            return self.val[k]
        vl = self.dfs(a, b, k * 2 + 1, l, (l+r)//2)
        vr = self.dfs(a, b, k * 2 + 2, (l+r)//2, r)
        return self.merge(vl, vr)
    

    def query(self, a, b):
        return self.dfs(a, b, 0, 0, self.n)

    
n, q = list(map(int, input().split()))
rmq = RMQ(n)

while q:
    q = q - 1
    com, x, y = list(map(int, input().split()))
    if com == 0:
        rmq.update(x, y)
    else:
        print (rmq.query(x, y + 1))

