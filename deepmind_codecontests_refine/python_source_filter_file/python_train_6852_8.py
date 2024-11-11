class BIT:
    def __init__(self, n):
        self.N = n
        self.n = 1<<n.bit_length()
        self.data = [0] * (self.n + 1)
        
    def sum(self, i):
        s = 0
        while i > 0:
            s += self.data[i]
            i -= i & -i
        return s

    def add(self, i, x):
        while i <= self.n:
            self.data[i] += x
            i += i & -i
N = int(input())
A = list(map(int, input().split()))
N0 = N*(N+1)//2
def C(x):
    B = BIT(N*2+1)
    s = [0]*(N+1)
    for i in range(N):
        a = A[i]
        s[i] = 1 if x<a else -1
        s[i]+=s[i-1]
    res = 0
    for i in range(-1, N):
        res+=B.sum(s[i]+N+1)
        B.add(s[i]+N+1, 1)
    return res<=N0//2
ok = max(A)
ng = min(A)-1
while abs(ok-ng)>1:
    mid = (ok+ng)//2
    if C(mid):#midが条件を満たすか
        ok = mid
    else:
        ng = mid
print(ok)

    

    