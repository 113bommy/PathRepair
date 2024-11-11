n = int(input())
h = list(map(int,input().split()))
h1 = [[h[i],i] for i in range(n)]
h1.sort()
a = list(map(int,input().split()))
dp = [0]*n
class Bit:
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
    def max(self, i):
        # [0, i) の要素の最大値を返す
        s = 0
        i += 1
        while i>0:
            s = max(s,self.tree[i])
            i -= i & -i
        return s
 
    def add(self, i, x):
        i += 1
        while i <= self.size:
            self.tree[i] = max(x,self.tree[i])
            i += i & -i
bit = Bit(2*n+1)

for i in range(n):
    s = h1[i][1]
    x = a[s]+bit.max(s-1)
    dp[s] = x
    bit.add(s,x)
    
print(max(dp))