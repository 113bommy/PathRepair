class BIT:
    '''
    0-indexed
    '''
    def __init__(self, N):
        self.size = N
        self.tree = [0] * (N + 1)
        self.depth = n.bit_length()

    def _bitsum(self, i):
        ret = 0
        while i:
            ret += self.tree[i]
            i ^= i & -i
        return ret

    def bitsum(self, l, r=None): # [l, r)
        if r is None:
            return self._bitsum(l)
        else:
            return self._bitsum(r) - self._bitsum(l)

    def bitadd(self, i, x):
        i += 1
        while i <= self.size:
            self.tree[i] += x
            i += i & -i
        return

n = int(input())
m = n * (n + 1) // 4
a = list(map(int, input().split()))
d = dict()
_a = sorted(set(a + [0]))
for i, x in enumerate(_a):
  d[x] = i
a = [d[x] for x in a]


def check(X):
  b = [0] + [(y>=X)*2 - 1 for y in a]
  for i in range(n):
    b[i+1] += b[i]
  c = min(b)
  b = [x-c for x in b] 
  bit = BIT(max(b) + 2)
  ans = 0
  for x in b:
    ans += bit.bitsum(x + 1)
    bit.bitadd(x, 1)
  return ans >= m

t = [len(_a), 0]
while t[0] - t[1] > 1:
  mid = (t[0] + t[1]) // 2
  t[check(mid)] = mid
print(_a[t[1]])
