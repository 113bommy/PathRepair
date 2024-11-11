import sys
input = sys.stdin.readline
class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)
 
    def sum(self, i):
        if i == 0:
            return 0
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
 
    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i
aas = "abcdefghijklmnopqrstuvwxyz"
N = int(input().strip())
S = list(input().strip())
Q = int(input().strip())
cbt = dict()
MX = 10**5 + 2
for c in aas:
    cbt[c] = Bit(MX)
    for i, a in enumerate(S):
        if a == c:
            cbt[c].add(i+1, 1)

for _ in range(Q):
    t, i, c = input().split()
    t = int(t)
    if t == 1:
        i = int(i)
        if S[i-1] != c:
            cbt[S[i-1]].add(i, -1)
            cbt[c].add(i, 1)
            S[i-1] = c
    else:
#        print(S)
        l, r = int(i), int(c)
#        print(l, r)
        s = 0
        for a in aas:
            bt = cbt[a]
#            print(a, bt.sum(r),bt.sum(l-1))
            s += (bt.sum(r)-bt.sum(l-1)>0)
        print(s)
