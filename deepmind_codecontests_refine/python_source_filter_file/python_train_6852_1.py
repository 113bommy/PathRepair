class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)
 
    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
 
    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i

n = int(input())
a = list(map(int, input().split()))
def med(x):
    cum = [0] * (n+1)
    for i in range(n):
        if a[i] >= x:
            cum[i+1] = cum[i] + 1
        else:
            cum[i+1] = cum[i] - 1
    m = min(cum)
    for i in range(n+1):
        cum[i] -= m - 1
    zb = Bit(max(cum))
    ret = 0
    for j in range(n+1):
        ret += zb.sum(cum[j])
        zb.add(cum[j], 1)
    return ret
b = sorted(a)
l = 0
r = n
while(r - l > 1):
    mid = (l + r) // 2
    if 2 * med(b[mid]) >= n * (n+1) // 2:
        l = mid
    else:
        r = mid
print(b[l])
