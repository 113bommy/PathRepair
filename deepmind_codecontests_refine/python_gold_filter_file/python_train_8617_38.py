# Binary Indexed Tree (Fenwick Tree)
class BIT():
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 1)

    def add(self, i, value):
        i = i + 1
        while i <= self.n:
            self.bit[i] += value
            i += i & -i

    def _sum(self, i):
        s = 0
        while i > 0:
            s += self.bit[i]
            i -= i & -i
        return s

    def sum(self, l, r):
        return self._sum(r) - self._sum(l)

n = int(input())
S = input()
q = int(input())
Query = [input().split() for _ in range(q)]

bits = [BIT(n) for i in range(26)]
s = []
for i,c in enumerate(S):
    bits[ord(c) - ord("a")].add(i,1)
    s.append(c)

for q_type,fr,to in Query:
    if q_type == "1":
        i = int(fr)-1
        bits[ord(s[i]) - ord("a")].add(i,-1)
        bits[ord(to) - ord("a")].add(i,1)
        s[i] = to
    else:
        l,r = int(fr)-1,int(to)
        tmp = 0
        for i in range(26):
            if bits[i].sum(l,r):
                tmp += 1
        print(tmp)

